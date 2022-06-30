/*list the names of all people who starred in a movie released in 2004, ordered by birth year*/
SELECT  people.name
FROM    people
WHERE   id IN (
    SELECT  person_id   -- get the ids of the people who starred in the movies
    FROM    stars
    WHERE   movie_id IN (
        SELECT  id  -- get the ids of the movies released in 2004
        FROM    movies
        WHERE   year = 2004
    )
)
ORDER BY people.birth;