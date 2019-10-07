CC=g++         # the compiler
LIBS=-lm       # the libraries we will ref

# Need object files main.o and methods.o to create exe 
data: main.o methods.o
	$(CC) main.o methods.o -o data


main.o: main.cpp database.h
	$(CC) -c main.cpp

methods.o: methods.cpp database.h
	$(CC) -c methods.cpp
   
# other rules; invoked by make clean etc 

# deletes all the object code files
clean:
	@rm -f *.o
