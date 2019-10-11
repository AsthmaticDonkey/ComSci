#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>

#include "Image.h"

using namespace std;

namespace SMTWAL002{
////////////////////////////////////////////////////////////////////////////////
   //iterator
   Image::iterator::iterator(u_char *p){
      ptr = p;
   }

   Image::iterator & Image::iterator::operator=(const iterator & rhs){
      *ptr = *rhs.ptr;
      return *this;
   }

   bool Image::iterator::operator!=(const iterator & rhs){
      return ptr!=rhs.ptr;
   }

   unsigned char & Image::iterator::operator*(){
      return *ptr;
   }

   Image::iterator & Image::iterator::operator++(){
      ++ptr;
      return *this;
   }

   Image::iterator & Image::iterator::operator--(){
      --ptr;
      return *this;
   }

////////////////////////////////////////////////////////////////////////////////
   //Image
   Image::Image(string s){
      ifstream myfile(s,ios::out|ios::binary);
      string temp;

      //Gets rid of first line P5
      getline(myfile,temp);
      //Gets rid of comments
      getline(myfile,temp);
      while (temp[0] == '#') getline(myfile,temp);

      //Read size
      stringstream  lineStream(temp);
      lineStream >> height;
      lineStream >> width;

      //Read 255
      getline(myfile,temp);

      //Read data
      unique_ptr<unsigned char[]> temp_ptr(new unsigned char[height*width]);
      myfile.read((char*)(temp_ptr.get()),height*width);
      data = std::move(temp_ptr);
      myfile.close();
   }

   Image::Image(const Image & im){
      height = im.height;
      width = im.width;
      //Reserve space
      unique_ptr<unsigned char[]> temp_ptr(new unsigned char[height*width]);
      data = std::move(temp_ptr);

      Image::iterator beg = this->begin(), end = this->end();
      Image::iterator inStart = im.begin();
      while ( beg != end)
      {
         *beg = *inStart;
         ++beg;
         ++inStart;
      }
}

   Image::~Image(){
      data = nullptr;
   }

   int Image::getWidth(){
      return width;
   }

   int Image::getHight(){
      return height;
   }

   void Image::write(string s){
      ofstream myfile(s,ios::out|ios::binary);
      string temp;

      //Writes
      myfile << "P5" << endl;
      //Gets rid of comments

      //Write size
      myfile << height << " " <<  width << endl;

      //Write 255
      myfile << "255" << endl;

      //Write data
      myfile.write((char*)(data.get()),height*width);
      myfile.close();
   }

   Image Image::operator+(Image & rhs){
      Image temp = rhs;
      Image::iterator start1 = temp.begin(), end1 = temp.end();
      Image::iterator start2 = this->begin();
      while (start1 != end1) {
         if (*start1+*start1<=255){
            *start1 = *start1 + *start2;
         }
         else *start1 =255;
         ++start1;
         ++start2;
      }
      return temp;
   }

   Image Image::operator-(const Image & rhs)const{
      Image temp = rhs;
      Image::iterator start1 = temp.begin(), end1 = temp.end();
      Image::iterator start2 = this->begin();
      while (start1 != end1) {
         if (*start2-*start1>=0){
            *start1 = *start2 - *start1;
         }
         else *start1 =0;
         ++start1;
         ++start2;
      }
      return temp;
   }


   Image Image::operator!(){
      Image temp(*this);
      Image::iterator start = temp.begin(), end = temp.end();
      while (start != end) {
         *start = 255 - *start;
         ++start;
      }
      return temp;
   }

   Image Image::operator/(const Image & rhs)const{
      Image temp = rhs;
      Image::iterator start1 = temp.begin(), end1 = temp.end();
      Image::iterator start2 = this->begin();
      while (start1 != end1) {
         if (*start1==255) *start1 = *start2;
            else *start1 = 0;
         ++start1;
         ++start2;
      }
      return temp;
   }

   Image Image::operator*(int i)const{
      Image temp(*this);
      Image::iterator start = temp.begin(), end = temp.end();
      while (start != end) {
         if (*start>i) *start = 255;
         ++start;
      }
      return temp;
   }

}