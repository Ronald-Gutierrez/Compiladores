#include<iostream>
#include<string>
#define ISNUM(X) X >='0' && X <='9'
using namespace std;
int main()
{
    string cadena;
    cout<<"INGRESE LA CADENA A RECONOCER \n"; 
    cin>>cadena;
    cadena=cadena+'\n';

    cout<<cadena;
    return 0;
}