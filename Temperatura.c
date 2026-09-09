#include <stdio.h>

int main(){
    float temperatura;
    
    printf("Iniciando monitoramento de temperatura...\n");
    printf("Digite a temperatura em graus celsius:  ");
    scanf("%f", &temperatura);
    
    while (temperatura < 80) {
        printf("Temperatura atual: %.1f °C\n", temperatura);
        printf("Digite a temperatura (°C):  ");
        scanf("%f", temperatura);
        break;
    }
    printf("\nALERTA: temperatura acima do limite!\n");
    return 0;
}