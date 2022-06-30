/* get the names of all people who starred in a movie in which Kevin Bacon also starred*/
SELECT  people.name
FROM    people
WHERE   people.id IN (
    SELECT  stars.person_id    --get the ids of the people that starred in the movies from stars
    FROM    stars
    WHERE   stars.movie_id IN (
        SELECT  movies.id   -- get the ids of the movies that KB starred from movies
        FROM movies
        WHERE   movies.id IN (
            SELECT stars.movie_id   -- get the ids of the movies that KB starred from stars
            FROM stars
            WHERE   stars.person_id IN (
                SELECT  people.id   -- get Kevin Bacon's id from people
                FROM people
                WHERE
                    people.name = "Kevin Bacon" AND people.birth = 1958
            )
        )
    )
)
AND NOT people.name = "Kevin Bacon";   -- except him self