#include<iostream>
#include<fstream>
#include <string>
#include "Image.h"

using namespace std;
using namespace NDXMYR001;

int main(int argc, char *argv[])
{
    string a1, a2, a3;
    a1 = argv[1];
    a2 = argv[2];
    if(!a1.compare("-a"))//Add operation
    {
        a3 = argv[3];
        Image* im1 = new Image(a2);
        Image* im2 = new Image(a3);
        Image* im3;
        im3 = *im1 + *im2;
        im3->write(a2);
    }
    else if(!a1.compare("-s"))//Subtract operation
    {
        a3 = argv[3];
        Image* im1 = new Image(a2);
        Image* im2 = new Image(a3);
        Image* im3;
        im3 = *im1 - *im2;
        im3->write(a2);
    }
    else if(!a1.compare("-i"))//Invert operation
    {
        Image* im1 = new Image(a2);
        Image* im3;
        im3 = !*im1;
        im3->write(a2);
    }
    else if(!a1.compare("-l"))//mask operation
    {
        a3 = argv[3];
        Image* im1 = new Image(a2);
        Image* im2 = new Image(a3);
        Image* im3;
        im3 = (*im1)/(*im2);
        im3->write(a2);
    }
    else if(!a1.compare("-t"))//Threshold
    {
        int i = stoi(argv[3]);
        Image* im1 = new Image(a2);
        Image* im3;
        im3 = (*im1)*i;
        im3->write(a2);
    }
    return 0;
}
