#include "bitmap.h"
#include<fstream>
#include<iostream>
using namespace std;
Bitmap::Bitmap(string fileName)
{
    this->fileName = fileName;
    this->rgbCode[0]= 0;
    this->rgbCode[1] = 0;
    this->rgbCode[2] = 0;
     this->offset = 0;
}
string Bitmap::getFileName()
{
    return this->fileName;
}
void Bitmap::readImage()
{
    fstream fin(this->fileName);
    //========================= 
    fin.seekg(0, fin.end); 
    int length = fin.tellg();
    fin.seekg(0, fin.beg);      //taken from cpp.com
    imageCode = new char[length];
    fin.read(imageCode, length);
    //===========================
    bool found = 0;
    for (int i = 3; i < length && found==0; i++)
    {
        if (*(imageCode + i)>0)
        {
            this->offset = *(imageCode + i);
                found = 1;
        }
    }
    cout<<offset<<endl;
    rgbCode[0] = *(imageCode + offset);
    rgbCode[1] = *(imageCode + offset+1);
    rgbCode[2] = *(imageCode + offset+2);
    *(imageCode + offset) = 125;
    fstream fout("1pixel_prelucrare.bmp");
    fout.write(imageCode, length);
  
}