#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

// DEFINIENDO LOS TOKENS
#define MAYOR '>'
#define MENOR '<'
#define IGUAL '='
#define EXCLAMACION '!'
#define PUNTOYCOMA ';'
#define COMA ','
#define CORCHETE_A '['
#define CORCHETE_C ']'
#define PARI '('
#define PARE ')'
#define PR 256
#define NUM 257
#define MAYORIGUAL 258
#define WHILE 259
#define IF 260
#define MENORIGUAL 261
#define IGUALIGUAL 262
#define DIFERENTE 263
#define SUMA '+'
#define RESTA '-'
#define PRODUCTO '*'
#define DIVISION '/'

int scaner();
void mostrar(int);
int espalres();

FILE *f;
char lexema[80];

void main(int n, char *pal[])
{
    int token;
    f=stdin; //entrada estandar del teclado
    if(n==2) //si se especifico un archivo de lectura
    {
        f=fopen(pal[1],"rt"); //lectura modo texto
        if(f==NULL)
            f=stdin;
    }
    if(f==stdin) //la lectura sera desde la entrada estandar
        printf("Ingrese texto ........ termine con Ctrl c \n");
    while(1)
    {
        token=scaner();
        if(token==EOF) break;
        mostrar(token);
    }
    if(f !=stdin) // si la entrada fue de un archivo
        fclose(f); // entonces cerrar el archivo.
}//fin del main

int scaner()
{
    int c;
    int i;
    do c=fgetc(f); while(isspace(c)); //ignora blancos
    if(c==EOF) 
        return EOF;
    if(isalpha(c)) //regla del ID
    {
        i=0;
        do{
            lexema[i++]=c;
            c=fgetc(f);
        } while(isalnum(c)||c=='_');
        lexema[i]=0;
        ungetc(c,f); //se devuelve c al flujo de entrada
        i=espalres(); // verifica si es palabra reservada
            // WHILE , IF
        if(i>=0)
            return i;
        return PR; // se trata de un PR
    }
    if(isdigit(c)) //regla del NUM
    {
        i=0;
        do{
            lexema[i++]=c;
            c=fgetc(f);
        }while(isdigit(c));
        lexema[i]=0;
        ungetc(c,f);
        return NUM;
    }
    //regla de PUNTOYCOMA y PARI
    if((c==',')||(c==';')||(c=='(')||(c==')') || (c=='[')|| (c==']')
        ||(c=='+')||(c=='-') ||(c=='*') ||(c=='/')) 
        return c; 

    if(c=='>') //regla de ">" o ">="
    {
        c=fgetc(f);
        if(c=='=') //return MAYORIGUAL
        { 
            lexema[0]='>'; 
            lexema[1]='='; 
            lexema[2]= 0;
            return MAYORIGUAL;
        }
        ungetc(c,f);
        return MAYOR; //return MAYOR
    }
    if(c=='<') //regla de "<" o "<="
    {
        c=fgetc(f);
        if(c=='=') //return MENORIGUAL
        { 
            lexema[0]='<'; 
            lexema[1]='='; 
            lexema[2]= 0;
            return MENORIGUAL;
        }
        ungetc(c,f);
        return MENOR; //return MENOR
    }
    if(c=='=') //regla de " =" o "=="
    {
        c=fgetc(f);
        if(c=='=') //return IGUALIGUAL
        { 
            lexema[0]='='; 
            lexema[1]='='; 
            lexema[2]= 0;
            return IGUALIGUAL;
        }
        ungetc(c,f);
        return IGUAL; //return IGUAL
    }
    if(c=='!') //regla de "1" o "1="
    {
        c=fgetc(f);
        if(c=='=') //return DIFERENTE
        { 
            lexema[0]='!'; 
            lexema[1]='='; 
            lexema[2]= 0;
            return DIFERENTE;
        }
        ungetc(c,f);
        return EXCLAMACION; //return EXCLAMACION
    }

}//fin de scaner
/*    */
int espalres()
{
    if(strcmp(lexema,"while")==0) return WHILE;
    if(strcmp(lexema,"if")==0) return IF;
    return -1;
}
void mostrar(int token)
{
    switch(token)
    {
    case PR: printf("token = PR [%s] \n",lexema); break;
    case NUM: printf("token = NUM [%s] \n",lexema); break;
    case IGUALIGUAL: printf("token = IGUALIGUAL [%s] \n",lexema); break;
    case MAYORIGUAL: printf("token = MAYORIGUAL [%s] \n",lexema); break;
    case MENORIGUAL: printf("token = MENORIGUAL [%s] \n",lexema); break;
    case DIFERENTE: printf("token = DIFERENTE [%s] \n",lexema); break;
    case EXCLAMACION: printf("token = EXCLAMACION [%c] \n",lexema); break;
    case WHILE: printf("token = WHILE [%s] \n",lexema); break;
    case IF: printf("token = IF [%s] \n",lexema); break;
    case PARI: printf("token = PARI [%c] \n",token); break;
    case PARE: printf("token = PARE [%c] \n",token); break;
    case CORCHETE_C: printf("token = CORCHETE_C [%c] \n",token); break;
    case CORCHETE_A: printf("token = CORCHETE_A [%c] \n",token); break;
    case MAYOR: printf("token = MAYOR [%c] \n",token); break;
    case MENOR: printf("token = MENOR [%c] \n",token); break;
    case IGUAL: printf("token = IGUAL [%c] \n",token); break;
    case SUMA: printf("token = SUMA [%c] \n",token); break;
    case RESTA: printf("token = RESTA [%c] \n",token); break;
    case PRODUCTO: printf("token = PRODUCTO [%c] \n",token); break;
    case DIVISION: printf("token = DIVISION [%c] \n",token); break;
    case PUNTOYCOMA: printf("token = PUNTOYCOMA [%c] \n",token); break;
    case COMA: printf("token = COMA [%c] \n",token); break;
    }
}