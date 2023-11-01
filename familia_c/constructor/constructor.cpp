//Despre constructori si destructori
#include <iostream>
#include<string.h>
using namespace std;
class Student {
	string nume;
	float medie;
public:
	Student(string s="ION",float nr=4) //daca la apelare nu se introduc parametrii
	{									// atunci e ca un constructor default
		nume = s;
		medie = nr;
	}
	Student(Student &x) //constructor copiere
	{					//folosit ca masura de siguranta cand lucram cu obiecte dinamice
		nume = x.nume;
		medie = x.medie;
	}
	~Student()
	{
		cout << "GATA JOACA " <<nume<<'!'<<endl;
	}
	void Indexare(float puncte)
	{
		medie = medie + 2;
		if (medie > 10)
			cout << "PARAOLIMPIC!" << endl;
	}
	void Afisare()
	{
		cout << "NUME:" << nume << endl;
		cout << "MEDIE:" << medie << endl;
		cout << "-----------------" << endl;
	}
	bool Picat()
	{
		bool picat = 0;
		if (medie < 5)
			picat = 1;
		return picat;
	}
	bool areBursa()
	{
		bool ok = 0;
		if (medie >= 8)
			ok = 1;
		return ok;
	}
};
int main()
{
	Student x, y("Ciuca Norris", 11),z("Ghita");
	x.Afisare();
	y.Afisare();
	z.Afisare();
	Student* p;
	p = new Student("Matei", 4.1);
	p->Afisare();
	delete p;
}
