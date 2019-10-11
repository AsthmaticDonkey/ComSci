#include <iostream>
#include <memory>
#include <fstream>
#include <unordered_map>
#include "HuffmanNode.h"
#include "HuffmanTree.h"
#include <vector>
#include <queue>
//#include <functional>


using namespace std;
namespace NDXMYR001{

        vector<string> bts;
        vector<NDXMYR001::HuffmanNode> pv;
        std::shared_ptr<HuffmanNode> root;
        unordered_map<char, string> code;
        unordered_map<string ,char> decode;
         string bin;
         unordered_map<char,int> m;
//         auto count;
         
        shared_ptr<HuffmanNode> s8;
         
        HuffmanTree::HuffmanTree(){}
        HuffmanTree::~HuffmanTree(){}
        
        struct compare
        {
            bool operator()(const shared_ptr<HuffmanNode>& left, const shared_ptr<HuffmanNode>& right) const
            {
                return (*left).getFreq() > (*right).getFreq();
            }
        };
        
        void HuffmanTree::frequency(string filename)
        {
            char ch;
            ifstream f;
            f.open(filename);
            while(f>> noskipws >> ch)
            {
                //unordered_map<char,int>::const_iterator got = m.find (ch);
                auto got = m.find (ch);
                if(got != m.end())
                {
                    int i = (*got).second;
                    got->second = i +1;
                }
                else
                {
                    m.insert({ch,1});
                }
            }
            f.close();
            
        }
         
         
        void HuffmanTree::build()
        {
            //auto count = pv.begin();
            //HuffmanNode* htemp =new HuffmanNode();
            /*(while(!m.empty())
            {
                char let;
                int fre = 0;
                for(auto q = m.begin(); q != m.end(); q++ )
                {
                    if((*q).second >= fre)
                    {
                        let = (*q).first;
                    }
                }
                auto q = m.find(let);
                cout << (*q).first << (*q).second << endl;
                (*htemp).setFreq((*q).second);
                (*htemp).setLetter((*q).first);
                m.erase((*q).first);
                pv.push_back(*htemp);
                //pv.insert(*htemp);
                //count++;
                cout <<"here"<<endl;
                
            }*/
            priority_queue<shared_ptr<HuffmanNode>, std::vector<shared_ptr<HuffmanNode>>, compare> pq;
            for (auto itr:m) 
            {
                pq.push(make_shared<HuffmanNode>(itr.first, itr.second));
            }
            
            
            while(pq.size() != 1)
            {
               shared_ptr<HuffmanNode> s1 = pq.top();
               pq.pop();
               shared_ptr<HuffmanNode> s2 = pq.top();
               pq.pop();
               s8 = make_shared<HuffmanNode>(s1, s2);
               pq.push(s8);
            }
           
        }
        
        shared_ptr<HuffmanNode> HuffmanTree::getS8()
        {
            return s8;
        } 
        
       
        void HuffmanTree::codeTable(shared_ptr<HuffmanNode> s1, string bin)
        {
            if((*s1).getEnd())
            {
                char ch = (*s1).getLetter();
                cout<< ch << " "<< bin<< endl;
                code.insert({ch, bin});
                return;
            }
            else
            {
                codeTable((*s1).getLeft(), bin+"1");
                codeTable((*s1).getRight(), bin+"0");
                
            }
        }
        
        void HuffmanTree::compress(string s, string out)
        {
            string compress = "";
            ofstream mf;
            mf.open(out<<".hdr");
            for (char &c : s)
            {
                //cout<<c<<endl;
                mf << (*code.find(c)).second << " ";
//              bts.insert(a+"");
            }
            mf.close();
        }
        
/*        string decoder(string s)
        {
            for(auto a = code.begin(); a !=code.end(); a++)
            {
                decode.insert((*a).second, (*a).first);
            }
            string decompress = "";
            for (auto a= bts.begin(); a !=bts.end(); a++)
            {
                string b = (*decode.find(*a)).second;
                decompress.append(b);
            }
            return decompress;
        }*/
        
        
}


