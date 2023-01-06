#include <stdio.h>
#include <conio.h>
#include <string.h>
char preanalisis;
void parea(int);
void A();
void B();
void C();
void error();
void S()
{
    if (preanalisis == 'y')
    { 
        parea('y'); 
        S(); 
    }
    else if (preanalisis == 'a')
    { 
        A(); 
        B(); 
        parea('a'); 
    }
    else if (preanalisis == 'c')
    { 
        C();
        B(); 
        parea('a'); 
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
void C()
{
    if (preanalisis == 'c')
        parea('c');
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

    /* RECONOCE:

    S --> yS
    S --> A B a
    S --> C B a
    A --> a
    B --> b
    C --> c

    yaba
    ycba
    aba
    cba
    yyy...yyaba
    yyy...yycba
    
    */

}