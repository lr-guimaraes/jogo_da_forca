#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int main(){
    char *Sorteio[][6] = {{"MMA","BOXE","VOLEI","SURF","JUDO",'SKATE'},
                        {"TREMOR","ZEMO","FALCAO","THANOS","MANDARIM","BUCKY"},
                        {"KRATOS","ATREUS","ZEUS","CRONOS","BALDUR","LAUFAY"},
                        {"ATHLETICO","CURITIBA","FLAMENGO","GREMIO","BRAGANTINO","SANTOS"}};
    char LetrasUsadas[26], Letra[1], P[13] ,palavra[13] = " "; 
    int s,S, i,j,cont,vidas,k;
    vidas = 6;
    i = 0;
    k = 1; 
    
    //Paravra sorteada
    srand(time(NULL)); 
    s =  rand() % 6; //sorteio da coluna
    S =  rand() % 4; //sorteio da linha
    //menu
    strcpy(P,Sorteio[S][s]);
    if (S == 0){
        printf("----------------------------\nJogo da forca sobre Esportes\n----------------------------\n");
    }else if (S == 1){
        printf("----------------------------\nJogo da forca sobre Personagens da Marvel\n----------------------------\n");
    }else if (S == 2)
    {
        printf("----------------------------\nJogo da forca sobre Pesonagens de God of war\n----------------------------\n");
    }else if (S == 3){
        printf("----------------------------\nJogo da forca sobre Times da serie A do Brasileirao\n----------------------------\n");
    }
    
    printf("A palavra tem %d letras\n",strlen(P));
    strncpy(palavra,"__________________",strlen(P));
   
    while (i< strlen(P) && vidas>0){
        //impreçoes
        printf("Voce tem %d vidas\n",vidas);
        printf("\nEscreva uma Letra: \n");
        gets(Letra); 
        
        //imprementação de letras usadas
        LetrasUsadas[k] = Letra[0];
        k++;
        //TESTE DE CARACTER
        for (cont = 0; cont < strlen(P); cont++){ 
            if (toupper(Letra[0]) == P[cont]){
                palavra[cont] = P[cont];
                i++;
            }
        }
        j = strlen(P);
        
        for (cont = 0; cont < strlen(P); cont++){
           if (toupper(Letra[0]) != P[cont]){
               j--;     
            }
        }
        if (j == 0){
            vidas--;
        }
        if(vidas == 0){
            printf("VOCE PERDEU \n");
         }

        printf("%s \n",palavra);
        printf("Letras usadas: \n");
        //Impressao das letras usadas
        for (cont =1 ;cont < k;cont++){
            printf("%c, ",toupper((LetrasUsadas[cont])));
        }
          printf("\n");
    }
    return 0;
}
