#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;


int main()
{
    string linea;
    string texto;
    ifstream arhivo("doc.txt");
    while(getline(arhivo,linea))
    {
        texto=texto+linea;
    }
    
    return 0;
}
