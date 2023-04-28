#!/bin/bash
# This is echo color shell
# by author rivers 2021.09-23

# 字体颜色
echo "------------font color-----------"
for i in {31..37}; do
echo -e "\033[$i;40mHello world!\033[0m"
done

# 背景颜色
echo "-------background color----------"
for i in {41..47}; do
echo -e "\033[47;${i}mHello world!\033[0m"
done

# 显示方式
echo "----------show style-------------"
for i in {1..8}; do
echo -e "\033[$i;31;40mHello world!\033[0m"
done