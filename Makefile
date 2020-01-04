all: babyQuery 

babyQuery:babyQuery.o removeCommas.o
	gcc -ansi -Wall -o babyQuery babyQuery.o removeCommas.o

babyQuery.o: babyQuery.c
	gcc -ansi -Wall -c babyQuery.c

removeCommas.o: removeCommas.c
	gcc -ansi -Wall -c removeCommas.c

clean:
	rm babyQuery.o babyQuery removeCommas.o removeCommas

