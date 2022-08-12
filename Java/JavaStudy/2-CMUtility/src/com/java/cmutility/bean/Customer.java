package com.java.cmutility.bean;

/**
 * @description Customer为实体对象，用来封装客户信息
 * @author zhe.gao
 * @version V1.0.01
 * @date 2022.08.11 14:00
 */
public class Customer {
    private String name;    //客户姓名
    private char gender;    //性别
    private int age;        //年龄
    private String phone;   //电话
    private String email;   //邮箱

    public Customer(){

    }

    public Customer(String name, char gender, int age, String phone, String email){
        this.name = name;
        this.gender = gender;
        this.age = age;
        this.phone = phone;
        this.email = email;
    }

    public String getName(){
        return name;
    }

    public char getGender(){
        return gender;
    }

    public int getAge(){
        return age;
    }

    public String getPhone(){
        return phone;
    }

    public String getEmail(){
        return email;
    }
}