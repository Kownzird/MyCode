#! /bin/bash

# 示例 1：在死循环中，满足条件终止循环

while true; do
    let N++
    if [ $N -eq 5 ];then
        break
    fi
    echo $N
done