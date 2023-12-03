const { saveNote, getNote, listNotes, deleteNote } = require('./notes');

// Get command-line arguments
const command = process.argv[2];

// Handle different commands
if (command === 'add') {
  const name = process.argv[3];
  const id = process.argv[4];
  saveNote({ name, id });
} else if (command === 'list') {
  listNotes();
} else if (command === 'get') {
  const idToGet = process.argv[3];
  getNote(idToGet);
} else if (command === 'delete') {
  const idToDelete = process.argv[3];
  deleteNote(idToDelete);
} else {
  console.log('Command not recognized. Available commands: add, list');
}
