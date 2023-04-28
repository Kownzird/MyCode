#! /bin/bash

i=1
sum=0

while ((i<=100));do
    # sum=`expr $i + $sum`
    sum=$(($i+$sum))
    ((i++))
done
echo $sum