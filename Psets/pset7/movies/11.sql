/*list of the titles of the five highest rated movies (in order) that Chadwick Boseman starred in,
starting with the highest rated*/
SELECT  title
FROM    movies
    INNER JOIN  ratings
    ON  ratings.movie_id = movies.id

    INNER JOIN  stars
    ON  stars.movie_id = movies.id
WHERE   stars.person_id IN (
    SELECT  id  -- get Chadwick Boseman's id
    FROM    people
    WHERE   people.name = "Chadwick Boseman"
)
ORDER BY
    ratings.rating DESC
LIMIT   5;