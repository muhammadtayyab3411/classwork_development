#!/bin/bash

# Get user input for student ID
echo "Enter student ID to delete:"
read student_id

# Delete a student by ID
echo "Calling DELETE /students/:id"
curl -X DELETE http://localhost:3000/students/$student_id