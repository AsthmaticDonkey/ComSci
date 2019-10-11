CC=g++         # the compiler
LIBS=-lm       # the libraries we will ref
CFLAGS=-std=c++11

makeimageops: iterator.o Image.o imageops.o Image.h
	$(CC) $(CFLAGS) iterator.o Image.o imageops.o Image.h -o imageops

imageops.o: imageops.cpp Image.h
	$(CC) $(CFLAGS) imageops.cpp -c  

Image.o: Image.cpp Image.h
	$(CC) $(CFLAGS) Image.cpp -c 

iterator.o: iterator.cpp Image.h
	$(CC) $(CFLAGS) iterator.cpp -c
   
# other rules; invoked by make clean etc 

# deletes all the object code files
clean:
	@rm -f *.o
