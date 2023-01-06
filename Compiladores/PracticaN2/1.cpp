#include<iostream>
using namespace std;
const string estados[]={"Estado 1","Estado 2","Estado 3"}; 
void reconocer_diagrama(){
    string input;
    cout<<"Ingrese cadena:"<<endl;
    cin>>input;
    //cout<<estados[0]<<endl;
    if(isdigit(input[0])||input[0]==' '|| input[0]=='\0' ){
        cout<<estados[1]<<endl;
        cout<<"No reconocido"<<endl;
        return ;
    }
    
    int i=0;
    while(input[i]!='\0'){
        int val=(int) input[i];
        if((val>=97 && val<=122) ||(val>=65 && val<=90)||isdigit(input[i]) ){
            cout<<i+1<<") "<<estados[2]<<"\t"<<input[i]<<endl;
            i++;
        }
    
        else {
            cout<<"No se reconocio la cadena"<<endl;
            return;

        }

    }
    cout<<"Se  reconocio la cadena "<<input<<endl;
}
int main(){
    reconocer_diagrama();
    return  0;
}