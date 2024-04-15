#!/bin/bash

# Get user input for updating an existing student
echo "Enter student ID to update:"
read student_id

echo "Enter updated name (press enter to skip):"
read name

echo "Enter updated age (press enter to skip):"
read age

echo "Enter updated grade (press enter to skip):"
read grade

# Prepare JSON payload for updating student
payload="{"
if [ -n "$name" ]; then
    payload+="\"name\": \"$name\","
fi
if [ -n "$age" ]; then
    payload+="\"age\": $age,"
fi
if [ -n "$grade" ]; then
    payload+="\"grade\": \"$grade\","
fi
# Remove trailing comma if present
payload=$(echo "$payload" | sed 's/,$//')
payload+="}"

# Update an existing student
echo "Calling PUT /students/:id"
curl -X PUT -H "Content-Type: application/json" -d "$payload" http://localhost:3000/students/$student_id  # Replace 1 with the actual student ID