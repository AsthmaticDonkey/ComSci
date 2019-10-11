#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <memory>
#include <string>

#ifndef IMAGE_H
#define IMAGE_H

namespace NDXMYR001{  
class Image{
    private:
        int width, height, length;
        friend class iterator;
        friend class imageops;
        
    public:
        std::unique_ptr<unsigned char[]> data;
    class iterator
        {
            private:
                unsigned char *ptr;
                iterator(unsigned char *p) : ptr(p) {}
                unsigned char *cp;
                friend class Image;
                friend class imageops;
            public:
                iterator();
               // iterator(iterator& i);
                iterator(Image n);
                ~iterator();
                
                //void end();
                //void begin();
                void operator++();
                void operator--();
                bool operator==(iterator& n);
                unsigned char* operator*();
                void operator=(iterator n);
                //int operator+(iterator n);
                void setValue(unsigned char i);
                unsigned char getValue();
                //Image::iterator begin();
                //Image::iterator end();
                //unsigned char* getPtr();
                //void copy(unsigned char *a, unsigned char *b, int i, Image n);
        };
    
    Image(std::string s);
    Image(int l);
    Image(Image& i);
    ~Image();
    void write(std::string s);
    Image* operator+(Image &n);
    Image* operator-(Image n);
    Image* operator/(Image &n);
    Image* operator*(int f);
    Image* operator!();
    Image::iterator begin(void) const;
    Image::iterator end(void) const;
    int getHeight();
    int getWidth();
    int getLength();
    void setHeight(int h);
    void setWidth(int w);
    std::string operator<<(std::string head);
    Image* operator>>(std::string head);
    //void Image::copy(const Image& rhs);
};
}
#endif
