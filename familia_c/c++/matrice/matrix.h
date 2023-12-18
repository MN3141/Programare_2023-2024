#pragma once
class Matrix {
    int lines;
    int columns;
    int** mat;
public:
    Matrix(int lines);//matrice patratica
    Matrix(int lines, int columns);
    void Print();
    Matrix operator+(Matrix &m); //folosim referinta pt a nu mai apela constructorul de copiere
};
//de implementat operatorii:=,==,+,-,transpusa