#!/bin/bash
read -p "Enter a number: " number
if [ `expr $number % 2` == 0 ]
then
  echo "Number is even."
else
  echo "Number is odd."
fi

