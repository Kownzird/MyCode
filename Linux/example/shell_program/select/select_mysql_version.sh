#! /bin/bash

# $PS3 用于定义 select 命令的提示符
PS3="Select a number: "
while true;do
    select mysql_version in 5.1 5.6 quit; do
        case $mysql_version in
        5.1)
            echo "mysql 5.1"
            break
            ;;
        5.6)
            echo "mysql 5.6"
            break
            ;;
        quit)
            exit 0
            ;;
        *)
            echo "Input error, Please enter again!"
            break
            ;;
        esac
    done
done