#include <stdio.h>

typedef enum {
    q0,
    q25,
    q50,
    q75,
    q100
} Estado;

int maquina_mealy(int moeda, Estado *estado){
    int saida = 0;

    switch (*estado){
        case q0:
            if (moeda == 25){
                *estado = q25;
                saida = 0;
            }
            else if (moeda == 50){
                *estado = q50;
                saida = 0;
            }
            else if (moeda == 100){
                *estado = q100;
                saida = 1;
            }
            break;
        
        case q25:
            if (moeda == 25){
                *estado = q50;
                saida = 0;
            }
            else if (moeda == 50){
                *estado = q75;
                saida = 0;
            }
            else if (moeda == 100){
                *estado = q25; // 125, vai liberar 100 e deixar 25
                saida = 1;
            }
            break;

        case q50:
            if (moeda == 25){
                *estado = q75;
                saida = 0;
            }
            else if (moeda == 50){
                *estado = q100;
                saida = 1; 
            }
            else if (moeda == 100){
                *estado = q50; // 150, vai liberar 100 e deixar 50
                saida = 1;
            }
            break;

        case q75:
            if (moeda == 25){
                *estado = q100;
                saida = 1;
            }
            else if(moeda == 50){
                *estado = q25;
                saida = 1;
            }
            else if (moeda == 100){
                *estado = q75;
                saida = 1;
            }
            break;
        
        case q100:
            if (moeda == 25){
                *estado = q25;
                saida = 0;
            }
            else if (moeda == 50){
                *estado = q50;
                saida = 0;
            }      
            else if (moeda == 100){
                *estado = q100;
                saida = 1;
            }
            break;
    }

    return saida;
}

int main(){

    int moedas[] = {100,25,25,25,25,100,50,50,100,100,25,50,25,50,25,25,100};
    int n = sizeof(moedas) / sizeof(moedas[0]);
    int saida_lista[n];

    Estado estado_atual = q0;

    for (int i = 0; i < n; i++){
        int m = moedas[i];
        saida_lista[i] = maquina_mealy(m, &estado_atual);
    }

    printf("Moedas: ");
    for (int i = 0; i < n; i++){
        printf("%d ", moedas[i]);
    }

    printf("\nSaidas: ");
    for (int i = 0; i < n; i++){
        printf("%d ", saida_lista[i]);
    }

    return 0;
}