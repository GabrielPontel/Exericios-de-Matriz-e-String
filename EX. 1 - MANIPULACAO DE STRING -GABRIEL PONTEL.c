#include <stdio.h>
#define TF 50

///contar como strlen
int fuc_strlen(char vet[])
{
    int tl=0;
    while(vet[tl]!='\0')
        tl++;
    return tl;
}

///ler o string
void ler_string(char vet[])
{
    printf("Escreva:\n");
    fgets(vet,TF,stdin);
    if(vet[fuc_strlen(vet)-1]==10)
        vet[fuc_strlen(vet)-1]='\0';
}

///validar posicao para exclusao tl-1
int val_pos_exc(char vet[])
{
    int pos,aux;
    aux = fuc_strlen(vet);
    do
    {
        printf("Digite a posicao escolhida dentre: 0 e %d\n", aux-1);
        scanf("%d", &pos);
    }
    while(aux-1<pos||pos<0);
    return pos;
}

///funcao de excluir um elemento na posicao desejada
void excluir_elem(char vet[],int pos)
{
    int i;
    for(i=pos; i<fuc_strlen(vet); i++)
        vet[i]=vet[i+1];
}

///validar posicao para exclusao tl
int val_pos_inc(char vet[])
{
    int pos,aux;
    aux = fuc_strlen(vet);
    do
    {
        printf("Digite a posicao escolhida dentre: 0 e %d\n", aux);
        scanf("%d", &pos);
    }
    while(aux<pos||pos<0);
    return pos;
}

///Incluir determinado elemento em uma pos
void incluir_elem(char vet[])
{
    int pos,i;
    char car;
    pos = val_pos_inc(vet);
    printf("Digite o caracter desejado:\n");
    scanf(" %c", &car);
    for(i=fuc_strlen(vet)+1; i>pos; i--)
    {
        vet[i]=vet[i-1];
    }
    vet[pos]=car;
}

///Copiar em outra string
void cop_string(char vet[], char novo[], int inicial,int fim)
{
    int i,j=0;
    for(i=inicial; i<fim+1; i++)
    {
        novo[j]=vet[i];
        j++;
    }
    novo[j]='\0';
}

///Copiar uma parte da string para outra
void fuc_copy(char vet[], char novo[])
{
    int inicial,fim,aux;
    inicial = val_pos_exc(vet);
    fim = val_pos_inc(vet);
    if(fim<inicial)
    {
        aux=inicial;
        inicial=fim;
        fim=aux;
    }
    cop_string(vet,novo,inicial,fim);
}

///Copiar a ultima palavra em outra string
void copiar_ultima(char vet[], char novo[])
{
    int i, pos;
    i=fuc_strlen(vet);
    while(vet[i]!=' '&& i>-1)
        i--;
    pos=i;

    cop_string(vet,novo,pos,fuc_strlen(vet));
}

///Copiar a primeira palavra em outra string
void copiar_primeira(char vet[], char novo[])
{
    int i=0, pos;
    while(vet[i]!=' '&& i<fuc_strlen(vet))
        i++;
    pos=i;

    cop_string(vet,novo,0,pos);
}

///Copiar o conteudo de uma string para outra
void fuc_strcpy(char vet[], char novo[])
{
    int i=0;
    while(vet[i]!='\0')
    {
        novo[i]=vet[i];
        i++;
    }
    novo[i]='\0';
}

///Apagar o conteudo de uma string
void apagar_string(char vet[])
{
    vet[0]='\0';
}

///Retirar espacos em brancos repetidos
void apagar_repetidos(char vet[])
{
    int i=0;
    while(vet[i]!='\0')
    {
        if(vet[i]==' '&&vet[i+1]==' ')
        {
            excluir_elem(vet,i);
            i--;
        }
        i++;
    }
}

///Retirar espaco em branco do comeco
void retirar_inicio(char vet[])
{
    if(vet[0]==' ')
    {
        excluir_elem(vet,0);
    }
}

///Retirar espaco em branco no fim
void retirar_fim(char vet[])
{
    if(vet[fuc_strlen(vet)-1]==' ')
    {
        excluir_elem(vet,fuc_strlen(vet)-1);
    }
}

int escolha_opcao()
{
    int opcao;
    do{
    printf("\n---------------------------menu-----------------------------------\n0. Sair\n1. Excluir um caracter de uma determinada posição de uma string;\n2. Incluir um caracter em uma determinada posição de uma string;\n3. Copiar uma parte de uma string para dentro de outra, para isso deve-se conhecer a posicao inicial e o final a ser copiada;\n4. Copiar a ultima palavra de uma string para outra string;\n5. Copiar a primeira palavra de uma string para outra;\n6. Retirar os espaços em branco repetidos de uma string;\n7. Retirar os espaços em branco do final de uma string;\n8. Retirar os espaços em branco do inicio de uma string;\n9. Copiar o conteudo de uma string para outra;\n10. Apagar o conteudo de uma string\n-----------------------------------------------------------------\n");
    scanf("%d", &opcao);
    if(opcao<0||opcao>10)
    {
        printf("\nOpcao invalida, digite novamente\n");
    }
    }while(opcao<0||opcao>10);
    return opcao;
}
void main()
{
    char vet[TF], novo[TF];
    int inicio, fim, opcao;
    ler_string(vet);
    do
    {

        switch(escolha_opcao())
        {
        case 1:
            excluir_elem(vet, val_pos_exc(vet));
            printf("\n--------------------------Excluir elemento--------------------------\n%s\n", vet);
            break;
        case 2:
            incluir_elem(vet);
            printf("\n--------------------------Incluiir elemento--------------------------\n%s\n", vet);
            break;
        case 3:
            fuc_copy(vet, novo);
            printf("\n--------------------------Copiar uma parte--------------------------\n%s\n", novo);
            break;
        case 4:
            copiar_ultima(vet, novo);
            printf("\n--------------------------Copiar a ultima palavra--------------------------%s\n", novo);
            break;
        case 5:
            copiar_primeira(vet, novo);
            printf("\n--------------------------Copiar a primeira palavra--------------------------\n%s\n", novo);
            break;
        case 6:
            apagar_repetidos(vet);
            printf("\n--------------------------Apagar espacos repetidos--------------------------\n%s\n", vet);
            break;
        case 7:
            retirar_fim(vet);
            printf("\n--------------------------Apagar espaco no fim--------------------------\n%s\n", vet);
            break;
        case 8:
            retirar_inicio(vet);
            printf("\n--------------------------Apagar espaco no inicio--------------------------\n%s\n", vet);
            break;
        case 9:
            fuc_strcpy(vet, novo);
            printf("\n--------------------------Copiar o conteudo para outra string--------------------------\n%s\n", novo);
            break;
        case 10:
            apagar_string(vet);
            printf("\n--------------------------Apagar a String--------------------------\n%s\n", vet);
            break;
        }
    }
    while(opcao!=0);



}
