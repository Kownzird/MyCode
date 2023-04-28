#ifndef _VIRTUALIO_ANDROID_H_
#define _VIRTUALIO_ANDROID_H_

#include <linux/cdev.h>
#include <linux/semaphore.h>

#define VIRTUALIO_DEVICE_NODE_NAME "virtualio"
#define VIRTUALIO_DEVICE_FILE_NAME "virtualio"
#define VIRTUALIO_DEVICE_PROC_NAME "virtualio"
#define VIRTUALIO_DEVICE_CLASS_NAME "virtualio"

struct virtualio_android_dev {
    char reg1;
    char reg2;
    char reg3;
    char reg4;
    struct semaphore sem;
    struct cdev dev;
};
#endif
