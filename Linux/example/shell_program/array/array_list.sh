#! /bin/bash

IP=(10.2.24.1 10.2.24.2 10.2.24.3)
for ((i=0;i<${#IP[*]};i++));do
    echo ${IP[$i]}
done