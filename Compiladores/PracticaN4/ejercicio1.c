#include <stdio.h>
#include <conio.h>
int preanalisis;
void parea(int);
void A();
void B();
void error();
void S()
{
    if (preanalisis == 'x')
    { 
        parea('x'); 
        S(); 
    }
    else if (preanalisis == 'a')
    { 
        A(); 
        B(); 
        parea('c'); 
    }
    else
        error();
}
void A()
{
    if (preanalisis == 'a')
        parea('a');
    else
        error();
}
void B()
{
    if (preanalisis == 'b')
        parea('b');
    else
        error();
}
void error()
{
    printf("Error de sintaxis");
}
void parea(int t)
{
    if (preanalisis==t)
        preanalisis=getchar();
    else
        error();
}
int main()
{
    printf("INGRESE LA CADENA A RECONOCER \n");
    preanalisis=getchar();
    S();

    /* RECONOCE 

    S --> x S
    S --> A B c
    A --> a
    B --> b

    xabc
    abc
    xxxxxxx...xxxabc
    */

}

