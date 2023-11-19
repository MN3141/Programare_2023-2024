/*
The current program is only works for positive integer numbers in base 10
*/
#include<iostream>
#include<math.h>
using namespace std;
int digits_BCD(int n) //determines the number of necessary bits
{                   //for the bcd array
    n=pow(2,n);
    int k=0;
    while(n)
    {
        n=n/10;
        k++;
    }
    return k*4;
}
int digits(int n) //determines the number of digits for
{               // the input number
    int ct=0;
    while(n)
    {
        n=n/10;
        ct++;
    }
    return ct;
}
class Num{
   private: int num_bits;
   public:
   Num()
   {
    num_bits=8; //default constructor
   }
    Num (int n)
    {
        num_bits=n;
    }
    private:
        char symbols[17]="0123456789ABCDEF";
        char* unsignb = new char[num_bits];
        char* bcd=new char[digits_BCD(num_bits)]; //packed BCD
        char* octal=new char[num_bits/3];
        char* hex=new char[num_bits/4];
    public:
        void printUnsign()
        {
        for(int i=0;i<num_bits;i++) //if there is an error in conversion
            cout<<*(unsignb+i);     //no further data can be printed on screen
        cout<<endl;                  //even tough they are not related to the class
        }
        void printBCD()
        {
        for(int i=0;i<digits_BCD(num_bits);i++) 
            cout<<*(bcd+i);
        cout<<endl;                  
        }
        void printOctal()
        {
        for(int i=0;i<num_bits/3;i++) 
            cout<<*(octal+i);
        cout<<endl;             
        }
        void printHex()
        {
        for(int i=0;i<num_bits/4;i++) 
            cout<<*(hex+i);
        cout<<endl;               
        }
        void toUnsign(int dec_num)
        {
            if(dec_num>=pow(2,num_bits))
            {
                cout<<"Your number is not in the range!"<<endl;
                return;
            }
            if(dec_num<0)
            {
                cout<<"Your number is signed!"<<endl;
                return;
            }
        for(int i=num_bits-1;i>=0;i--)
        {
           *(unsignb+i)=symbols[dec_num%2];
            dec_num=dec_num/2;
         }
        }
        void toOctal(int dec_num)
        {
            
            if(dec_num>=pow(8,num_bits))
            {
                cout<<"Your number is not in the range!"<<endl;
                return;
            }
            if(dec_num<0)
            {
                cout<<"Your number is signed!"<<endl;
                return;
            }
        for(int i=num_bits/3 -1;i>=0;i--)
        {
           *(octal+i)=symbols[dec_num%8]; 
            dec_num=dec_num/8;
         }
        }
        void toHex(int dec_num)
        {
            if(dec_num>=pow(16,num_bits/4))
            {
                cout<<"Your number is not in the range!"<<endl;
                return;
            }
            if(dec_num<0)
            {
                cout<<"Your number is signed!"<<endl;
                return;
            }
        for(int i=num_bits/4 -1;i>=0;i--)
        {
           *(hex+i)=symbols[dec_num%16]; //ASCII code for 0
            dec_num=dec_num/16;
         }
        }
    void toBCD(int dec_num)
    {
         if(dec_num>=pow(2,num_bits))
            {
                cout<<"Your number is not in the range!"<<endl;
                return;
            }
            if(dec_num<0)
            {
                cout<<"Your number is signed!"<<endl;
                return;
            }
        int num_digits=digits(dec_num);
        int k=num_digits*4;//4 bits per digit
        for(int i=0;i<num_digits;i++)
        {
            k=k-4;//we fill the array from right to left
            int digit=dec_num%10;
            for(int j=3;j>=0;j--)
            {
                *(bcd+k+j)=symbols[digit%2];
                digit=digit/2;
            }
            dec_num=dec_num/10;
        }
    }
};
int main()
{
  
}