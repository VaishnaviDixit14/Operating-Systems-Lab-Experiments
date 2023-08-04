#!/bin/bash

# Associative array to simulate the student structure
declare -A student

# Adding details for first student
student[name]="ABC"
student[regno]="101"
student[branch]="CSE"
student[sub1]=90
student[sub2]=80
student[sub3]=95

# Printing the details for first student
echo "Name: ${student[name]}"
echo "Register Number: ${student[regno]}"
echo "Branch: ${student[branch]}"
echo "Marks in Subject 1: ${student[sub1]}"
echo "Marks in Subject 2: ${student[sub2]}"
echo "Marks in Subject 3: ${student[sub3]}"
echo "-------------------------"

# Adding details for second student
student[name]="DEF"
student[regno]="102"
student[branch]="ECE"
student[sub1]=85
student[sub2]=70
student[sub3]=92

# Printing the details for second student
echo "Name: ${student[name]}"
echo "Register Number: ${student[regno]}"
echo "Branch: ${student[branch]}"
echo "Marks in Subject 1: ${student[sub1]}"
echo "Marks in Subject 2: ${student[sub2]}"
echo "Marks in Subject 3: ${student[sub3]}"
echo "-------------------------"

# Adding details for third student
student[name]="XYZ"
student[regno]="103"
student[branch]="MECH"
student[sub1]=75
student[sub2]=60
student[sub3]=80

# Printing the details for third student
echo "Name: ${student[name]}"
echo "Register Number: ${student[regno]}"
echo "Branch: ${student[branch]}"
echo "Marks in Subject 1: ${student[sub1]}"
echo "Marks in Subject 2: ${student[sub2]}"
echo "Marks in Subject 3: ${student[sub3]}"
echo "-------------------------"

