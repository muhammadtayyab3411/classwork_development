const net = require('net');
const readline = require('readline');

const client = new net.Socket();
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const serverAddress = '127.0.0.1';
const serverPort = 12345;

// Connect to the server
client.connect(serverPort, serverAddress, () => {
  console.log('Connected to server');

  // Request authentication
  rl.question('Enter password: ', (password) => {
    // Send the password to the server
    client.write(password + '\n');
  });
});

// Handle server response
client.on('data', (data) => {
  console.log(data.toString());
  // send data to the server
  client.write('Hello, server!\n');
  rl.close();
});

// Handle connection termination
client.on('close', () => {
  console.log('Connection closed');
});
