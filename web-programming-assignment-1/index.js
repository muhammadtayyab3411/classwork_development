const { saveNote, getNote, listNotes, deleteNote } = require('./notes');

// Get command-line arguments
const command = process.argv[2];

// Switch based on the command
switch (command) {
  case 'add':
    const name = process.argv[3];
    const id = process.argv[4];
    saveNote({ name, id });
    break;

  case 'list':
    listNotes();
    break;

  case 'get':
    const idToGet = process.argv[3];
    getNote(idToGet);
    break;

  case 'delete':
    const idToDelete = process.argv[3];
    deleteNote(idToDelete);
    break;

  default:
    console.log(
      'Command not recognized. Available commands: add, list, get, delete'
    );
    break;
}
