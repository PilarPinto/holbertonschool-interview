#!/usr/bin/node
/* Star Wars API info */
const request = require('request');
const urlAcc = 'https://swapi-api.hbtn.io/api/films/';
const movPos = process.argv[2];
// query
request(urlAcc + moviPos, (error, response, body) => {
  if (error) throw error;
  const characters = JSON.parse(body).characters;
  showNames(characters);
});
// console print
const showNames = (names, i = 0) => {
  if (i === names.length) return;
  request(names[i], (error, response, body) => {
    if (error) throw error;
    console.log(JSON.parse(body).name);
    showNames(names, i + 1);
  });
};
