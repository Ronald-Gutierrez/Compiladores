#include<iostream>
#include<string>

using namespace std;
int main()
{

    string frase;
    cout<<" Ingrese la frase"<<endl;
    getline(cin,frase);
    int estado=1; 
    int i=0;    
    int count=0;
    while(i < frase.size())
    {
        if(estado==1)
        {
            if(isdigit(frase[i])==1) 
                estado=2;
            else if((frase[i]>=65  && frase[i]<=90) || (frase[i]>=97  && frase[i]<=122))
                estado=3;
            else
                estado=2;
        }
        else if(estado==2)
            count++;
        else if(estado==3)
        {
            if((frase[i]>=65  && frase[i]<=90) || (frase[i]>=97  && frase[i]<=122))
                estado=3;
            else if (isdigit(frase[i])==1)
                estado=3;
            else 
                count++;
        }
        i++;
    }
    
    if(estado == 3)
        cout<<"se reconocio"<<endl;
    else if (count != 0 || estado == 2|| estado == 1)
        cout<<"Error";
    return 0;
}