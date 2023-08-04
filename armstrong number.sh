#!/bin/bash
echo "21BCE5126"
echo "Enter a number:"
read n
# Counting the number of digits in the input number
digits=${#n}
sum=0
for (( i=0; i<$digits; i++ ))
do
    # Extracting each digit from the input number
    digit=${n:i:1}
    # Calculating the cube of the extracted digit
    cube=$((digit * digit * digit))
    # Adding the cube to the sum variable
    sum=$((sum + cube))
done
# Checking if the sum is equal to the input number
if [ $sum -eq $n ]
then
    echo "$n is an Armstrong number"
else
    echo "$n is not an Armstrong number"
fi

