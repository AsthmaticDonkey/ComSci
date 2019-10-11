#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <memory>
#include <string>


#include "Image.h"

using namespace std;
namespace NDXMYR001
{
    

    Image::iterator::iterator()
    {
        ptr = nullptr;
    }
    Image::iterator::~iterator()
    {
        ptr = nullptr;
    }

    void Image::iterator::operator++()
    {
        ptr++;
    }
    void Image::iterator::operator--()
    {
        ptr--;
    }
    bool Image::iterator::operator==(iterator& n)
    {
        return (ptr == *n);
    }
    void Image::iterator::operator=(iterator n)
    {
        ptr = *n;
    }
    unsigned char* Image::iterator::operator*()
    {
        return ptr;
    }

   /* int Image::iterator::operator+(iterator& n)
    {
        return (*ptr + *n);
    }*/
    void Image::iterator::setValue(unsigned char i)
    {
        *ptr = i;
    }
    
    unsigned char Image::iterator::getValue()
    {
        return *ptr;
    }
    
   /* void Image::iterator::copy(unsigned char *a, unsigned char *b, int i, Image n)
    {
        cp = new unsigned char[i];
        for(int w=0; w<n.getLength(); w++)
        {
            cp[w] = *a;
            a++;
        }
        ptr = &(cp[0]);
    }*/
}
