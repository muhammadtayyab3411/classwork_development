const express = require('express');
const fs = require('fs').promises;
const bodyParser = require('body-parser');

const app = express();
const port = process.env.PORT || 3000;

app.use(bodyParser.json());

async function getCandidates() {
  const data = await fs.readFile('./db/candidate.json', 'utf8');
  return JSON.parse(data);
}

async function getSeats() {
  const data = await fs.readFile('./db/nationalAssemblySeat.json', 'utf8');
  return JSON.parse(data);
}

async function saveCandidates(candidates) {
  await fs.writeFile('./db/candidate.json', JSON.stringify(candidates));
}

async function saveSeats(seats) {
  await fs.writeFile('./db/nationalAssemblySeat.json', JSON.stringify(seats));
}

app.get('/candidates', async (req, res) => {
  const candidates = await getCandidates();
  res.status(200).send(candidates);
});

app.post('/candidate', async (req, res) => {
  const { symbol, party, name } = req.body;

  if (!symbol || !party || !name) return res.status(400).send('Invalid data');

  const candidates = await getCandidates();
  const seats = await getSeats();

  const candidate = {
    id: candidates.length + 1,
    symbol,
    party,
    name,
  };

  const seat = {
    id: seats.length + 1,
    seat_number: 1 + Math.random() * 10,
    candidate_id: candidate.id,
    votes: 0,
  };

  await saveCandidates([...candidates, candidate]);
  await saveSeats([...seats, seat]);

  res.status(200).send(candidate);
});

app.post('/vote', async (req, res) => {
  const { seat_number, candidate_id } = req.body;

  if (!candidate_id) return res.status(400).send('Invalid data');

  const candidates = await getCandidates();
  const seats = await getSeats();

  const candidate = candidates.find((c) => c.id === candidate_id);
  const seat = seats.find(
    (s) => s.candidate_id === candidate_id && s.seat_number === seat_number
  );

  if (!candidate || !seat) return res.status(400).send('Invalid data');

  seat.votes += 1;
  await saveSeats(seats);

  res.status(200).send(seat);
});

app.post('/winner', async (req, res) => {
  const { seat_number } = req.body;

  const seats = await getSeats();
  const candidates = await getCandidates();

  const seat = seats.filter((s) => s.seat_number === seat_number);

  if (seat.length === 0)
    return res.status(400).send('No seats found with the provided number');

  const winner = seat.reduce((a, b) => (a.votes > b.votes ? a : b));
  winner['candidate'] = candidates.find((c) => c.id === winner.candidate_id);

  res.status(200).send(winner);
});

app.get('/overAllWinner', async (req, res) => {
  const seats = await getSeats();
  const candidates = await getCandidates();

  const winner = seats.reduce((a, b) => (a.votes > b.votes ? a : b));
  winner['candidate'] = candidates.find((c) => c.id === winner.candidate_id);

  res.status(200).send(winner);
});

app.listen(port, () => {
  console.log(`Server is running on port ${port}`);
});
