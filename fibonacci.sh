#!/bin/bash
echo "21BCE5126"
echo "Enter a number:"
read n
a=0
b=1
echo -n "$a $b "
for ((i=3; i<=$n; i++))
do
    c=$((a + b))
    echo -n "$c "
    a=$b
    b=$c
done

echo ""

