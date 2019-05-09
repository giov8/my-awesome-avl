myavl:	main.o avl.o
	gcc main.o avl.o -o myavl -Wall

main.o:	main.c
	gcc -c main.c -Wall

avl.o: 	avl.c avl.h
	gcc -c avl.c -Wall
