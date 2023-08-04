#!/bin/sh
echo "Enter the number:"
read n
rem=$(( $n%2 ))
if [ $rem -eq 0 ]
then
echo "$n is an even number."
else 
echo "$n is a odd number."
fi
