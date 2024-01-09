const net = require('net');

const server = net.createServer((socket) => {
  console.log('Client connected');

  let password = '';

  // Handle data received from the client
  socket.on('data', (data) => {
    password += data.toString();

    // Check if the password input is complete
    if (password.includes('\n')) {
      password = password.trim(); // Remove trailing newline character

      if (password === 'password') {
        // Successful authentication
        console.log('Authentication successful');

        // Send data to the client
        socket.write('\nHello, client!\n');

        // Handle data received from the client
        socket.on('data', (message) => {
          console.log(message.toString());

          // Close the connection
          socket.end();
        });
      } else {
        // Incorrect password
        socket.end();
      }
    }
  });

  // Handle client disconnection
  socket.on('end', () => {
    console.log('Client disconnected');
  });
});

const port = 12345;
server.listen(port, () => {
  console.log(`Server listening on port ${port}`);
});
