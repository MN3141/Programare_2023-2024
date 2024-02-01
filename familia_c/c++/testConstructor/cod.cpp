#include<iostream>
using namespace std;
class T{
    protected: int x,y; //folosind atributul protected,x si y pot fi accesati de clasele derivate din T
    public:
    T(){this->x=0;this->y=0;cout<<"Constructor implicit T:"<<endl;}
    T(T &var){this->x=var.x;this->y=var.y;cout<<"Constructor de copiere T:"<<endl;}
    ~T(){cout<<"Destructor T:"<<endl;}
    void setValues(int x,int y)
    {
        this->x=x;
        this->y=y;
    }
    friend T Ceva(T &var);
    friend T Ceva2(T var);
    virtual void Afisare()
    {
        cout<<"Afisare de la clasa T:"<<"**"<<endl;
    }
    void operator=(T var)
    {
        cout<<"Redefinire operator atribuire:"<<endl;
        this->x=var.x;
        this->y=var.y;
    }
    friend istream &operator>>(istream &flux, T &var)
    {
        flux>>var.x;
        flux>>var.y;
        return flux;
        //OBS:atributul friend e necesar deoarece putem sa mentinem ordinea operanzilor dupa bunul plac
        //    (putand astfel sa citim cascadat);
        //    daca nu foloseam friend,atunci ordinea ar fi fost fixa:T &var la stanga musai
    }
    /*istream &operator>>(T &var)
    {
        numai asa s-ar putea fara atributul friend 
    } */
};
T Ceva(T &var)
{
    cout<<"Suntem in corpul functiei 1:"<<endl;
    T temp;
    temp.x=var.x*2;
    temp.y=var.y*10;
    return temp;
}
T Ceva2(T var)
{
    cout<<"Suntem in corpul functiei 2:"<<endl;
    T temp;
    temp.x=var.x*var.x;
    temp.y=var.y*var.y;
    return temp;
}
class TDeriv0 :public T{
    int z;
    T varT;
    public:
    TDeriv0(){this->z=-1;cout<<"Constructor implicit TDeriv0:"<<endl;}
    //daca nu mentionam constructorul clasei de baza
    //atunci se va apela automat cel implicit al clasei de baza
    TDeriv0(int x,int y,int z=10) :T(){
        this->x=-x;this->y=y;this->z=z;
        cout<<"Constructor explicit TDeriv0:"<<endl;
    }
    void Afisare()
    {
        cout<<"Afisare de la clasa TDeriv0:"<<"##"<<endl;
    }
    ~TDeriv0(){cout<<"Destructor TDeriv0:"<<endl;}
};
int main()
{
    T var0,var1;
    var0.setValues(10,20);
    cout<<"VAR1:"<<endl;
    var1=Ceva(var0);
    cout<<"VAR2:"<<endl;
    T var2=Ceva(var1); //constructor copiere
    cout<<"VAR3:"<<endl;
    T var3=var1;
    var3=Ceva2(var1);  //redefinire operator atribuire
                       //se vor apela 2 constructori de copiere:
                       //unul pt transmiterea obiectului var1 in functie
                       //unul pt var3 de pe linie T var3=var1
    //se apeleaza 6 destructori:4 pt cele 4 obiecte si 2 obiectele temporare din secventa var3=Ceva2(var1)             
    cout<<"================================"<<endl;
    cout<<"Teste pointer:"<<endl;
    T *pVar=NULL;
    pVar=new T;
    pVar->Afisare();
    delete pVar;
    pVar=new TDeriv0;
    pVar->Afisare();
    delete pVar;
    return 0;
    
}