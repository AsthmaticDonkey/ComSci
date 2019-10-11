#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>
#include <queue>
#include <functional>
#include "HuffmanNode.h"

#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

using namespace std;
namespace NDXMYR001{
class HuffmanTree
{

    private:
        vector<string> bts;
        vector<NDXMYR001::HuffmanNode> pv;
//        priority_queue<shared_ptr<HuffmanNode>, std::vector<shared_ptr<HuffmanNode>>, compare> pq;
        unordered_map<char, string> code;
        unordered_map<string ,char> decode;
         string bin;
         unordered_map<char,int> m;
//         auto count;
         
        shared_ptr<HuffmanNode> s8;
    
    public:
        HuffmanTree(void);
        ~HuffmanTree(void);
        void frequency(string filename);
        void build(void);
        shared_ptr<HuffmanNode> getS8(void);
        void codeTable(shared_ptr<HuffmanNode> s1, string bin);
        void compress(string s, string out);
        
//        string decoder(string s);
        
};
}
#endif

