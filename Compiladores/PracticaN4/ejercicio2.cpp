#include<iostream>
#include<string>
#define ISNUM(X) X >='0' && X <='9'
using namespace std;

string cadena;
char preanalisis;
int pos= 0;
void Term();
void Resto();
void Parea(char t);
void Exp();

void error()
{
    cout<<"Error de sintaxis";
}

void Resto()
{
    if(preanalisis=='+')
    {
        Parea('+');
        Term();
        cout<<"+";
        Resto();
    }
    else if(preanalisis=='-')
    {
        Parea('-');
        Term();
        cout<<"-";
        Resto();
    }
    else if (preanalisis=='\n')
        Parea('\n');
    else 
        error();
}
void Exp()
{
    if(ISNUM(preanalisis))
    {
        cout<<"ORDEN POSTFIJO \n";
        Term();
        Resto();
    }
    else
        error();
}
void Parea(char t)
{
    if (preanalisis==t && pos < cadena.size()){
        pos++;
        preanalisis=cadena[pos];
    }
    else
        error();
}
void Term()
{
    if(ISNUM(preanalisis))
    {
        cout<<preanalisis;
        Parea(preanalisis);
    }
    else
        error();
}
int main()
{
    cout<<"INGRESE LA CADENA A RECONOCER \n"; 
    cin>>cadena;
    cadena=cadena+'\n';
    preanalisis=cadena[0];
    Exp();
    cout<<endl;
    return 0;
}