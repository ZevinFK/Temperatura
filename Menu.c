#include <stdio.h>
#include <stdlib.h>

int main() {
   int opcao; 
   float limite;
   float temperaturas[3];
   int count = 0;
   
    do{
            system("cls");
            printf("\n=====Temperature=====\n");
            printf("\n1. Definir Temperatura Limite\n"); 
            printf("\n2. Adicionar Valor a Temperatura\n"); 
            printf("\n3. Mostrar resultados\n");
            printf("\n4. Sair\n");
            printf("\n=====================\n");
            scanf("%d", &opcao);
            system("cls");
            printf("\nOpção Selecionada:  %d\n", opcao);

        switch (opcao) {

            case 1:
                printf("Defina a Temperatura Limite para prosseguir:  ");
                scanf("%f", &limite);

                while (limite < 0 || limite > 75) {
                    printf("Temperatura Inválida!\n");
                    printf("Digite novamente:  ");
                    scanf("%f", &limite);
                }
            break;
            
            case 2: {
 
                printf("De 0 a 3\nQuantos valores deseja adicionar?:  ");
                scanf("%d", &count);
                system("cls");

                while (count <= 0 || count > 3){
                    printf("Quantidade inválida ou não permitida\n");
                    printf("Digite novamente:  ");
                    scanf("%d", &count);
                }
                
                for (int i = 0; i < count; i++) {
                        printf("Digite a temperatura %d: ", i + 1);
                        scanf("%f", &temperaturas[i]);
                        system("cls");

                        while(temperaturas[i] < 0 || temperaturas[i] > 75){
                            printf("Temperatura inválida!\n");
                            printf("Digite novamente:  ");
                            scanf("%f", &temperaturas[i]);
                            system("cls");
                        }
                    }
                    break; 
            }  
            case 3:
                printf("Temperaturas Registradas:  \n");
                for (int i = 0; i < count; i++) {
                    printf("%.2f°C\n", temperaturas[i]);
                }
            system("pause");   
            break;
            
            case 4:  
                printf("Saindo...") ;
            break;

            default:
                printf("Opção inválida!\n");
                
        }
    } while (opcao != 4);
    

    return 0;
}

