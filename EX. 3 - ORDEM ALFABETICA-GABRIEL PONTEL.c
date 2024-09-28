#include <stdio.h>
#include <string.h>

void ler_vet_string(char mat[3][50])
{
    printf("Digite os nomes:\n");
    int i;
    for(i=0; i<3; i++)
    {
        fgets(mat[i],50,stdin);
        if(mat[i][strlen(mat[i])-1]==10)
            mat[i][strlen(mat[i])-1]='\0';
    }
}

int achar_menor(char mat[3][50], int inicio)
{
    int i,pos;
    char menor[50];
    strcpy(menor,mat[inicio]);
    pos = inicio;
    for(i=pos;i<3;i++)
    {
        if(strcmp(menor,mat[i])>0)
        {
            strcpy(menor,mat[i]);
            pos=i;
        }
    }
    return pos;
}

void ordem_alfabetica(char mat[3][50])
{
    char aux[50];
    int i,pos;
    for(i=0;i<2;i++)
    {
        pos=achar_menor(mat,i);
        strcpy(aux,mat[i]);
        strcpy(mat[i],mat[pos]);
        strcpy(mat[pos],aux);
    }
}

void apresentar_mat(char mat[3][50])
{
    int i;
    printf("A ordem alfabetica:\n");
    for(i=0; i<3; i++)
        printf("%d - %s\n", i+1, mat[i]);
}
void main()
{
    char mat[3][50];
    ler_vet_string(mat);
    ordem_alfabetica(mat);
    apresentar_mat(mat);
}
