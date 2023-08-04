#!/bin/sh
echo "Read first number:"
read a
echo "Read second number:"
read b
sum=$(( $a+$b ))
echo "Sum is:$sum"
