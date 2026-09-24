#include <stdio.h>
#include <stdlib.h>

#define MAX_TEMPERATURAS 100

int main() {

    int opcao;

    float limite = 0;
    float temperaturas[MAX_TEMPERATURAS];

    int count = 0;
    int limiteDefinido = 0;
    int alertaSeguranca = 0;

    do {

        system("cls");

        printf("\n===== TEMPERATURE =====\n");

        printf("\n1. Definir Temperatura Limite\n");
        printf("\n2. Adicionar Valores de Temperatura\n");
        printf("\n3. Mostrar Resultados\n");
        printf("\n4. Sair\n");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        system("cls");

        switch (opcao) {

            // =========================================
            // CASE 1 - DEFINIR LIMITE
            // =========================================

            case 1:

                printf("===== DEFINIR TEMPERATURA LIMITE =====\n\n");

                printf("Digite a temperatura limite (0 a 75): ");
                scanf("%f", &limite);

                while (limite < 0 || limite > 75) {

                    printf("\nTemperatura invalida!\n");
                    printf("Digite novamente (0 a 75): ");
                    scanf("%f", &limite);
                }

                limiteDefinido = 1;

                printf("\nTemperatura limite definida: %.2f C\n", limite);

                system("pause");

                break;


            // =========================================
            // CASE 2 - ADICIONAR TEMPERATURAS
            // =========================================

            case 2: {

                if (!limiteDefinido) {

                    printf("Defina primeiro a temperatura limite!\n");

                    system("pause");

                    break;
                }

                if (alertaSeguranca) {

                    printf("O sistema ja foi interrompido por seguranca.\n");

                    system("pause");

                    break;
                }

                int quantidade;

                printf("===== ADICIONAR TEMPERATURAS =====\n\n");

                printf("Quantos valores deseja adicionar? ");
                scanf("%d", &quantidade);

                while (quantidade <= 0 ||
                       quantidade > MAX_TEMPERATURAS - count) {

                    printf("\nQuantidade invalida!\n");

                    printf("Voce pode adicionar no maximo %d valores.\n",
                           MAX_TEMPERATURAS - count);

                    printf("Digite novamente: ");
                    scanf("%d", &quantidade);
                }


                for (int i = 0; i < quantidade; i++) {

                    printf("\nDigite a temperatura %d: ",
                           count + 1);

                    scanf("%f", &temperaturas[count]);


                    // Validacao da temperatura

                    while (temperaturas[count] < 0 ||
                           temperaturas[count] > 75) {

                        printf("Temperatura invalida!\n");

                        printf("Digite novamente (0 a 75): ");

                        scanf("%f", &temperaturas[count]);
                    }


                    // Verifica se esta acima do limite

                    if (temperaturas[count] > limite) {

                        printf("\nALERTA: temperatura acima do limite!\n");

                    }

                    count++;


                    // Verifica as ultimas 3 temperaturas

                    if (count >= 3) {

                        if (temperaturas[count - 1] > limite &&
                            temperaturas[count - 2] > limite &&
                            temperaturas[count - 3] > limite) {

                            printf("\n");
                            printf("====================================\n");
                            printf("       ALERTA DE SEGURANCA!\n");
                            printf("====================================\n");

                            printf("\n3 temperaturas consecutivas");
                            printf(" acima do limite!\n");

                            printf("A maquina sera desligada automaticamente.\n");

                            alertaSeguranca = 1;

                            break;
                        }
                    }
                }

                system("pause");

                break;
            }


            // =========================================
            // CASE 3 - RELATORIO
            // =========================================

            case 3: {

                printf("===== RELATORIO FINAL =====\n\n");

                if (count == 0) {

                    printf("Nenhuma temperatura foi registrada.\n");

                    system("pause");

                    break;
                }


                float soma = 0;
                float media;

                float maior = temperaturas[0];
                float menor = temperaturas[0];

                int acimaDoLimite = 0;


                // Percorre todas as temperaturas

                for (int i = 0; i < count; i++) {

                    // Soma para calcular a media

                    soma += temperaturas[i];


                    // Maior temperatura

                    if (temperaturas[i] > maior) {

                        maior = temperaturas[i];
                    }


                    // Menor temperatura

                    if (temperaturas[i] < menor) {

                        menor = temperaturas[i];
                    }


                    // Conta temperaturas acima do limite

                    if (temperaturas[i] > limite) {

                        acimaDoLimite++;
                    }
                }


                media = soma / count;


                printf("Temperatura limite: %.2f C\n", limite);

                printf("Quantidade de temperaturas: %d\n", count);

                printf("Temperatura media: %.2f C\n", media);

                printf("Maior temperatura: %.2f C\n", maior);

                printf("Menor temperatura: %.2f C\n", menor);

                printf("Temperaturas acima do limite: %d\n",
                       acimaDoLimite);


                printf("\nTemperaturas registradas:\n");

                for (int i = 0; i < count; i++) {

                    printf("%d - %.2f C\n",
                           i + 1,
                           temperaturas[i]);
                }


                printf("\n===== STATUS DO SISTEMA =====\n");

                if (alertaSeguranca) {

                    printf("ALERTA: MAQUINA DESLIGADA!\n");
                    printf("Motivo: 3 temperaturas consecutivas");
                    printf(" acima do limite.\n");

                } else {

                    printf("Sistema funcionando normalmente.\n");
                }


                system("pause");

                break;
            }


            // =========================================
            // CASE 4 - SAIR
            // =========================================

            case 4:

                printf("Saindo...\n");

                break;


            // =========================================
            // OPCAO INVALIDA
            // =========================================

            default:

                printf("Opcao invalida!\n");

                system("pause");

                break;
        }

    } while (opcao != 4);


    return 0;
}