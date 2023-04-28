#! /bin/bash

# check hosts is on/Off

Network=$1

for Host in $(seq 1 254);
do
ping -c 1 $Network.$Host > /dev/null && result=0 || result=1

if [ $result -eq 0 ];then
    # [和 m 结合起来组成一个控制码
    # \033[32;1m 表示设置输出的颜色为绿色（32），并且加粗显示（1）
    # \033[0m 用于复位终端颜色属性，以免影响后续的命令输出
    echo -e "\033[32;1m$Network.$Host is up \033[0m"
    echo "$Network.$Host" >> ./tmp/up.txt
else
    # 31m：设置了输出文本的颜色属性，代表红色字体
    echo -e "\033[;31m$Network.$Host is down \033[0m"
    echo "$Network.$Host" >> ./tmp/down.txt
fi
done