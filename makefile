mastermind: classic.o ia.o main.o
	gcc classic.o ia.o main.o -o mastermind
	rm -f *.o core

ia.o: ia.c
	gcc -c ia.c 

classic.o: classic.c 
	gcc -c classic.c 

main.o: main.c params.h
	gcc -c main.c 

clean:
	rm -f *.o core