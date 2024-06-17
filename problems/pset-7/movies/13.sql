SELECT DISTINCT other_people.name
FROM people AS kevin_bacon
JOIN stars AS kevin_stars ON kevin_bacon.id = kevin_stars.person_id
JOIN movies ON kevin_stars.movie_id = movies.id
JOIN stars AS other_stars ON movies.id = other_stars.movie_id
JOIN people AS other_people ON other_stars.person_id = other_people.id
WHERE kevin_bacon.name = 'Kevin Bacon' AND kevin_bacon.birth = 1958 AND other_people.name != 'Kevin Bacon';
