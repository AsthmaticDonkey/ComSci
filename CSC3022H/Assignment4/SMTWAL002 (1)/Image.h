#ifndef IMAGE_H
#define IMAGE_H

#include <memory>

namespace SMTWAL002{
class Image
{
   private:
   int width, height;
   std::unique_ptr<unsigned char[]> data;

   public:
   class iterator{
      private:
      unsigned char *ptr;

      public:
      //Constructors/Destructors
      iterator(u_char *p);
      iterator( const iterator & rhs) : ptr(rhs.ptr) {};

      //Operators
      iterator & operator=(const iterator & rhs);
      unsigned char & operator*();
      bool operator!=(const iterator & rhs);
      iterator & operator++();
      iterator & operator--();

   };
   friend iterator;
   const iterator begin(void) const { return iterator(data.get());};
   const iterator end(void) const { return iterator(&data.get()[(width)*(height)]+1);};

   //Operators
   Image operator+(Image & rhs);
   Image operator-(const Image & rhs)const;
   Image operator!();
   Image operator/(const Image & rhs)const;
   Image operator*(int i)const;

   //Functions
   Image(std::string s);
   Image(const Image & im);
   ~Image();
   int getWidth();
   int getHight();
   void write(std::string s);
};
}
#endif