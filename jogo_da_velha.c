#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
  int opcao;
  setlocale(LC_ALL, "Portuguese");
  system("cls");

  do {
    printf("\n   -----Jogo da velha!-----\n");
    printf("\n\tMenu:\n");
    printf("\t1. Partida PvE\n");
    printf("\t2. Partida PvP\n");
    printf("\t3. Sair\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
        pve();
        break;
      case 2:
        pvp();
        break;
      case 3:
        printf("Saindo do programa.\n");
        break;
      default:
        printf("Opção inválida.\n");
    }
  } while (opcao != 3);

  return 0;
}

int pve() {
    // Variáveis
    int tabuleiro[3][3];
    int linha, coluna;
    int jogador = 1; // 1 para o jogador, 0 para o computador
    int jogadas = 0;
    int vencedor = -1; // inicializa com posição vazia
    int i;
    int j;

    // Inicializar o tabuleiro
    for (i = 0; i < 3; i++) {
        for ( j = 0; j < 3; j++) {
            tabuleiro[i][j] = -1; // tabuleiro vazio
        }
    }

    // Loop enquanto não tem vencedor ou atinge a quantidade limite de espaços
    while (vencedor == -1 && jogadas < 9) {
        // Exibir o tabuleiro
        printf("\n");
        for ( i = 0; i < 3; i++) {
            for ( j = 0; j < 3; j++) {
                if (j > 0) {
                    printf("|");
                }
                if (tabuleiro[i][j] == 0) { // marca posição para jogador 0 (computador)
                    printf(" 0 ");
                } else if (tabuleiro[i][j] == 1) { // marca posição para jogador 1
                    printf(" 1 ");
                } else {
                    printf("   "); // linha sem jogada
                }
            }
            printf("\n");
            if (i < 2) {
                printf("-----------\n");
            }
        }
        printf("\n");

        // Verificar se é a vez do jogador ou do computador
        if (jogador == 1) {
            // Solicitar entrada do jogador
            printf("Turno do jogador. Digite a linha (0-2): ");
            scanf("%d", &linha);
            printf("Turno do jogador. Digite a coluna (0-2): ");
            scanf("%d", &coluna);

            // Verificar se a jogada é válida
            if (linha < 0 || linha >= 3 || coluna < 0 || coluna >= 3 || tabuleiro[linha][coluna] != -1) {
                printf("Movimento inválido. Tente novamente.\n");
                continue;
            }

            // Fazer a jogada
            tabuleiro[linha][coluna] = 1;
            jogadas++;
            jogador = 0; // trocar para o computador
        } else {
            // Jogada do computador
            srand(time(NULL)); // inicializar gerador de números aleatórios
            int linha_aleatoria = rand() % 3;
            int coluna_aleatoria = rand() % 3;

            // Verificar se a jogada é válida
            while (tabuleiro[linha_aleatoria][coluna_aleatoria] != -1) {
                linha_aleatoria = rand() % 3;
                coluna_aleatoria = rand() % 3;
            }

            // Fazer a jogada
            tabuleiro[linha_aleatoria][coluna_aleatoria] = 0;
            jogadas++;
            jogador = 1; // trocar para o jogador
        }
        system("cls");

        // Verificar vencedor
        for ( i = 0; i < 3; i++) {
            if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != -1) {
                vencedor = tabuleiro[i][0];
            }
            if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != -1) {
                vencedor = tabuleiro[0][i];
            }
        }
        if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != -1) {
            vencedor = tabuleiro[0][0];
        }
        if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != -1) {
            vencedor = tabuleiro[0][2];
        }
    }
    // Exibir o tabuleiro final
    printf("\n");

    for ( i = 0; i < 3; i++) {
        for ( j = 0; j < 3; j++) {
            if (j > 0) {
                printf("|");
            }
            if (tabuleiro[i][j] == 0) {
                printf(" 0 ");
            } else if (tabuleiro[i][j] == 1) {
                printf(" 1 ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
        if (i < 2) {
            printf("-----------\n");
        }
    }
    printf("\n");

    // Exibir o resultado
    if (vencedor != -1) {
        if (vencedor == 0) {
            printf("Computador vence!\n");
        } else {
            printf("Jogador vence!\n");
        }
    } else {
        printf("Velha!\n");
    }
    system("pause");
    return 0;
}

int pvp() {
    //Variaveis
    int tabuleiro[3][3];
    int linha, coluna;
    int jogador = 0;
    int jogadas = 0;
    int vencedor = -1; //inicializa com posiÃ§Ã£o vazia
    int i;
    int j;

    // Inicializar o tabuleiro
    for ( i = 0; i < 3; i++) {
        for ( j = 0; j < 3; j++) {
            tabuleiro[i][j] = -1; //tabuleiro vazio
        }    
    }
    //Loop enquanto nÃ£o tem vancedor ou atinge a quantidade limite de espaÃ§os
    while (vencedor == -1 && jogadas < 9) {
        // Exibir o tabuleiro
        printf("\n");
        for ( i = 0; i < 3; i++) {
            for ( j = 0; j < 3; j++) {
                if (j > 0) {
                    printf("|");
                }    
                if (tabuleiro[i][j] == 0) { //marca posiÃ§Ã£o para jogador 0
                    printf(" 0 ");
                } else if (tabuleiro[i][j] == 1) { //marca posiÃ§Ã£o para jogador 1
                    printf(" 1 ");
                } else {
                    printf("   "); //linha sem jogada
                }    
            }
            printf("\n");
            if (i < 2) {
                printf("-----------\n");
            }    
        }
        printf("\n");

        // Solicitar entrada do jogador
        printf("Turno do jogador %d. Digite a linha (0-2): ", jogador);
        scanf("%d", &linha);
        printf("Turno do jogador %d. Digite a coluna (0-2): ", jogador);
        scanf("%d", &coluna);

        // Verificar se a jogada Ã© vÃ¡lida
        if (linha < 0 || linha >= 3 || coluna < 0 || coluna >= 3 || tabuleiro[linha][coluna] != -1) {
            printf("Movimento inválido. Tente novamente.\n");
            continue;
        }

        // Fazer a jogada
        tabuleiro[linha][coluna] = jogador;
        jogadas++;

        // Verificar vencedor
        for ( i = 0; i < 3; i++) {
            if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != -1) {
                vencedor = tabuleiro[i][0];
            }  
            if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != -1) {
                vencedor = tabuleiro[0][i];
            }
        }
        if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != -1) {
            vencedor = tabuleiro[0][0];
        }
        if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != -1) {
            vencedor = tabuleiro[0][2];
        }  
        // Trocar jogador
        if (jogador == 0) {
            jogador = 1;
        } else {
            jogador = 0;
        }
    }

    // Exibir o tabuleiro final
    printf("\n");
    for ( i = 0; i < 3; i++) {
        for ( j = 0; j < 3; j++) {
            if (j > 0) {
                printf("|");
            }    
            if (tabuleiro[i][j] == 0) {
                printf(" 0 ");
            } else if (tabuleiro[i][j] == 1) {
                printf(" 1 ");
            } else {
                printf("   ");
            }    
        }
        printf("\n");
        if (i < 2) {
            printf("-----------\n");
        }    
    }
    printf("\n");

    // Exibir o resultado
    if (vencedor != -1) {
        printf("Jogador %d vence!\n", vencedor);
    } else { 
        printf("Velha!\n");
    }
    system("pause");
    return 0;
}
