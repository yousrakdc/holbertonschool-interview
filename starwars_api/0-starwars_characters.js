#!/usr/bin/env

const request = require('request');

const movieId = process.argv[2];
const BASE_URL = 'https://swapi.dev/api/films/';

function printCharacter(characters, index) {
  if (index >= characters.length) {
    return;
  }
  request(characters[index], (err, res, body) => {
    if (err) {
      console.error(err);
      return;
    }
    const character = JSON.parse(body);
    console.log(character.name);
    printCharacter(characters, index + 1);
  });
}

request(`${BASE_URL}${movieId}/`, (err, res, body) => {
  if (err) {
    console.error(err);
    return;
  }
  const film = JSON.parse(body);
  printCharacter(film.characters, 0);
});
