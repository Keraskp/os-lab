#!/bin/bash
a=0
b=1

read -p "Enter no. of terms : " num
for((i=0;i<num;i++))
{
echo -n "$a "
fn=$((a+b))
a=$b
b=$fn
}

echo ""
