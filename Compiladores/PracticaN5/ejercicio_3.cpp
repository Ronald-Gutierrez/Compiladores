#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string>
#define MAS '+'
#define MENOS '-'
#define MULT '*'
#define DIV '/'
#define NUM 256
#define FIN -1
char lexema[80];
int tok;
std::string cadena;
void parea(int);
void error();
void Resto();
void Term();
int scanner();
void Exp()
{   
    Resto(); 
}
void Resto()
{
    Term();
    if (tok == MAS)
    { 
        parea(MAS);
        Term();
        printf("+");
        cadena=cadena+" + "+" ";
        Resto();
    }
    else if (tok == MENOS)
    { 
        parea(MENOS);
        Term();
        printf("-");
        cadena=cadena+" - "+" ";
        Resto();
    }
    else if (tok == MULT)
    { 
        parea(MULT);
        Term();
        printf("*");
        cadena=cadena+" * "+" ";
        Resto();
    }
    else if (tok == DIV)
    { 
        parea(DIV);
        Term();
        printf("/");
        cadena=cadena+" / "+" ";
        Resto();
    }
    else //cadena vacia
        ;
}
void Term()
{
    if (tok==NUM)
    { 
        printf("%s",lexema);
        cadena=cadena+lexema+' ';
        parea(NUM); 
    }
    else if(tok =='(')
    {
        parea('(');
        Exp();
        parea(')');
    }

}

void error()
{
    printf("Error de sintaxis");
}
void parea(int t)
{
    if (tok==t)
        tok=scanner();
    else
        error();
}
int scanner()
{
    int c,i;
    do c=getchar(); 
    while(c==' ');
    if (c=='\n')
        return FIN;
    if (c==MAS || c==MENOS || c==MULT || c==DIV || c=='(' || c==')')
        return c;
    if(isdigit(c))
    {
        i=0;
        do { lexema[i++]=c; 
            c=getchar();
        }while(isdigit(c));
        lexema[i]=0;
        ungetc(c,stdin);
        return NUM;
    }
}
int main()
{
    printf("--Ingrese la expresion a evaluar--\n");
    tok=scanner();
    Exp();
}

