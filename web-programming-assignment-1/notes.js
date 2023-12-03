const fs = require('fs');

const saveNote = (note) => {
  const notes = loadNotes();
  const duplicateNote = notes.find(
    (existingNote) => existingNote.id === note.id
  );

  if (!duplicateNote) {
    notes.push(note);
    fs.writeFileSync('notes.json', JSON.stringify(notes));
    console.log('Note added successfully!');
  } else {
    console.log('Error: Note with the given ID already exists.');
  }
};

const loadNotes = () => {
  try {
    const dataBuffer = fs.readFileSync('notes.json');
    const dataJSON = dataBuffer.toString();
    return JSON.parse(dataJSON);
  } catch (error) {
    return [];
  }
};

const listNotes = () => {
  const notes = loadNotes();
  console.log('Your Notes:');
  notes.forEach((note) => {
    console.log(`Name: ${note.name}, ID: ${note.id}`);
  });
};

const getNote = (id) => {
  const notes = loadNotes();
  const note = notes.find((note) => note.id === id);

  if (!note) return console.log(`Error: Note with ID ${id} not found.`);

  console.log(`Name: ${note.name}, ID: ${note.id}`);
};

const deleteNote = (id) => {
  let notes = loadNotes();
  const filteredNotes = notes.filter((note) => note.id !== id);

  if (filteredNotes.length < notes.length) {
    fs.writeFileSync('notes.json', JSON.stringify(filteredNotes));
    console.log(`Note with ID ${id} deleted successfully!`);
  } else {
    console.log(`Error: Note with ID ${id} not found.`);
  }
};

module.exports = {
  saveNote,
  loadNotes,
  listNotes,
  getNote,
  deleteNote,
};
