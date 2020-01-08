#include <stdio.h>
#include <stdlib.h>

void Win_Cond(char **posicao);

    int min(char **posicao, char jogador, int numero_jogadas);
    int vencedor(char **casa, int cont_jogadas){
    if (casa[0][0] == 'X' && casa[0][1] == 'X' && casa[0][2] == 'X') {
             return -1;
        }
       else  if (casa[1][0] == 'X' && casa[1][1] == 'X' && casa[1][2] == 'X') {
            return -1;
        }
       else  if (casa[2][0] == 'X' && casa[2][1] == 'X' && casa[2][2] == 'X') {
            return -1;
        }
        else if (casa[0][0] == 'X' && casa[1][0] == 'X' && casa[2][0] == 'X') {
            return -1;
        }
       else  if (casa[0][1] == 'X' && casa[1][1] == 'X' && casa[2][1] == 'X') {
            return -1;
        }
        else if (casa[0][2] == 'X' && casa[1][2] == 'X' && casa[2][2] == 'X') {
            return -1;
        }
        else if (casa[0][0] == 'X' && casa[1][1] == 'X' && casa[2][2] == 'X') {
            return -1;
        }
       else  if (casa[0][2] == 'X' && casa[1][1] == 'X' && casa[2][0] == 'X') {
            return -1;
        }
        else if (casa[0][0] == 'O' && casa[0][1] == 'O' && casa[0][2] == 'O') {
            return 1;
        }
       else  if (casa[1][0] == 'O' && casa[1][1] == 'O' && casa[1][2] == 'O') {
             return 1;
        }
        else if (casa[2][0] == 'O' && casa[2][1] == 'O' && casa[2][2] == 'O') {
             return 1;
        }
        else if (casa[0][0] == 'O' && casa[1][0] == 'O' && casa[2][0] == 'O') {
             return 1;
        }
        else if (casa[0][1] == 'O' && casa[1][1] == 'O' && casa[2][1] == 'O') {
             return 1;
        }
        else if (casa[0][2] == 'O' && casa[1][2] == 'O' && casa[2][2] == 'O') {
             return 1;
        }
        else if (casa[0][0] == 'O' && casa[1][1] == 'O' && casa[2][2] == 'O') {
             return 1;
        }
        else if (casa[0][2] == 'O' && casa[1][1] == 'O' && casa[2][0] == 'O') {
             return 1;
        }
        else if (cont_jogadas<=9){
            return -2;
        }
        else{return 0;}
}

char **copy(char **arr) {
    int i, j;
    char **novo = (char **)malloc(3 * sizeof(char*));
    novo[0] = (char *)malloc(3 * sizeof(char));
    novo[1] = (char *)malloc(3 * sizeof(char));
    novo[2] = (char *)malloc(3 * sizeof(char));

    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            novo[i][j] = arr[i][j];
        }
    }
return novo;
}

int max(char ** posicao, char jogador, int numero_jogadas){

    //printf("Estou em min, vez do %c\n", jogador);
    //Tabuleiro(posicao);
    //printf("\nVencedor:%d\n",vencedor(posicao, numero_jogadas));

    int ven = vencedor(posicao, numero_jogadas);
    if (ven == -2) {
        int melhorRetorno=-1000;
        int i, j;
        for (i=0; i<3;i++){
            for (j=0; j<3;j++){
                if (posicao[i][j] == ' '){
                    char ** copia = copy(posicao);
                    copia[i][j] = jogador;
                    int retorno = min(copia, 'X',numero_jogadas+1);
                    if (retorno > melhorRetorno){
                        melhorRetorno = retorno;
                    }
                }
            }
        }
    return melhorRetorno;
    }
return ven;
}

int min(char ** posicao, char jogador, int numero_jogadas){

    int ven = vencedor(posicao, numero_jogadas);
    //printf("Estou em min, vez do %c\n", jogador);
    //Tabuleiro(posicao);
    //printf("\nVencedor:%d\n",vencedor(posicao, numero_jogadas));

    if (ven == -2) {
        int melhorRetorno=1000;
        int i, j;
        for (i=0; i<3;i++){
            for (j=0; j<3;j++){
                if (posicao[i][j] == ' '){
                char ** copia = copy(posicao);
                copia[i][j] = jogador;
                int retorno = max(copia, 'O',numero_jogadas+1);
                    if (retorno < melhorRetorno){
                        melhorRetorno = retorno;
                    }
                }
            }
        }
    return melhorRetorno;
    }
return ven;
}

int *jogadaIA(char **posicao, char jogador, int numero_jogadas){
    //printf("Estou em max, vez do %c\n", jogador);
    Tabuleiro(posicao);
    //printf("\nVencedor:%d\n",vencedor(posicao, numero_jogadas));
    int Melhorlinha=0, MelhorColuna=0;
    int melhorRetorno=-10000;
    int i, j;
    for (i=0; i<3;i++){
        for (j=0; j<3;j++){
            if (posicao[i][j] == ' '){
                char **copia = copy(posicao);
                copia[i][j] = jogador;
                int retorno = min(copia, 'X', numero_jogadas+1);
                printf("%d\n", retorno);
                    if (retorno > melhorRetorno){
                        melhorRetorno= retorno;
                        Melhorlinha=i;
                        MelhorColuna=j;
                }
            }
        }
    }
    int *jogada = (int*)malloc(sizeof(int)*2);
    jogada[0] = Melhorlinha;
    jogada[1] = MelhorColuna;
return jogada;
}

void Tabuleiro(char **posicao) {

    system("cls");
    printf("\n\t\t   %c | %c | %c\n", posicao[0][0], posicao[0][1], posicao[0][2]);
    printf("\t\t  ------------\n");
    printf("\t\t   %c | %c | %c\n", posicao[1][0], posicao[1][1], posicao[1][2]);
    printf("\t\t  ------------\n");
    printf("\t\t   %c | %c | %c\n", posicao[2][0], posicao[2][1], posicao[2][2]);
}

int main(){

    char **casa = (char **)malloc(3 * sizeof(char*));
    casa[0] = (char *)malloc(3 * sizeof(char));
    casa[1] = (char *)malloc(3 * sizeof(char));
    casa[2] = (char *)malloc(3 * sizeof(char));
    //char casa[3][3] =  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            casa[i][j] = ' ';
        }
    }

    char jogar_novamente;
    int cont_jogadas, linha, coluna, vez=0, i, j;

    printf("#### Bem-vindo ao Jogo da Velha ####\n\n");

    do {
        cont_jogadas = 1;
        for(i=0; i<=2; i++) {
            for(j=0; j<=2; j++)
                casa[i][j] = ' ';
        }

        do {
            Tabuleiro(casa);

            if(vez%2 == 0){
                printf("\nVez do Jogador --> X <--\n");
                printf("\nDigite a linha e a coluna que deseja jogar separados por um espaco: ");
                scanf("%d", &linha);
                //printf("\nDigite a coluna que deseja jogar: ");
                scanf("%d", &coluna);}
            else{
                printf("\nVez do Jogador --> O <--\n");
                int *jogadaBola = jogadaIA(casa, 'O', cont_jogadas);
                linha = jogadaBola[0]+1;
                coluna= jogadaBola[1]+1;
        }

            if(linha < 1 || linha > 3 || coluna < 1 || coluna > 3) {
                printf("\nDigite um valor valido\n");
                system("pause");
            }
            else if(casa[linha-1][coluna-1] != ' ') {
                linha=0;
                coluna=0;
                printf("\n\nEssa posicao ja esta preenchida! Tente novamente\n");
                system("pause\n");
            }
            else {
                if(vez % 2 == 0) {
                    casa[linha-1][coluna-1] = 'X';
                }
                else {
                    casa[linha-1][coluna-1] = 'O';
                }
                vez++;
                cont_jogadas++;
            }

        if (casa[0][0] == 'X' && casa[0][1] == 'X' && casa[0][2] == 'X') {
            cont_jogadas = 10;
        }
        if (casa[1][0] == 'X' && casa[1][1] == 'X' && casa[1][2] == 'X') {
            cont_jogadas = 10;
        }
        if (casa[2][0] == 'X' && casa[2][1] == 'X' && casa[2][2] == 'X') {
            cont_jogadas = 10;
        }
        if (casa[0][0] == 'X' && casa[1][0] == 'X' && casa[2][0] == 'X') {
            cont_jogadas = 10;
        }
        if (casa[0][1] == 'X' && casa[1][1] == 'X' && casa[2][1] == 'X') {
            cont_jogadas = 10;
        }
        if (casa[0][2] == 'X' && casa[1][2] == 'X' && casa[2][2] == 'X') {
            cont_jogadas = 10;
        }
        if (casa[0][0] == 'X' && casa[1][1] == 'X' && casa[2][2] == 'X') {
            cont_jogadas = 10;
        }
        if (casa[0][2] == 'X' && casa[1][1] == 'X' && casa[2][0] == 'X') {
            cont_jogadas = 10;
        }
        if (casa[0][0] == 'O' && casa[0][1] == 'O' && casa[0][2] == 'O') {
            cont_jogadas = 11;
        }
        if (casa[1][0] == 'O' && casa[1][1] == 'O' && casa[1][2] == 'O') {
            cont_jogadas = 11;
        }
        if (casa[2][0] == 'O' && casa[2][1] == 'O' && casa[2][2] == 'O') {
            cont_jogadas = 11;
        }
        if (casa[0][0] == 'O' && casa[1][0] == 'O' && casa[2][0] == 'O') {
            cont_jogadas = 11;
        }
        if (casa[0][1] == 'O' && casa[1][1] == 'O' && casa[2][1] == 'O') {
            cont_jogadas = 11;
        }
        if (casa[0][2] == 'O' && casa[1][2] == 'O' && casa[2][2] == 'O') {
            cont_jogadas = 11;
        }
        if (casa[0][0] == 'O' && casa[1][1] == 'O' && casa[2][2] == 'O') {
            cont_jogadas = 11;
        }
        if (casa[0][2] == 'O' && casa[1][1] == 'O' && casa[2][0] == 'O') {
            cont_jogadas = 11;
        }
        } while(cont_jogadas<=9);

        Tabuleiro(casa);

        if (cont_jogadas == 10)
            printf("\n\t\t **PARABENS**\n\n\t O JOGADOR > X < EH O VENCEDOR!!\n");
        if (cont_jogadas == 11)
            printf("\n\t\t **PARABENS**\n\n\t O JOGADOR > O < EH O VENCEDOR!!\n");

        printf("\nDeseja jogar novamente? [S/N]\n");
        scanf("%s", &jogar_novamente);

    } while(jogar_novamente == 's' || jogar_novamente == 'S');

    printf("\n\t** Isso eh tudo, pessoal! **\n");

return 0;
}