#include<iostream>
#include<fstream>
#include <unordered_map>
#include <string>
#include "HuffmanNode.h"
#include "HuffmanTree.h"

using namespace std;
using namespace NDXMYR001;

/*unordered_map<char,int> m;
class huffencode
{
    public:
    void frequency(string filename)
    {
        char ch;
        ifstream f;
        f.open(filename);
        while(f>>ch)
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
};*/

int main(int argc, char *argv[])
{
    //huffencode h;
    
    HuffmanTree* hufft = new HuffmanTree();
    (*hufft).frequency(argv[1]);
    (*hufft).build();
    
    
    std::ifstream file(argv[1], std::ios_base::in|std::ios_base::ate);
    long file_length = file.tellg();
    file.seekg(0, std::ios_base::beg);

    char *st = new char[file_length];
    file.read(st, file_length);
    (*hufft).codeTable((*hufft).getS8(), "");
    cout<< "here"<<endl;
    (*hufft).compress(st, argv[2]);
    
    
}
