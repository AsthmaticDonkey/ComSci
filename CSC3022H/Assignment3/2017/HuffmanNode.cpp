#include <iostream>
#include <memory>
#include "HuffmanNode.h"

namespace NDXMYR001{
using namespace std;

    
    
        std::shared_ptr<HuffmanNode> l;
        std::shared_ptr<HuffmanNode> r;
        std::shared_ptr<HuffmanNode> root;
        char letter;
        int frequency;
        bool end;
        
   
        HuffmanNode::HuffmanNode(std::shared_ptr<HuffmanNode> a, std::shared_ptr<HuffmanNode> b)
        {
            l = a;
            r = b;
            //letter = '0';
            frequency = (*a).getFreq() + (*b).getFreq();
            end = false;
            
        }
        HuffmanNode::HuffmanNode()
        {
            letter = '0';
        }
        
        HuffmanNode::HuffmanNode(char a, int b)
        {
            letter = a;
            frequency = b;
            end = true;
        }
        
        HuffmanNode::~HuffmanNode(void)
        {
/*            delete l;
            delete r;
            delete root;
*/
            delete &letter;
            delete &frequency;
            delete &end;
        }
        
        std::shared_ptr<HuffmanNode> HuffmanNode::getLeft()
        {
            return l;
        }
        std::shared_ptr<HuffmanNode> HuffmanNode::getRight()
        {
            return r;
        }
        std::shared_ptr<HuffmanNode> HuffmanNode::getRoot()
        {
            return root;
        }
         char HuffmanNode::getLetter()
        {
            return letter;
        }
        int HuffmanNode::getFreq()
        {
            return frequency;
        }
        bool HuffmanNode::getEnd()
        {
            return end;
        }
        
        void HuffmanNode::setLeft(std::shared_ptr<HuffmanNode> a)
        {
            l =a;
        }
        void HuffmanNode::setRight(std::shared_ptr<HuffmanNode> b)
        {
            r = b;
        }
        void HuffmanNode::setRoot(std::shared_ptr<HuffmanNode> c)
        {
            root = c;
        }
        
        void HuffmanNode::setLetter(char d)
        {
            letter = d;
        }
        void HuffmanNode::setFreq(int e)
        {
            frequency = e;
        }
        
        void HuffmanNode::move(std::shared_ptr<HuffmanNode> a, std::shared_ptr<HuffmanNode> b, std::shared_ptr<HuffmanNode> c, int d)
        {
            l = a;
            r = b;
            root = c;
            frequency = d;
            
        }
        
/*        bool compare(HuffmanNode& b)
        {   
            return (frequency < b.getFreq());
        }
*/        
        
        
}
