__start__: obj Tablica
	./Tablica

CPPFLAGS=-Wall -pedantic -Iinc -c
LDFLAGS=-Wall



obj:
	mkdir obj

Tablica:  obj/tablica.o 
	g++ ${LDFLAGS} -o Tablica obj/tablica.o

obj/tablica.o: tablica.cpp 
	g++ ${CPPFLAGS} -o obj/tablica.o tablica.cpp

clean:
	rm -f Tablica obj/* core*
