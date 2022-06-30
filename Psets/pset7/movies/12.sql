/*list the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred*/
SELECT  movies.title
FROM    movies
    INNER JOIN  stars
    ON  stars.movie_id = movies.id
WHERE   stars.person_id IN(
    SELECT  id  -- get the ids of Johhny Depp and Helena Carter
    FROM    people
    WHERE   people.name IN (
        'Johnny Depp','Helena Bonham Carter'
    )
)
GROUP BY
    movies.title
HAVING
    COUNT(movies.title) = 2;    -- get just the movies witch starred