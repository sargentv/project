project: main.o movie1.o 
cc main.o movie1.o -o project
main.o: main.c movie.h
cc main.c -c
movie1.o: movie.h movie1.c
cc movie1.c -c
