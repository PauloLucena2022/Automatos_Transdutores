// Todas as cadeias em {0,1}* que representam cada 1 seguido imediatamente de dois 0
#include <stdio.h>

char *s;
int p;

void le_palavra(){
    p = 0;
    s = "10001001000@";
}

bool xp(char c){
    return s[p] == c;
}

bool np(){
    p++;
    return(true);
}

int main(){
    char fim = '@';
    int estado = 0;
    bool erro;

    le_palavra();

    while (!xp(fim) && !erro){
        switch(estado){
            case 0: // Estado q0 (estado final) - 0 fica em q0 / 1 - vai pra q1
                if (xp('0')){
                    np();
                }
                else if (xp('1')) {
                    np();
                    estado = 1;
                }
                else{
                    erro = true;
                }
                break;

            case 1: // Estado q1 - 0 - vai pra q2 / 1 - quebra
                if (xp('1')){
                    erro = true;
                }
                else if (xp('0')){
                    np();
                    estado = 2;
                }
                else {
                    erro = true;
                }
                break;
            
            case 2: // Estado q2 - 0 volta pra q0 / 1 - quebra
                if (xp('1')){
                    erro = true;
                }
                else if (xp('0')){
                    np();
                    estado = 0;
                }
                else {
                    erro = true;
                } 
                break;
        }
    }

    if (!erro && estado == 0 && xp(fim)){
        printf("O automato reconheceu com sucesso ate a posicao: %d\n", p+1);
    } 
    else {
        printf("Erro na posicao %d: caractere inesperado '%c' no estado 'q%d'\n", p + 1, s[p], estado);
    }

    return 0;
}