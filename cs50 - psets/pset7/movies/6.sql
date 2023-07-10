SELECT avg(rating) FROM ratings WHERE rating IS NOT NULL;

--outra alternativa
--select avg(rating) from ratings
--join movies on movies.id=ratings.movie_id
--where movies.year=2012;

-- obs:os resultados estão diferentes O.o


