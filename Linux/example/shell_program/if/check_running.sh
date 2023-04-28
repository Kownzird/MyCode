#! /bin/bash

# this is check crond

name=crond

num=$(ps aux|grep $name|grep -vc grep)

if [ $num -eq 1 ];then
    echo "crond is running"
else
    echo "crond is not running"
fi
