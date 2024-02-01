const express = require('express');
const fs = require('fs');
const bodyParser = require('body-parser');
const app = express();

const port = process.env.PORT || 3000;

app.use(bodyParser.json());

const Candidate = [
  {
    id: 1,
    symbol: 'bat',
    party: 'PTI',
  },
  {
    id: 2,
    symbol: 'lion',
    party: 'PML-N',
  },
  {
    id: 3,
    symbol: 'arrow',
    party: 'PPP',
  },
];

const NationalAssemblySeat = [
  {
    id: 1,
    seat_number: 1,
    candidate_id: 1,
    votes: 20,
  },
  {
    id: 2,
    seat_number: 1,
    candidate_id: 2,
    votes: 10,
  },
  {
    id: 3,
    seat_number: 1,
    candidate_id: 3,
    votes: 5,
  },
];

app.get('/candidates', (req, res) => {
  const candidates = JSON.parse(fs.readFileSync('./db/candidate.json', 'utf8'));

  res.status(200).send(candidates);
});

app.post('/candidate', (req, res) => {
  const { symbol, party, name } = req.body;

  if (!symbol || !party || !name) return res.status(400).send('Invalid data');

  const candidate = {
    id: Candidate.length + 1,
    symbol,
    party,
    name,
  };

  const nationalAssemblySeat = {
    id: NationalAssemblySeat.length + 1,
    seat_number: 1 + Math.random() * 10,
    candidate_id: candidate.id,
    votes: 0,
  };

  fs.writeFileSync(
    './db/candidate.json',
    JSON.stringify([...Candidate, candidate])
  );

  fs.writeFileSync(
    './db/nationalAssemblySeat.json',
    JSON.stringify([...NationalAssemblySeat, nationalAssemblySeat])
  );

  res.status(200).send(candidate);
});

app.post('/vote', (req, res) => {
  const { candidate_id } = req.body;

  if (!candidate_id) return res.status(400).send('Invalid data');

  const candidate = Candidate.find((c) => c.id === candidate_id);

  if (!candidate) return res.status(400).send('Invalid candidate');

  let nationalAssemblySeats = JSON.parse(
    fs.readFileSync('./db/nationalAssemblySeat.json', 'utf8')
  );

  let nationalAssemblySeat = nationalAssemblySeats.find(
    (n) => n.candidate_id === candidate_id
  );

  if (!nationalAssemblySeat)
    return res.status(400).send('Invalid national assembly seat');

  nationalAssemblySeat.votes += 1;

  fs.writeFileSync(
    './db/nationalAssemblySeat.json',
    JSON.stringify(nationalAssemblySeats, null, 2)
  );

  res.status(200).send(nationalAssemblySeat);
});

app.get('/winner', (req, res) => {
  let nationalAssemblySeats = JSON.parse(
    fs.readFileSync('./db/nationalAssemblySeat.json', 'utf8')
  );

  const winner = nationalAssemblySeats.reduce((acc, curr) =>
    acc.votes > curr.votes ? acc : curr
  );

  let candidates = JSON.parse(fs.readFileSync('./db/candidate.json', 'utf8'));

  winner['candidate'] = candidates.find((c) => c.id === winner.candidate_id);

  res.status(200).send(winner);
});

app.listen(port, () => {
  console.log(`Server is running on port ${port}`);
});
