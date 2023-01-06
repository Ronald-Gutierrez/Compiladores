#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) 
            return false;
    }
    return true;
}

int main()
{   stack<int> pila;
    string  cad;
    int val_1;
    int val_2;
    float resultado;
    cout<<"--ingresar la cadena postfija-- \n";
    for(int i=0;i<3;i++){
        cin>>cad;
        if(isNumber(cad))
        {
            pila.push(stoi(cad));
        }
        else if(cad=="+") 
        {
            val_1=pila.top();
            pila.pop();
            val_2=pila.top();
            pila.pop();
            resultado = val_2+val_1;
            pila.push(resultado);
        }
        else if(cad=="-") 
        {
            val_1=pila.top();
            pila.pop();
            val_2=pila.top();
            pila.pop();
            resultado = val_2-val_1;
            pila.push(resultado);
        }
        else if(cad=="*") 
        {
            val_1=pila.top();
            pila.pop();
            val_2=pila.top();
            pila.pop();
            resultado = val_2*val_1;
            pila.push(resultado);
        }
        else if(cad=="/") 
        {
            val_1=pila.top();
            pila.pop();
            val_2=pila.top();
            pila.pop();
            resultado = val_2/val_1;
            pila.push(resultado);
        }
    }
    cout<<"--Resultado en mi pila-- \n";
    cout<<pila.top();
    return 0;
}