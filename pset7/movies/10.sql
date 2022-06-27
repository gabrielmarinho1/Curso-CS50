/*list the names of all people who have directed a movie that received a rating of at least 9.0*/
SELECT  DISTINCT(people.name)
FROM    people
WHERE   people.id IN (
    SELECT  person_id   -- get the ids of the people starred in the movies
    FROM    directors
    WHERE   movie_id IN (
        SELECT  id  -- get the ids o the movies with rating at least 9.0
        FROM    movies
            INNER JOIN  ratings
            ON  movies.id = ratings.movie_id
        WHERE   ratings.rating >= 9.0
    )
);