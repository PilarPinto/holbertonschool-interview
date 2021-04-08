#!/usr/bin/node
const request = require('request');

const options = {
  url: `https://swapi-api.hbtn.io/api/films/${process.argv[2]}/`,
  headers: {
    'User-Agent': 'request'
  }
};

getData();

function getData () {
  request(options, async (err, response, body) => {
    if (!err) {
      for (const people of JSON.parse(body).characters) {
        await getCharactersNames(people);
      }
    } else {
      console.log(err);
    }
  });
}

function getCharactersNames (people) {
  return new Promise((resolve, reject) => {
    request(people, (err, response, body) => {
      if (!err) {
        console.log(JSON.parse(body).name);
        resolve();
      } else {
        reject(err);
      }
    });
  });
}
