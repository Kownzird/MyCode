#!/bin/bash
func() {
    VAR=$((1+1))
    return $VAR
    echo "This is a function."
}

func2(){
    VAR=$((2+2))
    echo "This is a function2"
    return $VAR
}

func
echo $?

func2
echo $?