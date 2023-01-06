#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string.h>
using namespace std;

char letras[] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v',
                'w','x','y','z'};

void cifrado(char *txt);
void descifrado(char *txt);

int main()
{
    string linea;
    string texto;
    ifstream arhivo("doc.txt");
    while(getline(arhivo,linea)) texto=texto+linea+"\n";
    char txt[500];
    for(int i=0; i<=texto.size();i++) txt[i]=texto[i];

    cifrado(txt);
    descifrado(txt);
    
    return 0;
}

void cifrado(char *txt){

    for(int i=0;i<strlen(txt);i++)
    {
        for(int j=0;j<strlen(letras);j++)
        {
            if(txt[i] == letras[j])
            {
                int aux=(j+3)%26;
                txt[i]=letras[aux];
                break;
            }
        }
    }
    cout<<"El texto cifrado es: "<<"\n"<<txt<<endl;
}

void descifrado(char *txt){
    for(int i=0;i<strlen(txt);i++){
        for(int j=0;j<strlen(letras);j++){
            if(txt[i] == letras[j])
            {
                int aux;
                if((j-3)<0) aux=26+(j-3);
                else aux=(j-3)%26;

                txt[i]=letras[aux];
                break;
            }
        }
    }
    cout<<"El texto descifrado es: "<<"\n"<<txt<<endl;
}