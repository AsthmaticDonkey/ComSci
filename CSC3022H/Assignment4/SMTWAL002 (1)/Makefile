CFLAGS=-std=c++11
imageops: main.o Image.o
	g++ $(CFLAGS) main.o Image.o -o imageops

main.o: main.cpp Image.h
	g++ $(CFLAGS) main.cpp -c

Image.o: Image.cpp Image.h
	g++ $(CFLAGS) Image.cpp -c

clean:
	rm -f *.o imageops