#include <iostream>
using namespace std;


void E_clausura(int* estados,int n,int* R,int &na)
{
    STACKPTR pila;
    //Inicializar E_clausura(R) con R
    init(pila);
    na=0;
    // Apilar todos los estados de R
    for(int i=0;i<n;i++)
    {
        push(pila,estados[i]);
        R[i]=estados[i];
        na++;
    }
    //Mientras la pila no es vacia Hacer
    //Desapilar r de la cima

    while(!empty(pila)) 
    {
        int t=pop(pila);
        //Por cada transición (r,ϵ,s) Hacer
        for(int k=0;k<AFN_MAX;k++)
            if(aristas[t][k]==EPSILON) 
            {
                int i=0;
                 //Si s no esta en E_clausura(R) entonces
                while(i<na && k!=R[i]) i++;
                if(i==na) 
                {
                    //Agregar s a E_clausura(R)
                    R[na++]=k;
                    // Apilar s.
                    push(pila,k);
                }
            }
    }
}

int main()
{
    return 0;
}