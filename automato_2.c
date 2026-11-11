#include <stdio.h>

char *s;
int p;

void le_palavra(){
    p = 0;
    s = "O computador e uma maquina capaz de variados tipos de tratamento automatico de informacoes ou processamento de dados. Entende-se por computador um sistema fisico que realiza algum tipo de computacao. Assumiu-se que os computadores pessoais e laptops sao icones da era da informacao. O primeiro computador eletromecanico foi construido por Konrad Zuse (1910-1995). Atualmente, um microcomputador é também chamado computador pessoal ou ainda computador domestico.@";
}

bool xp(char c){
    return s[p] == c;
}

bool np(){
    p++;
    return (true);
}

int main(){

    char fim = '@';
    int estado = 0;
    int contagem = 0;
    int inicio = 0; 

    le_palavra();

    while(!xp(fim)){
        switch(estado){
            case 0:
                if (xp(' ') || xp('C')){
                    np();
                    estado = 1;
                }
                else{
                    np();
                    estado = 0;
                }
                break;

            case 1: 
                if (xp('c')){
                    np();
                    inicio = p;
                    estado = 2;
                }
                else{
                    np();
                    estado = 0;
                }
                break;
            case 2:
                if (xp('o')){
                    np();
                    estado = 3;
                }
                else{
                    np();
                    estado = 0;
                }
                break;
            case 3:
                if (xp('m')){
                    np();
                    estado = 4;
                }
                else{
                    np();
                    estado = 0;
                }
                break;
            case 4:
                if (xp('p')){
                    np();
                    estado = 5;
                }
                else{
                    np();
                    estado = 0;
                }
                break;
            case 5: 
                if (xp('u')){
                    np();
                    estado = 6;
                }
                else{
                    np();
                    estado = 0;
                }
                break;
            case 6:
                if (xp('t')){
                    np();
                    estado = 7;
                }
                else{
                    np();
                    estado = 0;
                }
                break;
            case 7:
                if (xp('a')){
                    np();
                    estado = 8;
                }
                else{
                    np();
                    estado = 0;
                }
                break;
            case 8:
                if (xp('d')){
                    np();
                    estado = 9;
                }
                else{
                    np();
                    estado = 0;
                }
                break;
            case 9:
                if (xp('o')){
                    np();
                    estado = 10;
                }
                else{
                    np();
                    estado = 0;
                }
                break;
            case 10:
                if (xp('r')){
                    np();
                    estado = 11;
                }
                else{
                    np();
                    estado = 0;
                }
                break;
            case 11:
                if (xp(' ') || xp('.')){
                    np();
                    contagem++;
                    printf("Ocorrencia %d encontrada nas posicoes do intervalo dos indices [%d, %d]\n", contagem, inicio - 1, inicio + 8);
                    estado = 0;
                }
                else{
                    np();
                    estado = 0;
                }
                break;
        }
    }

    printf("\nO automato reconheceu %d ocorrencias da palavra 'computador' no texto!", contagem);

    return 0;
}
