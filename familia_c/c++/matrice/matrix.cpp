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
Matrix:: Matrix(int array[],int arraySize, int lines, int columns, bool byRow)
{
    int index = 0;//indexare tablou
    this->lines = lines;
    this->columns = columns;
    this->mat = new int* [lines];
    for (int i = 0; i <lines; i++)
    {
        this->mat[i] = new int[columns];
        for (int j = 0; j < columns; j++)
        {
            this->mat[i][j] = 0;//setare matrice
        }
    }
    int n = lines * (!byRow) + columns * byRow;
    int m = columns * (!byRow) + lines * byRow;
    //in functie de parametrul byRow i poate fi indexul pt linie sau coloana;analor pt j
    for(int i = 0;i <n;i++)
    {
        for (int j = 0;j <m && index<arraySize;j++)
        {
            this->mat[i*(!byRow)+j*byRow][j*(!byRow)+i*byRow] = array[index];//efectuam acest calcul ciudat la indexare pt a comuta intre parcurgerea pe linie sau coloane
            index++;
        }
    }
}
Matrix::Matrix(Matrix& m)
{
    this->lines = m.lines;
    this->columns = m.columns;
    this->mat = new int* [this->lines];
    for (int i = 0;i < this->lines;i++)
    {
        this->mat[i] = new int[this->columns];
        for (int j = 0;j < this->columns;j++)
            this->mat[i][j] =m.mat[i][j];
    }
}
Matrix:: ~Matrix()
{
    delete mat;
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
        printf("\n");
        int v[] = { -1 };
        Matrix error(v, 1, 1, 1);
        return error;
    }
    Matrix rez(this->lines, this->columns);
    for (int i = 0; i < rez.lines; i++)
    {
        for (int j = 0; j < rez.columns; j++)
           rez.mat[i][j] = this->mat[i][j] + m.mat[i][j];
    }
    return rez;
}
Matrix Matrix ::operator-(Matrix& m)
{
    if ((this->lines != m.lines) || (this->columns != m.columns))
    {
        printf("%s", "Can't add matrices of different forms!");
        printf("\n");
        int v[] = {-1};
        Matrix error(v, 1, 1, 1);
        return error;
    }
    Matrix rez(this->lines, this->columns);
    for (int i = 0; i < rez.lines; i++)
    {
        for (int j = 0; j < rez.columns; j++)
            rez.mat[i][j] = this->mat[i][j] - m.mat[i][j];
    }
    return rez;
}
Matrix Matrix::operator*(int x)
{
    Matrix rez = *this;
    for (int i = 0;i < this->lines;i++)
    {
        for (int j = 0;j < this->columns;j++)
            rez.mat[i][j] = rez.mat[i][j] * x;
    }
    return rez;
}
Matrix Matrix::operator*(Matrix& m)
{
    if (this->columns != m.lines)
    {
        printf("%s", "Can't multiply matrices of different forms!");
        printf("\n");
        int v[] = { -1 };
        Matrix error(v, 1, 1, 1);
        return error;
    }
    Matrix rez(this->lines,m.columns);
    for (int i = 0;i < rez.lines;i++)
    {
        for (int j = 0;j < rez.columns;j++)
        {
            for (int k = 0;k < m.columns;k++)
                rez.mat[i][j] = rez.mat[i][j] + this->mat[i][k] * m.mat[k][j];
        }
    }
    return rez;
}
Matrix Matrix::operator=(const Matrix& m)
{
    delete this->mat;
    this->lines = m.lines;
    this->columns = m.columns;
    this->mat = new int* [this->lines];
    for (int i = 0;i < this->lines;i++)
    {
        this->mat[i] = new int[this->columns];
        for (int j = 0;j < this->columns;j++)
            this->mat[i][j] = m.mat[i][j];
    }
    return *this;
}
bool Matrix::operator==(Matrix& m)
{
    if ((this->lines != m.lines) || (this->columns != m.columns))
    {
        return 0;
    }
    for (int i = 0;i < this->lines;i++)
    {
        for (int j = 0;j <this->columns;j++)
        {
            if (this->mat[i][j] != m.mat[i][j])
                return 0;
        }
    }
    return 1;
}
Matrix Matrix ::operator!()
{
    Matrix temp = *this;
    delete this->mat;
    swap(this->lines, this->columns);
    this->mat = new int* [this->lines];
    for (int i = 0;i < this->lines;i++)
    {
        this->mat[i] = new int[this->columns];
        for (int j = 0;j < this->columns;j++)
            this->mat[i][j] = temp.mat[j][i];
    }
    return *this;
}