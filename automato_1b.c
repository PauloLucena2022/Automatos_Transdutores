// Todas as cadeias em {a,b}* de modo que o último símbolo seja b e o número de símbolos a seja par
#include <stdio.h>

char *s;
int p;

void le_palavra(){
    p = 0;
    s = "ababbbbbaabb@";
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
            case 0: // Estado q0 - a - vai pra q1 / b - vai pra q2
                if (xp('a')){
                    np();
                    estado = 1;
                }
                else if (xp('b')){
                    np();
                    estado = 2;
                }
                else{
                    erro = true;
                }
                break;
            
            case 1: // Estado q1 - a vai pra q0 / b - fica em q1
                if (xp('a')){
                    np();
                    estado = 0;
                }
                else if (xp('b')){
                    np();
                    estado = 1;
                }
                else{
                    erro = true;
                }
                break;
            
            case 2: // Estado q2 - a - vai pra q1 / b - fica em q2 (Estado Final)
                if (xp('a')){
                    np();
                    estado = 1;
                }
                else if (xp('b')){
                    np();
                    estado = 2;
                }
                else{
                    erro = true;
                }
                break;
        }
    }

    if (!erro && estado == 2 && xp(fim)){
        printf("O automato reconheceu com sucesso ate a posicao: %d\n", p+1);
    }
    else{
        printf("Erro na posicao %d: caractere inesperado '%c' no estado 'q%d'\n", p + 1, s[p], estado);
    }

    return 0;
}