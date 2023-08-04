#!/bin/bash
echo "21BCE5126"
arr=(10 20 30 40 50)
echo "Enter the element you want to search:"
read elem
for i in "${arr[@]}"
do
    if [ $i -eq $elem ]
    then
        echo "$elem is present in the array"
        exit 0
    fi
done
echo "$elem is not present in the array"

