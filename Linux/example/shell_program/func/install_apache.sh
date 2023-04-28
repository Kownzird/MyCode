#!/bin/bash
#auto install apache
#By author rivers 2021-09-27 
#Httpd define path variable
FILES=httpd-2.4.57.tar.bz2 
FILES_DIR=./httpd-2.4.57
URL=http://mirrors.cnnic.cn/apache/httpd/
# PREFIX=/usr/local/apache2/
function Apache_install ()
{
    #Install httpd web server 
    if [[ "$1" -eq "1" ]];then
            wget -c $URL/$FILES &&  tar -jxvf $FILES && cd $FILES_DIR &&./configure
            if [ $? -eq 0 ];then
                    make && make install
                    echo -e "\n\033[32m--------------------------------------------"
                    echo -e "\033[32mThe $FILES_DIR Server Install Success !\033[0m"
            else
                    echo -e "\033[32mThe $FILES_DIR Make or Make install ERROR"
                    exit 0
            fi
    fi
}
Apache_install 1
# 调用函数，传参为1