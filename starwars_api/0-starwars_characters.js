#!/usr/bin/node
const request = require('request');

// Get the movie ID from the command line argument
const movieId = process.argv[2];

// Function to fetch character names from the Star Wars API
function getStarWarsCharacters(movieId) {
  const url = `https://swapi.dev/api/films/${movieId}/`;

  // Make a request to fetch the movie data
  request(url, function (err, response, body) {
    if (err) {
      console.error('Error fetching data:', err);
      return;
    }

    if (response.statusCode !== 200) {
      console.error('Error: Unable to fetch data');
      return;
    }

    // Parse the response body
    const movieData = JSON.parse(body);
    const characterUrls = movieData.characters;

    // Fetch each character's data
    characterUrls.forEach(function (characterUrl) {
      request(characterUrl, function (err, response, body) {
        if (err) {
          console.error('Error fetching character data:', err);
          return;
        }

        if (response.statusCode !== 200) {
          console.error('Error: Unable to fetch character data');
          return;
        }

        // Parse and print the character name
        const characterData = JSON.parse(body);
        console.log(characterData.name);
      });
    });
  });
}

// Validate input and call the function
if (!movieId) {
  console.log('Usage: ./0-starwars_characters.js <Movie ID>');
  process.exit(1);
}

getStarWarsCharacters(movieId);
