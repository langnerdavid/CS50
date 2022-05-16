--write a SQL query to list the names of all people
--who have directed a movie
--that received a rating of at least 9.0

SELECT DISTINCT(people.name) FROM people
JOIN directors ON people.id = directors.person_id
--JOIN movies ON movies.id = directors.movie_id
JOIN ratings ON ratings.movie_id = directors.movie_id
WHERE ratings.rating >= 9.0;