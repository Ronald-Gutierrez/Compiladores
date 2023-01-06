#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
    FILE *arch=fopen("doc.txt","rt");
    if (arch==NULL)
        exit(1);
    char caracter = fgetc(arch);
    while (!feof(arch))
    {
        printf("%c",caracter);
        caracter = fgetc(arch);
    }
    fclose(arch);
    getch();
    return 0;
}

    int c,i;

    FILE *arch=fopen("doc.txt","rt");
    if (arch==NULL)
        exit(1);
    char caracter = fgetc(arch);
    while (!feof(arch))
    {
        caracter = fgetc(arch);
    }
    