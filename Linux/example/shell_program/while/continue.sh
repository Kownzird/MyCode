#! /bin/bash

# 示例 2：举例子说明 continue 用法

N=0
while [ $N -lt 5 ];do
    let N++

    if [ $N -eq 3 ];then
        continue
    fi

    echo $N
done