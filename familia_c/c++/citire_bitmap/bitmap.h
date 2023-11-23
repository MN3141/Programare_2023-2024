#pragma once
#include<string>
using namespace std;
typedef unsigned char byte;
class Bitmap{
    string fileName;
    byte rgbCode[3];
    byte offset;
    char *imageCode;
    public:
    Bitmap(string fileName="");
    string getFileName();
    void readImage();
};