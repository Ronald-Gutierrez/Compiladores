#include <iostream>
#include <string>
using namespace std;

int main()
{
    string frase;
    cout<<" Ingrese el numero"<<endl;
    getline(cin,frase);

    int i=0;
    int count=0;
    while(i < frase.size() && count == 0)
    {
        //condicionamos para ASCII de '-' , '.'  y nmero.
        if(frase[0]==45 || frase[i]== 46 || isdigit(frase[i]) != 0)
            i++;
        else 
            count=1;
    }

    if(count==0)
        cout<<" Si se reconocio"<<endl;
    else
        cout<<" No se reconocio"<<endl;

    return 0;
}