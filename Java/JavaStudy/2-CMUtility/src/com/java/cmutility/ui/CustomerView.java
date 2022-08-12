package com.java.cmutility.ui;

import com.java.cmutility.bean.Customer;
import com.java.cmutility.util.CMUtility;
import com.java.cmutility.service.CustomerList;

/**
 * @description CustomerView为主模块，负责菜单的显示和用户操作
 * @author zhe.gao
 * @version V1.0.01
 * @date 2022.08.12 13:53
 */
public class CustomerView {

    private CustomerList customerList = new CustomerList(10);

    public CustomerView(){
        Customer cust = new Customer("张三",'男',20,"123456789","zhangsan@qq.com");
        customerList.addCustomer(cust);
    }

    /**
     * @description 显示主菜单，响应客户输入，根据客户操作分别调用其他相应的成员方法，以完成客户信息处理
     */
    public void enterMainMenu(){
        boolean isFlag = true;
        while (isFlag){
            System.out.println("\n-----------------客户信息管理软件-----------------\n");
            System.out.println("                  1 添 加 客 户");
            System.out.println("                  2 修 改 客 户");
            System.out.println("                  3 删 除 客 户");
            System.out.println("                  4 客 户 列 表");
            System.out.println("                  5 退       出\n");
            System.out.print("                  请选择(1-5):");

            char menu = CMUtility.readMenuSelection();
            switch (menu){
                case '1':
                    addNewCustomer();
                    break;
                case '2':
                    modifyCustomer();
                    break;
                case '3':
                    deleteCustomer();
                    break;
                case '4':
                    listAllCustomers();
                    break;
                case '5':
                    System.out.print("确认退出(Y/N)?");
                    char isExit = CMUtility.readConfirmSelection();
                    if(isExit == 'Y'){
                        isFlag = false;
                    }else{
                        break;
                    }
            }
        }
    }

    /**
     * @description 添加用户操作
     */
    private void addNewCustomer(){
        System.out.println("--------------------添加客户---------------------");
        System.out.print("姓名：");
        String name = CMUtility.readString(10);

        System.out.print("性别：");
        char gender = CMUtility.readChar();

        System.out.print("年龄：");
        int age = CMUtility.readInt();

        System.out.print("电话：");
        String phone = CMUtility.readString(13);

        System.out.print("邮箱：");
        String email = CMUtility.readString(30);

        Customer customer = new Customer(name, gender, age, phone, email);
        customerList.addCustomer(customer);
    }

    /**
     * @description 修改客户操作
     */
    private void modifyCustomer(){
        System.out.println("------------------修改用户信息---------------------");
        int id;
        Customer cust;
        for(;;){
            System.out.println("请选择修改客户编号(-1退出):");
            id = CMUtility.readInt();
            if(id == -1){
                return;
            }
            //获取选择索引处的客户对象
            cust = customerList.getCustomer(id - 1);
            if(cust == null){
                System.out.println("无法找到指定客户信息");
            }else{
                break;
            }
        }

        System.out.print("姓名(" + cust.getName() + "):");
        String name = CMUtility.readString(10, cust.getName());

        System.out.print("性别(" + cust.getGender() + "):");
        char gender = CMUtility.readChar(cust.getGender());

        System.out.print("年龄(" + cust.getAge() + "):");
        int age = CMUtility.readInt(cust.getAge());

        System.out.print("电话(" + cust.getPhone() + "):");
        String phone = CMUtility.readString(13, cust.getPhone());

        System.out.print("邮箱(" + cust.getEmail() + "):");
        String email = CMUtility.readString(30, cust.getEmail());

        Customer newCust = new Customer(name, gender, age, phone, email);
        customerList.replaceCustomer(id - 1, newCust);
    }

    /**
     * @description 删除用户操作
     */
    private void deleteCustomer(){
        System.out.println("--------------------删除客户---------------------");
        int id;
        Customer cust;
        for(;;){
            System.out.print("请选择删除客户编号(-1退出):");
            id = CMUtility.readInt();
            if(id == -1){
                return;
            }

            cust = customerList.getCustomer(id - 1);
            if(cust == null){
                System.out.println("无法找到指定用户");
            }else{
                break;
            }
        }

        //找到指定用户，确认删除
        System.out.print("确认删除(Y/N)?");
        char isDelete = CMUtility.readConfirmSelection();
        if(isDelete == 'Y'){
            customerList.deleteCustomer(id - 1);
            System.out.println("--------------------删除完成---------------------");
        }else{
            System.out.println("--------------------删除失败---------------------");
        }
    }

    /**
     * @description 显示客户列表操作
     */
    private void listAllCustomers(){
        System.out.println("--------------------客户列表---------------------");
        if(customerList.getTotal() == 0){
            System.out.println("没有用户记录");
        }else{
            System.out.println("编号\t姓名\t\t性别\t年龄\t电话\t\t\t邮箱");
            Customer[] custs = customerList.getAllCustomers();
            for(int i=0; i<custs.length; i++){
                Customer cust = custs[i];
                System.out.println((i+1) + "\t" + cust.getName() + "\t\t" + cust.getGender() + "\t"
                 + cust.getAge() + "\t" + cust.getPhone() + "\t" + cust.getEmail());
            }
        }
        System.out.println("------------------客户列表完成---------------------");
    }

    /**
     * @description 创建CustomerView实例，并调用enterMainMenu()方法执行程序
     * @param args
     */
    public static void main(String[] args) {
        CustomerView view = new CustomerView();
        view.enterMainMenu();
    }
}
