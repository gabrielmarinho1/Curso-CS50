/*list of the titles and release years of all Harry Potter movies, in chronological order.*/
SELECT
    movies.title,
    year
FROM    movies
WHERE   title LIKE 'Harry Potter%'
ORDER BY year;