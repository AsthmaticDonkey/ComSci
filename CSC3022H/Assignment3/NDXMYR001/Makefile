CC=g++ -std=c++11    # the compiler
LIBS=-lm       # the libraries we will ref

# Need object files main.o and methods.o to create exe 
VolImage: main.o VolImage.o
	$(CC) main.o VolImage.o -o VolImage

main.o: main.cpp
	$(CC) -c main.cpp

VolImage.o: VolImage.cpp VolImage.h
	$(CC) VolImage.cpp -c 
   
# other rules; invoked by make clean etc 

# deletes all the object code files
clean:
	@rm -f *.o
