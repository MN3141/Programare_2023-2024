#include <iostream>
#include<string>
using namespace std;
class Student {
private:
    int varsta;
    int media;
    int id;
    string nume;
public:
    Student()
    {
        cout << "CONSTRUCTOR BAZA" << endl;
        this->nume = "Ciuca Norris";
        this->varsta = 22;
        this->media = 11;//paraolimpic
        this->id = 3141;
    }
    Student(string s,int age,int grade,int id)
    {
        this->nume = s;
        this->varsta = age;
        this->media = grade;
        this->id = id;
    }
    void Afisare()
    {
        cout << this->nume << " " << this->media << " " << this->varsta<<" "<< this->id;
    }
    ~Student()
    {
        cout << "Hasta la vista " << this->nume << "! "<<"DESTRUCTOR IN CLAS DE BAZA" ;
        cout << endl;
    }
};
class Caminist: public Student {
private:
    int camin;
    int nr_camera;
public:
    Caminist(): Student()
    {
        cout << "CONSTRUCTOR DERIVAT" << endl;
        this->camin = 1;//cel mai bun camin
        this->nr_camera = 303;//un dulap lipsa

    }
    Caminist(string s, int age, int grade, int id,int camin,int nr_camera) : Student(s,age,grade,id)
    {
        cout << "CONSTRUCTOR DERIVAT" << endl;
        this->camin = camin;
        this->nr_camera = nr_camera;

    }
    void Afis()
    {
        this->Afisare(); //alternativ,se puteau declara membrii din Student drept private
        cout << endl << this->camin << " " << this->nr_camera << endl;
    }
    ~Caminist()
    {
        cout << "Afara din camera " << this->nr_camera << "! "<<"DESTRUCTOR IN CLAS DE DERIVATA"<<endl;
    }
};
int main()
{
    Student x;
    Caminist a;
    Caminist b("ION", 18, 5, 2111, 4, 501);
    b.Afis();
}