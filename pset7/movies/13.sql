--write a SQL query to list the names of all people
--who starred in a movie in which Kevin Bacon also starred.

SELECT DISTINCT(people.name) FROM people
JOIN stars ON stars.person_id = people.id
JOIN movies ON movies.id = stars.movie_id
WHERE stars.movie_id IN
    (SELECT movies.id FROM people
    JOIN stars ON stars.person_id = people.id
    JOIN movies ON movies.id = stars.movie_id
    WHERE people.name = "Kevin Bacon" AND people.birth = 1958)
    AND people.name != "Kevin Bacon";