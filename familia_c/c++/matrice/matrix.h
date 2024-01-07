#pragma once
class Matrix {
    int lines;
    int columns;
    int** mat;
public:
    Matrix(int lines);//matrice patratica
    Matrix(int lines, int columns);
    Matrix(int array[],int arraySize, int lines, int columns, bool byRow=0);
    Matrix(Matrix& m);
    ~Matrix();
    void Print();
    Matrix operator+(Matrix &m); //folosim referinta pt a nu mai apela constructorul de copiere
    Matrix operator-(Matrix& m);
    Matrix operator*(int x);
    Matrix operator*(Matrix& m);
    Matrix operator=(const Matrix& m);
    bool operator==(Matrix& m);
    Matrix operator!();
};