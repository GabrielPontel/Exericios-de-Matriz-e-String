#include <stdio.h>
#include <string.h>
#define TF 50
void ler_string(char vet[])
{
    printf("Escreva:\n");
    fgets(vet,TF,stdin);
    if(vet[strlen(vet)-1]==10)
        vet[strlen(vet)-1]='\0';
}

void fuc_strcpy(char novo[], char vet[])
{
    int i=0;
    while(vet[i]!='\0')
    {
        novo[i]=vet[i];
        i++;
    }
    novo[i]='\0';
}

void trocar_car(char vet[])
{
    int i=0;
    char car1, car2;
    printf("Digite o caracter que gostaria de excluir:");
    scanf(" %c", &car2);
    printf("Digite o elemento que gostaria de colocar:");
    scanf(" %c", &car1);
    while(vet[i]!='\0')
    {
        if(vet[i]==car2)
        {
            vet[i]=car1;
        }
        i++;
    }

}

void trocar_string(char vet1[], char vet2[])
{
    char aux[50];
    fuc_strcpy(aux,vet1);
    fuc_strcpy(vet1,vet2);
    fuc_strcpy(vet2,aux);
}

void string_maiuscula(char vet[])
{
    int i=0;
    while(vet[i]!='\0')
    {
        vet[i]=toupper(vet[i]);
        i++;
    }
}

void string_minuscula(char vet[])
{
    int i=0;
    while(vet[i]!='\0')
    {
        if(vet[i]>='A'&&vet[i]<='Z')
        {
            vet[i]+=32;
        }
        i++;
    }
}

void retirar_num(char vet[])
{
    int i=0,j;
    while(vet[i]!='\0')
    {
        if(vet[i]>='0'&&vet[i]<='9')
        {
            j=i;
            while(vet[j]!='\0')
            {
                vet[j]=vet[j+1];
                j++;
            }
            i--;
        }
        i++;
    }
}

void separar_string(char vet[], char maiuscula[], char minuscula[])
{
    int i=0, j=0, k=0;
    while(vet[i]!='\0')
    {
        if(vet[i]>='A'&&vet[i]<='Z')
        {
            maiuscula[j]=vet[i];
            j++;
        }
        else
        {
            if(vet[i]>='a'&&vet[i]<='z')
            {
                minuscula[k]=vet[i];
                k++;
            }
        }
        i++;
    }
    maiuscula[j]='\0';
    minuscula[k]='\0';
}
void main()
{
    char vet[TF],novo[TF],maiusculo[TF],minusculo[TF];
    ler_string(vet);
    trocar_car(vet);
    printf("\nO vetor 1 com os caracteres trocados = %s\n", vet);
    fflush(stdin);
    ler_string(novo);
    trocar_string(vet,novo);
    printf("\nO vetor 1: %s\nO vetor 2: %s\n",vet,novo);

    string_maiuscula(vet);
    printf("\nO vetor 1 em maiusculo: %s\n", vet);

    string_minuscula(vet);
    printf("\nO vetor 1 em minusculo: %s\n", vet);

    retirar_num(novo);
    printf("\nRetirando os numeros do vetor 1: %s\n", novo);

    separar_string(novo,maiusculo,minusculo);
    printf("\nA parte do vetor 2 maiusculo: %s\nA parte do vetor 2 minuscula: %s\n", maiusculo,minusculo);


}
