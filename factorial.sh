#!/bin/bash
echo "21BCE5126"
echo "Enter a number:"
read n
# Initializing the product variable with 1
product=1
# Loop through each number from 1 to n and multiply them together
for (( i=1; i<=$n; i++ ))
do
    # Multiplying the current number with the product variable
    product=$((product * i))
done
echo "Factorial of $n is: $product"

