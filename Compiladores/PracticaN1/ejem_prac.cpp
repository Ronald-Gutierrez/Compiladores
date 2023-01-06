#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string.h>
using namespace std;


int main()
{
    string linea;
    string texto;
    ifstream arhivo("doc.txt");
    char buscar[50]="int";

    while(getline(arhivo,linea))
    {
        texto=texto+linea;
    }
    int x=0,z=0,w=0;
    int validar=0;

    while(texto[x] != '\0') x++;
    while(buscar[w] !='\0') w++;

    for(int i=0;i<x;i++)
    {
        z=0;
        while(buscar[z] != '\0')
        {
            if(buscar[z] == texto[i+z]) validar = validar+1;
            z++;
        }
        if(validar == w) cout<<"se encontro"<<endl;

        else validar=0;

    }
    if(validar != w) cout<<"No se encontro nada"<<endl;

    return 0;
}