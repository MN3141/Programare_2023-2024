#include<iostream>
#include "matrix.h"
using namespace std;
Matrix::Matrix(int lines)
{
    this->lines = lines;
    this->columns = lines;
    this->mat = new int* [lines];
    for (int i = 0; i < lines; i++)
    {
        this->mat[i] = new int[lines];
        for(int j=0;j<lines;j++)
        this->mat[i][j] = 0;
    }
}
Matrix::Matrix(int lines, int columns)
{
    this->lines = lines;
    this->columns = columns;
    this->mat = new int* [lines];
    for (int i = 0; i < lines; i++)
    {
        this->mat[i] = new int[columns];
        for (int j = 0; j < columns; j++)
        {
            this->mat[i][j] = 0;
        }
    }
}
void Matrix::Print()
{
    for (int i = 0; i < this->lines; i++)
    {
        for (int j = 0; j < this->columns; j++)
        {
            cout << this->mat[i][j] << ' ';
        }
        cout << endl;
    }
}
Matrix Matrix::operator+(Matrix &m)
{
    if ((this->lines != m.lines) || (this->columns!=m.columns))
    {
        printf("%s", "Can't add matrices of different forms!");
        return -1;
    }
    Matrix rez(this->lines, this->columns);
    for (int i = 0; i < rez.lines; i++)
    {
        for (int j = 0; j < rez.columns; j++)
           rez.mat[i][j] = this->mat[i][j] + m.mat[i][j];
    }
    return rez;
}