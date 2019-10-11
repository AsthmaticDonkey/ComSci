#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <memory>
#include <string>

#include "Image.h"

using namespace std;
namespace NDXMYR001{
    

    Image::Image(string s)// Read image from file constructor (file name as parameter.)
    {
        ifstream file;
        file.open(s+".pgm");
        string line;
        stringstream ss;
        getline(file, line);//Remove first line
        getline(file, line);//Remove second line

        while(line[0] == '#')
        {
            getline(file, line);// While first character in line is #, remove line
        }

        ss<<line;//Put line into stringstream
        ss >> width;//Get width of image
        ss >> height;//Get height of image
        length = height*width;
        unique_ptr<unsigned char[]> t(new unsigned char[length]);
        file.read((char*)(t.get()),length);
        data = move(t);
    }

    Image::Image(int l)// Create blank image of length l (height*width = l)
    {
        length = l;
        unique_ptr<unsigned char[]> w(new unsigned char[length]);
        int y = 0;
        for(y = 0; y<length; y++)
        {
            w[y] = 0;
        }
        data = move(w);

    }

    Image::Image(Image& i)//copies image at i
    {
        height = i.getHeight();
        width = i.getWidth();

        iterator st1 = i.begin();
        
        unique_ptr<unsigned char[]> q(new unsigned char[height*width]);

        int y;
        for(y = 0; y<height*width; y++)
        {
            q[y] = **st1;
            ++st1;
        }
        length = height*width;
        data = move(q);
    }

    Image::~Image()//Delete constructor
    {
        data.reset();
    }
    
    
    int Image::getLength()//Return int Length
    {
        return height*width;
    }
    int Image::getHeight()//Return int height
    {
        return height;
    }
    int Image::getWidth()//Return int width
    {
        return width;
    }

    void Image::setHeight(int h)//Set int height
    {
        height = h;
    }
    void Image::setWidth(int w)//Set int width
    {
        width = w;
    }

    Image::iterator Image::begin(void) const//Returns first point of iterator
    {
        return  iterator(&(data.get()[0]));
    }
    
    Image::iterator Image::end(void) const
    {
        return  iterator(&(data.get()[length]));
    }

    void Image::write(string s)//create new file
    {
        
        s = s + "_out.pgm";
        ofstream ifs (s, std::ofstream::binary);

        ifs<<"P5\n";
        ifs<<"#\n";
        ifs<<height<<" "<<width<<"\n";
        ifs<<"255\n";
        iterator it = this->begin();
        string p = "";
        for(int q=0; q<=height; q++)
        {
            for(int w=0; w<=width; w++)
            {
                p += it.getValue();
                ++it;
            }
                
        }
        ifs<<p;
       
    }

    Image* Image::operator+(Image &n)//plus operator
    {
        iterator st1 = iterator(&(data.get()[0]));
        iterator en1 = iterator(&(data.get()[length]));
        iterator st2 = n.begin();
        
        Image *temp = new Image(height*width);

        temp->setHeight(height);
        temp->setWidth(width);

        iterator st3 = temp->begin();
        while(!(st1 == en1))
        {
            int o = ((int)st1.getValue() + (int)st2.getValue());
            if(o>255){o=255;}
            unsigned char i = (unsigned char) o;
            st3.setValue(i);
            ++st3;
            ++st2;    
            ++st1;
        }
        int o = ((int)st1.getValue() + (int)st2.getValue());
        if(o>255){o=255;}
        unsigned char i = (unsigned char) o;
        st3.setValue(i);
        ++st3;
        ++st2;    
        ++st1;
        return temp;
    }

   Image* Image::operator-(Image n)//minus operator
    {
        iterator st1 = iterator(&(data.get()[0]));
        iterator en1 = iterator(&(data.get()[length]));
        iterator st2 = n.begin();
        
        Image *temp = new Image(height*width);

        temp->setHeight(height);
        temp->setWidth(width);

        iterator st3 = temp->begin();
        while(!(st1 == en1))
        {
            int o = ((int)st1.getValue() - (int)st2.getValue());
            if(o<0){o=0;}
            unsigned char i = (unsigned char) o;
            st3.setValue(i);
            ++st3;
            ++st2;    
            ++st1;
        }
        int o = ((int)st1.getValue() - (int)st2.getValue());
        if(o<0){o=0;}
        unsigned char i = (unsigned char) o;
        st3.setValue(i);
        ++st3;
        ++st2;    
        ++st1;
        return temp;
    }



    Image* Image::operator/(Image &n)//Divide operator
    {
        iterator st1 = iterator(&(data.get()[0]));
        iterator en1 = iterator(&(data.get()[length]));
        iterator st2 = n.begin();
        
        Image *temp = new Image(height*width);

        temp->setHeight(height);
        temp->setWidth(width);

        iterator st3 = temp->begin();
        while(!(st1 == en1))
        {
            if((int)st2.getValue() == 0)
            {
                st3.setValue((unsigned char)255);
            }
            else
            {
                unsigned char i =st1.getValue();
                st3.setValue(i);
            }
            ++st3;
            ++st2;    
            ++st1;
        }
        if(((int)st2.getValue()) == 255)
            {
                unsigned char i =st1.getValue();
                st3.setValue(i);
            }
            else
            {
                st3.setValue((unsigned char)255);
            }
            ++st3;
            ++st2;    
            ++st1;
        return temp;
    }

    
    Image* Image::operator!()
    {
        iterator st1 = iterator(&(data.get()[0]));
        iterator en1 = iterator(&(data.get()[length]));
   
        
        Image *temp = new Image(height*width);

        temp->setHeight(height);
        temp->setWidth(width);

        iterator st3 = temp->begin();
        while(!(st1 == en1))
        {
            unsigned char i =st1.getValue();
            i = 255 - i;
            st3.setValue(i);
            ++st3;    
            ++st1;
        }
        unsigned char i =st1.getValue();
        i = 255 - i;
        st3.setValue(i);
        ++st3;    
        ++st1;
        return temp;
    }

    Image* Image::operator*(int z)//Multiply operator
    {
        iterator st1 = iterator(&(data.get()[0]));
        iterator en1 = iterator(&(data.get()[length]));
   
        
        Image *temp = new Image(height*width);

        temp->setHeight(height);
        temp->setWidth(width);

        iterator st3 = temp->begin();
        while(!(st1 == en1))
        {
            if(st1.getValue()>z)
            {
                unsigned char i =z;
                st3.setValue(i);
                ++st3;    
                ++st1;
            }
            else
            {
                unsigned char i =st1.getValue();
                st3.setValue(i);
                ++st3;    
                ++st1;
            }
        }
        
        if(st1.getValue()>z)
        {
            unsigned char i =z;
            st3.setValue(i);
            ++st3;    
            ++st1;
        }
        else
        {
            unsigned char i =st1.getValue();
            st3.setValue(i);
            ++st3;    
            ++st1;
        }

        return temp;
    }
    
     string Image::operator<<(string head)
    {
        string p = "";
        p += "P5\n";
        p += "#\n";
        p += height;
        p += " ";
        p += width;
        p += "\n";
        p += "255\n";
        iterator it = this->begin();
        for(int q=0; q<=height; q++)
        {
            for(int w=0; w<=width; w++)
            {
                p += it.getValue();
                ++it;
            }
            
        }
        return p;
       
    }

    Image* Image::operator>>(string head)
    {
        Image* temp = new Image(head);
        return temp;
    }
}
