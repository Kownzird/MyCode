#include <linux/init.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/device.h>
#include <asm/uaccess.h>
#include <linux/slab.h>
#include "virtualio.h"


/* �����豸�ű��� */
static int virtualio_major = 0;
static int virtualio_minor = 0;


/* �豸�����豸���� */
static struct class* virtualio_class = NULL;
static struct virtualio_android_dev* virtualio_dev = NULL;

/* ��ͳ���豸�ļ��������� */
static int virtualio_open(struct inode* inode, struct file* filp)
{
    struct virtualio_android_dev* dev;
    dev = container_of(inode->i_cdev, struct virtualio_android_dev, dev);
    filp->private_data = dev;
    return 0;
}

static int virtualio_release(struct inode* inode, struct file* filp)
{
    return 0;
}

static ssize_t virtualio_read(struct file* filp, char __user *buf, u8 num)
{
    ssize_t err = 0;
    struct virtualio_android_dev* dev = filp->private_data;
    /* ͬ������ */
    if(down_interruptible(&(dev->sem)))
    {
        return -ERESTARTSYS;
    }

    if(num < 1 || num > 4)
    {
        goto out;
    }

    /* ���Ĵ�����ֵ���Ƶ��û��ṩ�Ļ����� */
    switch(num)
    {
        case 1:
            copy_to_user(buf, &(dev->reg2), 1);
            break;

        case 2:
            copy_to_user(buf+1, &(dev->reg2), 1);
            break;

        case 3:
            copy_to_user(buf+2, &(dev->reg3), 1);
            break;

        case 4:
            copy_to_user(buf+3, &(dev->reg4), 1);
            break;    

        default:
            err = -EFAULT;
            goto out;
            break;     
    }
    err = num;
    out:
        up(&(dev->sem));
        return err;
}

static ssize_t virtualio_write(struct file* filp, const char __user *buf, u8 num)
{
    struct virtualio_android_dev* dev = filp->private_data;
    ssize_t err = 0;

    /* ͬ������ */
    if(down_interruptible(&(dev->sem)))
    {
        return -ERESTARTSYS;
    }

    if(num < 1 || num > 4)
    {
        goto out;
    }

    /* ���û��ṩ�Ļ�������ֵд���豸�Ĵ���ȥ */
    switch(num)
    {
        case 1:
            copy_from_user(&(dev->reg1), buf+num-1, 1);
            break;

        case 2:
            copy_from_user(&(dev->reg2), buf+num-1, 1);
            break;    

        case 3:
            copy_from_user(&(dev->reg3), buf+num-1, 1);
            break;

        case 4:
            copy_from_user(&(dev->reg4), buf+num-1, 1);
            break;    

        default:
            err = -EFAULT;
            goto out;      
            break;     
    }
    err = num;
    out:
        up(&(dev->sem));
        return err;
}

/* �豸�ļ������������� */
static struct file_operations virtualio_fops = {
    .owner = THIS_MODULE,
    .open = virtualio_open,
    .release = virtualio_release,
    .read = virtualio_read,
    .write = virtualio_write,
};

/* ���Ĵ�����ֵ��������buf�У��ڲ�ʹ�� */
static ssize_t __virtualio_get_reg(struct virtualio_android_dev* dev, char* buf)
{
    u8 reg1_val = 0;
    u8 reg2_val = 0;
    u8 reg3_val = 0;
    u8 reg4_val = 0;

    /* ͬ������ */
    if(down_interruptible(&(dev->sem)))
    {
        return -ERESTARTSYS;
    }

    reg1_val = dev->reg1;
    reg2_val = dev->reg2;
    reg3_val = dev->reg3;
    reg4_val = dev->reg4;


    up(&(dev->sem));

    return snprintf(buf, PAGE_SIZE, "%d, %d, %d, %d\n", reg1_val, reg2_val, reg3_val, reg4_val);
}

/* д������buf��ֵ���Ĵ����У��ڲ�ʹ�� */
static ssize_t __virtualio_set_reg(struct virtualio_android_dev* dev, const char buf[])
{
    u8 reg1_val = 0;
    u8 reg2_val = 0;
    u8 reg3_val = 0;
    u8 reg4_val = 0;

    /* ���ַ���ת�������� */
    reg1_val = buf[0];
    reg2_val = buf[1];
    reg3_val = buf[2];
    reg4_val = buf[3];

    printk(KERN_ALERT"set virtualio reg value:%d, %d, %d, %d.\n",reg1_val, reg2_val, reg3_val, reg4_val);

    /* ͬ������ */
    if(down_interruptible(&(dev->sem)))
    {
        return -ERESTARTSYS;
    }

    dev->reg1 = reg1_val;
    dev->reg2 = reg2_val;
    dev->reg3 = reg3_val;
    dev->reg4 = reg4_val;

    up(&(dev->sem));

    return 4;

}


/* �����豸���Է��� */
// static ssize_t virtualio_reg_show(struct device* dev, struct device_attribute* attr, char* buf)
// {
//     struct virtualio_android_dev* hdev = (struct virtualio_android_dev*)dev_get_drvdata(dev);
//     return __virtualio_get_reg(hdev, buf);
// }

// static ssize_t virtualio_reg_store(struct device* dev, struct device_attribute* attr, const char* buf)
// {
//     struct virtualio_android_dev* hdev = (struct virtualio_android_dev*)dev_get_drvdata(dev);
//     return __virtualio_set_reg(hdev, buf);
// }

/* �����豸���� */
// static DEVICE_ATTR(VIRTUALIO_DEVICE_CLASS_NAME, S_IRUGO | S_IWUSR, virtualio_reg_show, virtualio_reg_store);


static ssize_t virtualio_proc_read(char* page, char** start, off_t off, int count, int* eof, void* data)
{
    return __virtualio_get_reg(virtualio_dev, page);
}

static ssize_t virtualio_proc_write(struct file* filp, const char __user *buff, unsigned long len, void* data)
{
    int err = 0;
    char* page = NULL;

    if(len > PAGE_SIZE)
    {
        printk(KERN_ALERT "The buff is too large: &lu,\n", len);
        return -EFAULT;
    }

    page = (char*) __get_free_page(GFP_KERNEL);
    if(!page)
    {
        printk(KERN_ALERT "Failed to alloc page.\n");
        err = -ENOMEM;
    }

    /* �Ȱ��û��ṩ�Ļ�����ֵ���Ƶ��ں˻������� */
    if(copy_from_user(page, buff, len))
    {
        printk(KERN_ALERT "Failed to copy buff from user\n");
        err = -EFAULT;
        goto out;
    }

    err = __virtualio_set_reg(virtualio_dev, page);

    out:
        free_page((unsigned long)page);
        return err;
}

static const struct file_operations virtualio_proc_fops = 
{
    .owner = THIS_MODULE,
    .read = virtualio_proc_read,
    .write = virtualio_proc_write,
};

static void virtualio_create_proc(void)
{
    struct proc_dir_entry* entry = NULL;
    entry = proc_create(VIRTUALIO_DEVICE_PROC_NAME, 0777, NULL, &virtualio_proc_fops);
    if(entry = NULL)
    {
        printk(KERN_ALERT"Create virtualio proc failed!\n");
    }
}

static void virtualio_remove_proc(void)
{
    remove_proc_entry(VIRTUALIO_DEVICE_PROC_NAME, NULL);
}

static int __virtualio_setup_dev(struct virtualio_android_dev* dev)
{
    int err;
    dev_t devno = MKDEV(virtualio_major, virtualio_minor);
    memset(dev, 0, sizeof(struct virtualio_android_dev));
    cdev_init(&(dev->dev), &virtualio_fops);
    dev->dev.owner = THIS_MODULE;
    dev->dev.ops = &virtualio_fops;

    /* ע���ַ��豸 */
    err = cdev_add(&(dev->dev), devno, 1);
    if(err)
    {
        return err;
    }

    /* ��ʼ���ź����ͼĴ�����ֵ */
    //init_MUTEX(&(dev_sem)); �°汾�ں��б��ϳ�ʹ��
    sema_init(&(dev->sem), 1);
    dev->reg1 = 0;
    dev->reg2 = 0;
    dev->reg3 = 0;
    dev->reg4 = 0;

    return 0;

}

/* ģ����ط��� */
static int __init virtualio_init(void)
{
    int err = -1;
    dev_t dev = 0;
    struct device* temp = NULL;

    printk(KERN_ALERT"Initializing virtualio device.\n");

    /* ��̬�������豸�ʹ��豸 */
    err = alloc_chrdev_region(&dev, 0, 1, VIRTUALIO_DEVICE_NODE_NAME);
    if(err < 0)
    {
        printk(KERN_ALERT"Failed to alloc char dev region.\n");
        goto fail;
    }

    virtualio_major = MAJOR(dev);
    virtualio_minor = MINOR(dev);

    /* ����virtualio_dev�豸�ṹ������ڴ� */
    virtualio_dev = kmalloc(sizeof(struct virtualio_android_dev), GFP_KERNEL);
    if(!virtualio_dev)
    {
        err = -ENOMEM;
        printk(KERN_ALERT"Failed to alloc virtualio_dev.\n");
        goto unregister;
    }

    /* ��ʼ���豸 */
    err = __virtualio_setup_dev(virtualio_dev);
    if(err)
    {
        printk(KERN_ALERT"Failed to alloc virtualio_dev.\n");
        goto cleanup;
    }

    /* ��sys/class/Ŀ¼�´����豸���Ŀ¼virtualio */
    virtualio_class = class_create(THIS_MODULE, VIRTUALIO_DEVICE_CLASS_NAME);
    if(IS_ERR(virtualio_class))
    {
        err = PTR_ERR(virtualio_class);
        printk(KERN_ALERT"Failed to create virtualio device.\n");
        goto destroy_cdev;
    }

    /* ��/devĿ¼��sys/class/virtualioĿ¼�·ֱ𴴽��豸�ļ�virtualio */
    temp = device_create(virtualio_class, NULL, dev, "%s", VIRTUALIO_DEVICE_FILE_NAME);
    if(IS_ERR(temp))
    {
        err = PTR_ERR(temp);
        printk(KERN_ALERT"Failed to create virtualio device.\n");
        goto destroy_class;
    }

    dev_set_drvdata(temp, virtualio_dev);

    /* ����/proc/virtualio �ļ� */
    virtualio_create_proc();
    printk(KERN_ALERT"Succeded to initialize virtualio device.\n");
    return 0;

    destroy_device:
        device_destroy(virtualio_class, dev);

    destroy_class:
        class_destroy(virtualio_class);

    destroy_cdev:
        cdev_del(&(virtualio_dev->dev));        

    cleanup:
        kfree(virtualio_dev);

    unregister:
        unregister_chrdev_region(MKDEV(virtualio_major, virtualio_minor), 1);

    fail:
        return err;            
}

/* ģ��ж�ط��� */
static void __exit virtualio_exit(void)
{
    dev_t devno = MKDEV(virtualio_major, virtualio_minor);
    printk(KERN_ALERT"Destroy virtualio device.\n");
    
    /* ɾ��/proc/virtualio�ļ� */
    virtualio_remove_proc();

    /* �����豸�����豸 */
    if(virtualio_class)
    {
        device_destroy(virtualio_class, MKDEV(virtualio_major, virtualio_minor));
        class_destroy(virtualio_class);
    }

    /* ɾ���ַ��豸���ͷ��豸�ڴ� */
    if(virtualio_dev)
    {
        cdev_del(&(virtualio_dev->dev));
        kfree(virtualio_dev);
    }

    /* �ͷ��豸�� */
    unregister_chrdev_region(MKDEV(virtualio_major, virtualio_minor), 1);
}

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("First Android Driver");

module_init(virtualio_init);
module_exit(virtualio_exit);
