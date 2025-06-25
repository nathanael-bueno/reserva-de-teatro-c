#include <stdio.h>
#include <string.h>

void titulo(char *a, int b) {
    printf("\n");
    for (int i = 1; i <= (b * 2); i++) {
        if (i == b) {
            printf("= %s ", a);  
        } else {
            printf("=");
        }
    }
    printf("\n");
}

void nome_assento(char *nome, int assento) {
    if (strcmp(nome, " ") != 0) {
        printf("\n%d - Assento reservado para %s.", assento, nome);
    } else {
        printf("\n%d - Assento vazio.", assento);
    }
}

int contar_ocupados(char lugares[]) {
    int ocupados = 0;
    for (int i = 0; i < 5; i++) {
        if (lugares[i] == 'X') {
            ocupados++;
        }
    }
    return ocupados;
}

int main() {
    char nome1[25] = " ", nome2[25] = " ", nome3[25] = " ", nome4[25] = " ", nome5[25] = " ";
    char lugares[6] = "";
    int opc = 1;

    while (opc != 0) {
        titulo("TEATRO", 14);
        printf("[1] - Ver lugares disponiveis\n[2] - Reservar um lugar\n[3] - Cancelar Reserva\n[0] - Fechar Programa\nSelecione uma Opcao: ");
        scanf("%d", &opc);

        if (opc == 1) {
            titulo("ASSENTOS DISPONIVEIS", 7);

            for (int i = 0; i < 5; i++) {
                if (lugares[i] == 'X') {
                    printf("[X] ");
                } else {
                    printf("[ ] ");
                }
            }
            printf("\n");

            for (int i = 0; i < 5; i++) {
                printf(" %d  ", (i + 1));
            }
            printf("\n");

            nome_assento(nome1, 1);
            nome_assento(nome2, 2);
            nome_assento(nome3, 3);
            nome_assento(nome4, 4);
            nome_assento(nome5, 5);

            printf("\nOBS: Os assentos marcados com um 'X' estão ocupados.\n");

        } else if (opc == 2) {
            if (contar_ocupados(lugares) == 5) {
                printf("\n>> O teatro está lotado! Não há mais assentos disponíveis.\n");
            } else {
                int reservar = 0;
                titulo("RESERVAR ASSENTO", 9);
                printf("Reservar assento de N° (1 a 5): ");
                scanf("%d", &reservar);
                reservar--;

                if (reservar >= 0 && reservar < 5) {
                    if (lugares[reservar] == 'X') {
                        printf("\n>> Este assento já está reservado!\n");
                    } else {
                        printf("Informe o nome para o assento N° %d: ", (reservar + 1));
                        getchar(); 

                        switch (reservar) {
                            case 0: scanf("%s", nome1); break;
                            case 1: scanf("%s", nome2); break;
                            case 2: scanf("%s", nome3); break;
                            case 3: scanf("%s", nome4); break;
                            case 4: scanf("%s", nome5); break;
                        }
                        lugares[reservar] = 'X';
                        printf("\n>> Assento reservado com sucesso!\n");
                    }
                } else {
                    printf("\n>> Número de assento inválido!\n");
                }
            }

        } else if (opc == 3) {
            int cancelar = 0;
            titulo("CANCELAR RESERVA", 9);
            printf("Cancelar reserva do assento N° (1 a 5): ");
            scanf("%d", &cancelar);
            cancelar--;

            if (cancelar >= 0 && cancelar < 5) {
                if (lugares[cancelar] != 'X') {
                    printf("\n>> Este assento já está vazio!\n");
                } else {
                    switch (cancelar) {
                        case 0: strcpy(nome1, " "); break;
                        case 1: strcpy(nome2, " "); break;
                        case 2: strcpy(nome3, " "); break;
                        case 3: strcpy(nome4, " "); break;
                        case 4: strcpy(nome5, " "); break;
                    }
                    lugares[cancelar] = ' ';
                    printf("\n>> Reserva cancelada com sucesso!\n");
                }
            } else {
                printf("\n>> Número de assento inválido!\n");
            }

        } else if (opc == 4) {
            int consultar;
            titulo("CONSULTAR POLTRONA", 9);
            printf("Informe o número da poltrona (1 a 5): ");
            scanf("%d", &consultar);
            consultar--;

            if (consultar >= 0 && consultar < 5) {
                if (lugares[consultar] == 'X') {
                    switch (consultar) {
                        case 0: printf("\n>> Poltrona 1 está ocupada por %s.\n", nome1); break;
                        case 1: printf("\n>> Poltrona 2 está ocupada por %s.\n", nome2); break;
                        case 2: printf("\n>> Poltrona 3 está ocupada por %s.\n", nome3); break;
                        case 3: printf("\n>> Poltrona 4 está ocupada por %s.\n", nome4); break;
                        case 4: printf("\n>> Poltrona 5 está ocupada por %s.\n", nome5); break;
                    }
                } else {
                    printf("\n>> A poltrona %d está vazia.\n", consultar + 1);
                }
            } else {
                printf("\n>> Número de poltrona inválido!\n");
            }

        } else if (opc == 0) {
            printf("\n>> Obrigado! Volte sempre!\n");

        } else {
            printf("\n>> Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}