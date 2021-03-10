/*
 * Programa: Conversor de bases numéricas
 * Data de criação: 15/10/2018
 * Autor: Ádrio Francisco de Queiroz Falcão
 * Versão: 1.0
 * Última modificação em [25/10/2018] feita por [Ádrio Francisco de Queiroz Falcão]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

float BinFracio(char Dec[]){
    int tamanho = 0, j = 0; 
    float calc = 0.5, soma = 0; // Clac serve para calcular as bases
    bool boolean = 0, verfra = 0;

    tamanho = strlen(Dec); //Recebe o tamanho da String
    while(tamanho != 0){
        if(Dec[j] == ','|| Dec[j] == '.'){
            verfra = 1;
        }
        if(verfra == 1){
            if(Dec[j] == '1' && boolean == 0){
                soma = calc;
                boolean = 1;
            }else if(Dec[j] == '1' && boolean !=0){
                calc = calc/2;
                soma = soma + calc;
            }else if(Dec[j] == ',' || Dec[j] == '.'){

            }else{
                calc = calc/2;
            }
        }
        j++;
        tamanho--;
    }
    return soma;
}

void DecimalFracio(char bina[]){
    float fracio;
    int i = 0, j = 0, cont = 0;

    while(cont != 1){
        if(bina[j] == '.'){
            cont = 1;
        }else{
            bina[j] = '0';
            j++;
        }
    }

    if(cont == 0)
    return ;

    printf("\nBINA: %s", bina);
    fracio = atof(bina);
    sprintf(bina, "%f", fracio);
    printf("\nFRACIO: %f",fracio);

    for(i=0; i<10; i++){
        fracio = fracio*2;
        if(fracio >= 1){
            bina[i] = '1';
            fracio = fracio - 1;
            printf("\nBINA[%d]: %c", i, bina);
            printf("\nFRACIO\n: %d", fracio);
        }else
        bina[i] = '0';
        printf("\nBINA[%d]: %c\n", i, bina);
    }

    printf("%s",bina);
    system("pause");
}

void ParteInt(char num[]){
    int tamanho = 0, i= 0;

    tamanho = strlen(num);
    while(tamanho != 0){
        if(num[i] == ','|| num[i] == '.'){
            num[i] = '\0';
        }
        i++;
        tamanho--;
    }
}

void DecParaBin(){
    int inteiro,inteirobuff, resto, temp, i=0, sinal=0, fracioBin[10];
    float fracio;
    char binario[10], buffer[10] ;

    printf("Informe um numero DECIMAL: ");
    scanf("%f", &fracio);

    if(fracio < 0){
        fracio = fracio*-1;
        sinal = 1;
    }

    inteiro = fracio;
    inteirobuff = inteiro;
    strcpy(binario, "");

     while(inteiro >= 2){
        resto = inteiro%2; //Obtem o resto da divis�o
        temp = inteiro/2; //Obtem o Quociente
        inteiro = temp;
        sprintf(buffer, "%d", resto); //Atribui para variavel "Buffer" o valor de "Resto"
        strcat(binario, buffer); //Concatena o valor da variavel "Buffer" para "Binario"
    }

    sprintf(buffer, "%d", inteiro); //Ainda � precido do valor de "Quociente" por isso ele � passado para o "Buffer"
    strcat(binario, buffer);

    if(sinal == 1){
        fracio = fracio*-1;
        system("cls");
        printf("O Numero %f convertido para BINARIO e: 1 %s", fracio, strrev(binario));
        fracio = fracio*-1;
    }else{
        system("cls");
        printf("O Numero %f convertido para BINARIO e: %s", fracio, strrev(binario));
    }

    fracio =  fracio - inteirobuff;
    
    if(fracio == 0)
        printf("\n");

    if(fracio != 0){

        for(i=0; i<10; i++){
            fracio = fracio*2;
            if(fracio >= 1){
                fracioBin[i] = 1;
                fracio = fracio - 1;
            }else
            fracioBin[i] = 0;
        }

        printf(".");

        for(i=0; i<10; i++){
            printf("%d", fracioBin[i]);
        }

        printf("\n");
    }

    printf("\n");
    system("pause");
}

void BinParaDec(){
    char Dec[10], buffer[10], num[20];
    int tamanho = 0, i = 0, sinal = 0; // Temp serve para calcular as bases
    float soma = 0, fracio, temp = 1;
    bool boolean;

    printf("Informe um numero BINARIO: ");
    fflush(stdin);
    gets(Dec);
    strcpy(num, Dec);

    if(Dec[0] == '-')
        sinal = 1;

    fracio = BinFracio(Dec);
    ParteInt(Dec);
    tamanho = strlen(Dec); //Recebe o tamanho da String
    strrev(Dec); //Inverte a String

    while(tamanho != 0){
        if(Dec[i] == '1' && boolean == 0){ //Primeiro numero a ser somado
            soma = temp;
            boolean = 1;
        }else if(Dec[i] == '1' && boolean !=0){ //Segundo ou maior � ser somada
            temp = temp*2;
            soma = soma + temp;
        }else{ //Caso Seja zero, n�o ser� contabilizado na soma
            temp = temp*2;;
        }
        i++; //Indice que controla qual n�mero vai ser analizado e calculado
        tamanho--; //Controle de quantas an�lises ser�o feitas
    }
    
    strrev(Dec);
    soma = soma + fracio;

    if(sinal == 1){
        system("cls");
        soma = soma*-1;
        printf("O numero %s convertido para DECINAMAL e: %f\n", num, soma);
    }else{
        system("cls");
        printf("O numero %s convertido para DECINAMAL e: %f\n", num, soma);
    }
}

int main(){

    int op, menu;
    do{
        printf("\t\t-----Conversor de base Numerica-----\n\n");
        printf("Selecione uma das opções abaixo:\n\n");
        printf("[1] - Decimal -> Binario\n");
        printf("[2] - Binario -> Decimal\n");
        printf("[0] - Sair do programa\n");

        printf("\nDigite uma Opcao: ");
        scanf("%d", &op);

        switch(op){
        case 1:
            menu = 0;
            while(menu != 1){
                system("cls");
                DecParaBin();
                printf("\nDeseja voltar para o Menu? (1- Sim/ 0- Nao)\nOpcao: ");
                scanf("%d", &menu);
                system("cls");
            }
            break;

        case 2:
            menu = 0;
            while(menu != 1){
                system("cls");
                BinParaDec();
                printf("\nDeseja voltar para o Menu? (1- Sim/ 0- Nao)\nOpcao: ");
                scanf("%d", &menu);
                system("cls");
            }
            break;

        case 0:
            printf("\nPrograma Encerrado!\n");
            system("pause");
            system("cls");
            break;

        default:
            system("cls");
            system("pause");
            printf("\nOpcao invalida!\n");
        }

    }while(op != 0);

    return 0;
    system("pause");
}
