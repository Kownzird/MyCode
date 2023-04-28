#! /bin/bash

# this is check directory 

# if [ ! -d ./data/rivers -a ! -d ./tmp/rivers ];then
#     mkdir -p /data/rivers
# fi

if [ ! -d ./data/rivers ] && [ ! -d ./tmp/rivers ];then
    mkdir -p ./data/rivers
fi