#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool isIn(char a, char p[], int n){
    for(int i = 0; i < n;i++){
        if(p[i]==a){
            return true;
        }
    }
    return false;
}

void reconocimiento(string &reco){
    if((reco[0]>=65  && reco[0]<=90) || (reco[0]>=97  && reco[0]<=122)){
        cout<<"Es una palabra: "<<reco<<endl;
        reco="";
    }else if(reco[0]>=48  && reco[0]<=57){
        cout<<"Es un numero: "<<reco<<endl;
        reco="";
    }else if(reco[0]>=33  && reco[0]<=47){
        cout<<"Es un caracter especial: "<<reco<<endl;
        reco="";
    }
}

int main(){
    string linea;
    string text="";
    ifstream arhivo("doc.txt");
    while(getline(arhivo,linea)){
        text=text+linea+"\n";
    }
    cout << text << endl;
    const int q=3;
    char sepa[q]={' ', '\t', '\n'};
    string reco="";
    for(int i=0;i<text.size();i++){
        if(isIn(text[i],sepa,q)){
            reconocimiento(reco);
        }else{
            reco+=text[i];
        }
    }
    return 0;
}