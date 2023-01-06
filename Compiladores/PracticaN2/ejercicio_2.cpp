
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string frase;
    cout<<" Ingrese la frase"<<endl;
    getline(cin,frase);

    int Tabla[3][3]={{2, 3, 0}, {0, 0, 0}, {3, 3, 1}};
    int Estado=0;
    int EstadoC=0;
    int entrada=0;
    int i=0;
    while (i <= frase.size())
    {
        if (entrada != 1 && isdigit(frase[i])==1 )
        {
            entrada=0;
            EstadoC=1;
        }
        else if ((frase[i]>=65  && frase[i]<=90) || (frase[i]>=97  && frase[i]<=122))
        {
            entrada = 1;
            EstadoC=2;
        }
        else if (frase[i]=='\0'|| (frase[i]>=65  && frase[i]<=90) || (frase[i]>=97  && frase[i]<=122)|| entrada == 1 ){
            entrada = 2;
            EstadoC=2;
        }
        else {
            cout<<"Error"<<endl;
            break;
        }
        
        Estado = Tabla[EstadoC][entrada];

        if (Estado == 0)
        {
            cout<<"Error";
            break;
        }

        else if (Estado == 1)
        {
            cout<<"se reconocio";
            break;
        }
        i++;
    }
  
    return 0;
}