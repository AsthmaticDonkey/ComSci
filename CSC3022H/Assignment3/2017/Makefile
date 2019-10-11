CC=g++ -std=c++11    # the compiler
LIBS=-lm       # the libraries we will ref

#huffencode: huffencode.o
#	$(CC) huffencode.o -o huffencode

huffencode:   HuffmanNode.o HuffmanTree.o huffencode.o
	$(CC) HuffmanNode.o HuffmanTree.o huffencode.o -o huffencode
	
HuffmanNode.o: HuffmanNode.cpp HuffmanNode.h
	$(CC) HuffmanNode.cpp -c
	
HuffmanTree.o: HuffmanTree.cpp HuffmanNode.h HuffmanTree.h
	$(CC) HuffmanTree.cpp -c 
	
huffencode.o: huffencode.cpp HuffmanTree.h
	$(CC) huffencode.cpp -c 
   
# other rules; invoked by make clean etc 

# deletes all the object code files
clean:
	@rm -f *.o
