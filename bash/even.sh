#!/bin/bash
read -p "Enter a number: " number
if [ $((number%2)) -eq 0 ]
then
  echo "Number is even."
else
  echo "Number is odd."
fi
