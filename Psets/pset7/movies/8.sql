/*list the names of all people who starred in Toy Story*/
SELECT  people.name
FROM  people
    INNER JOIN  stars
    ON  people.id = stars.person_id
WHERE stars.movie_id IN (
  SELECT  movies.id -- get TS's id
  FROM  movies
  WHERE title ="Toy Story"
);