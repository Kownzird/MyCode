#! /bin/bash

# this check grade shell

grade=$1

if [ $grade -gt 90 ];then
    echo "A"
elif [ $grade -gt 70 ];then
    echo "B"
elif [ $grade -gt 60 ];then
    echo "C"
else
    echo "FAIL"
fi
