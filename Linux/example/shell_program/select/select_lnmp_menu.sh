#!/bin/bash


PS3="Please enter you select install menu:"
select i in http php mysql quit
do
case $i in
        http)
        echo -e "\033[31m Test Httpd \033[0m" 
        ;;
        php)
        echo  -e "\033[32m Test PHP\033[0m"
        ;;
        mysql)
        echo -e "\033[33m Test MySQL.\033[0m"
        ;;
        quit)
        echo -e "\033[32m The System exit.\033[0m"
        exit
esac
done