#include <stdio.h>
#define TF 10
void ler_matriz(int mat[TF][TF])
{
    int i,j;
    for(i=0;i<TF;i++)
        for(j=0;j<TF;j++)
        {
            printf("MATRIZ[%d][%d] = ",i,j);
            scanf("%d", &mat[i][j]);
        }
}

int somar_coluna(int mat[TF][TF], int pos)
{
    int i,somar=0;
    for(i=0; i<TF; i++)
    {
        somar+=mat[i][pos];
    }
    return somar;
}

int somar_linha(int vet[TF])
{
    int i,somar=0;
    for(i=0;i<TF;i++)
        somar+=vet[i];
    return somar;
}

void apresentar_soma_linhas(int mat[TF][TF])
{
    int i;
    for(i=0;i<TF;i++)
    {
        printf("A soma da linha %d = %d\n",i, somar_linha(mat[i]));
    }
}

void apresentar_soma_colunas(int mat[TF][TF])
{
    int i;
    for(i=0;i<TF;i++)
    {
        printf("A soma da coluna %d = %d\n",i, somar_coluna(mat,i));
    }
}

int achar_Maior(int mat[TF][TF])
{
    int i=0;
    int maior;
    maior = somar_linha(mat[i]);
    for(i=1;i<TF;i++)
    {
        if(maior<somar_linha(mat[i]))
        {
            maior = somar_linha(mat[i]);
        }
    }
    return maior;
}

int achar_linha(int mat[TF][TF])
{
    int i,j,elem,linha;
    elem = mat[0][0];
    linha = 0;
    for(i=0;i<TF;i++)
        for(j=0;j<TF;j++)
        {
            if(elem<mat[i][j])
            {
                elem=mat[i][j];
                linha = i;
            }
        }
    return linha;
}

int achar_coluna(int mat[TF][TF])
{
    int i,j,elem,coluna;
    elem = mat[0][0];
    coluna = 0;
    for(i=0;i<TF;i++)
        for(j=0;j<TF;j++)
        {
            if(elem<mat[i][j])
            {
                elem=mat[i][j];
                coluna = j;
            }
        }
    return coluna;
}

int achar_menor(int mat[TF][TF], int *coluna)
{
     int i,j,elem,linha;

    elem = mat[0][0];
    *coluna = 0;
    linha = 0;
    for(i=0;i<TF;i++)
        for(j=0;j<TF;j++)
        {
            if(elem>mat[i][j])
            {
                elem=mat[i][j];
                linha = i;
                *coluna = j;
            }
        }
    return linha;
}

void main()
{
    int mat[TF][TF],col;

    ler_matriz(mat);
    apresentar_soma_linhas(mat);
    apresentar_soma_colunas(mat);
    printf("\nA soma linha com a maior soma = %d\n", achar_Maior(mat));
    printf("\nA linha do maior elemento: linha %d\n", achar_linha(mat));
    printf("\nA coluna do maior elemento: coluna %d\n", achar_coluna(mat));
    printf("\nO menor elemento tem a posicao: MATRIZ[%d][%d]\n", achar_menor(mat,&col), col);
}



