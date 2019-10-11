#include <iostream>
#include <memory>

#ifndef HUFFMAN_NODE_H
#define HUFFMAN_NODE_H

namespace NDXMYR001{  
class HuffmanNode{
    private:
        std::shared_ptr<HuffmanNode> l;
        std::shared_ptr<HuffmanNode> r;
        
        char letter;
        int frequency;
        bool end;
        
    public:
        HuffmanNode(std::shared_ptr<HuffmanNode> a, std::shared_ptr<HuffmanNode> b);
        HuffmanNode();
        HuffmanNode(char a, int b);
        
        ~HuffmanNode(void);
        
        std::shared_ptr<HuffmanNode> getLeft(void);
        std::shared_ptr<HuffmanNode> getRight(void);
        //std::shared_ptr<HuffmanNode> getRoot(void);
        char getLetter(void);
        int getFreq(void);
        bool getEnd(void);
        
        void setLeft(std::shared_ptr<HuffmanNode> a);
        void setRight(std::shared_ptr<HuffmanNode> b);
        //void setRoot(std::shared_ptr<HuffmanNode> c);
        void setLetter(char d);
        void setFreq(int e);
        
        void move(std::shared_ptr<HuffmanNode> a, std::shared_ptr<HuffmanNode> b, std::shared_ptr<HuffmanNode> c, int d);
        
        bool compare(const HuffmanNode& b);
        
};
}
#endif
