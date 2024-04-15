// Import required modules
const express = require('express');
const bodyParser = require('body-parser');

// Create an instance of Express
const app = express();

// Middleware to parse JSON bodies
app.use(bodyParser.json());

// Sample data - Initial list of students
let students = [
  { id: 1, name: 'John Doe', age: 20, grade: 'A' },
  { id: 2, name: 'Jane Smith', age: 22, grade: 'B' },
];

// GET all students
app.get('/students', (req, res) => {
  res.json(students);
});

// GET a single student by ID
app.get('/students/:id', (req, res) => {
  const id = parseInt(req.params.id);
  const student = students.find((student) => student.id === id);
  if (!student) {
    res.status(404).send('Student not found');
  } else {
    res.json(student);
  }
});

// POST create a new student
app.post('/students', (req, res) => {
  const { name, age, grade } = req.body;
  const id = students.length + 1;
  const newStudent = { id, name, age, grade };
  students.push(newStudent);
  res.status(201).json(newStudent);
});

// PUT update an existing student
app.put('/students/:id', (req, res) => {
  const id = parseInt(req.params.id);
  const { name, age } = req.body;
  const index = students.findIndex((student) => student.id === id);
  if (index === -1) {
    res.status(404).send('Student not found');
  } else {
    students[index] = { id, name, age };
    res.json(students[index]);
  }
});

// DELETE a student by ID
app.delete('/students/:id', (req, res) => {
  const id = parseInt(req.params.id);
  const index = students.findIndex((student) => student.id === id);
  if (index === -1) {
    res.status(404).send('Student not found');
  } else {
    students.splice(index, 1);
    res.sendStatus(204);
  }
});

// Start the server
const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
  console.log(`Server is running on port ${PORT}`);
});
