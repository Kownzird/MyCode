#! /bin/bash

# 打印 1-100 数字

i=0
while ((i<=100))
do
    echo $i
    # i=`expr $i + 1`
    # ((i=i+1))
    i=$((i+1))
done