--write a SQL query to list the names of all people who starred in Toy Story
SELECT people.name FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON movies.id = stars.movie_id
WHERE stars.movie_id =
    (SELECT movies.id from movies
        WHERE title LIKE "%Toy Story%");