#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{

    fstream inf;
    inf.open("doc.txt");
    int filas=2;
    int colm=2;
    int tabla[filas][colm];
    for(int i=0; i<filas; i++)
    {
        for(int j=0; j<colm; j++)
        {
            archivo>>tabla[i][j];
        }
    }
    for(int i=0; i<filas; i++){
        for(int j=0; j<colm; j++)
        {
            cout <<tabla[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}