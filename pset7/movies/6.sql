 --write a SQL query to determine the average rating of all movies released in 2012
 SELECT AVG(rating) FROM ratings join movies ON ratings.movie_id = movies.id WHERE year = 2012;
