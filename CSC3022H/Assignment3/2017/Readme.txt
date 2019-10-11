 HuffmanNode.cpp uses it's own header in the make file. It includes this header file.
 HuffmanTree.cpp uses it's own header and HuffmanNode.h . This is because it includes HuffmanNode.
 huffencode.cpp uses the HuffmanTree.h file as it include HuffmanTree.
 
 huffencode uses the .o files of all 3 .cpp files.
 
 build() creates shared pointers for all the letters and places them in a priority queue. it then builds the tree buy removing the nodes and coupling them to an internal node before re-adding them to the priority queue till there is only one left.
 
 codeTable() recurses down the tree, adding to the assosiated string each time. finally adding it to an unordered map
 
 compress uses a unordered map to change the characters into the assosiated string.
