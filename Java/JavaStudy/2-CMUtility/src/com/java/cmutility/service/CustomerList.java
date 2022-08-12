package com.java.cmutility.service;

import com.java.cmutility.bean.Customer;

/**
 * @description CustomerList为Customer对象的管理模块，
 *              内部用数组管理一组Customer对象，并提供相应的添加、修改、删除和遍历的方法，供CustomerView调用
 * @author zhe.gao
 * @version V1.0.01
 * @date 2022.08.11 14:00
 */
public class CustomerList {
    private Customer[] customers;
    private int total;

    public CustomerList(int totalCustomer){
        customers = new Customer[totalCustomer];
    }

    /**
     * @description 将参数customer添加到数组中的最后一个客户对象记录之后
     * @param customer 指定要添加的客户对象
     * @return 添加成功返回true，添加失败返回false
     */
    public boolean addCustomer(Customer customer){
        if(total < customers.length - 1){
            customers[total++] = customer;
            return true;
        }
        return false;
    }

    /**
     * @description 从数组中删除参数index所指定索引位置的客户对象记录
     * @param index  指定所删除对象在数组中的索引位置，从0开始
     * @return 删除成功返回true，删除失败返回false
     */
    public boolean deleteCustomer(int index){
        if(index < 0 || index >= customers.length){
            return false;
        }

        //将该位置后的客户信息往前迁移
        for(int i=index; i<customers.length-1; i++){
            customers[i] = customers[i+1];
        }

        //最后有元素的数组需要置空
        customers[--total] = null;
        return true;
    }

    /**
     * @description 用customer替换数组中由index指定的对象
     * @param index 指定所替换对象在数组中的位置
     * @param customer 指定替换的新客户对象
     * @return 替换成功返回true，替换失败返回false
     */
    public boolean replaceCustomer(int index, Customer customer){
        if(index < 0 || index >= customers.length){
            return false;
        }
        customers[index] = customer;
        return true;
    }

    /**
     * @description 返回数组中记录的所有客户对象
     * @return Customer[]数组中包含了所有的客户对象，该数组长度与对象个数相同
     */
    public Customer[] getAllCustomers(){
        Customer[] custs = new Customer[total];
        for(int i=0; i<total; i++){
            custs[i] = customers[i];
        }
        return custs;
    }

    /**
     * @description 返回参数index指定索引位置的客户对象
     * @param index 指定所有获取的客户在数组中的索引位置，从0开始
     * @return 封装了客户信息的customer对象
     */
    public Customer getCustomer(int index){
        if(index < 0 || index >= customers.length){
            return null;
        }
        return customers[index];
    }

    /**
     * @description 返回当前总客户数
     * @return 当前总客户数
     */
    public int getTotal(){
        return total;
    }
}
