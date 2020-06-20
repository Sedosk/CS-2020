-- SQL query to determine the number of movies with an IMDb rating of 10.0.

SELECT title, year FROM movies 
WHERE title LIKE "Harry Potter%" 
ORDER BY year ASC;
