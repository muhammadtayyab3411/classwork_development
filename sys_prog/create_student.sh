#!/bin/bash

# Get user input for creating a new student
echo "Enter student name:"
read name

echo "Enter student age:"
read age

echo "Enter student grade:"
read grade

# Create a new student
echo "Calling POST /students"
curl -X POST -H "Content-Type: application/json" -d "{\"name\": \"$name\", \"age\": $age, \"grade\": \"$grade\"}" http://localhost:3000/students