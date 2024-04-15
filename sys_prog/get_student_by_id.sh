#!/bin/bash

# Get user input for student ID
echo "Enter student ID:"
read student_id

# Get a specific student by ID
echo "Calling GET /students/:id"
curl -X GET http://localhost:3000/students/$student_id