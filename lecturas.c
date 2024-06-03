#include <stdio.h>
#include "lecturas.h"

int leerEnteroPositivo(char* mensaje){
    int valor;
    do {
        printf("%s", mensaje);
        scanf("%d", &valor);
    } while(valor <= 0);
    return valor;
}

int leerEntero(char* mensaje){
    int num;
    printf("%s", mensaje);
    scanf("%d", &num);
    return num;
}

int leerEnteroEntre(char* mensaje, int min, int max){
    int num;
    do {
        printf("%s", mensaje);
        scanf("%d", &num);
    } while(num < min || num > max);
    return num;
}

float leerFlotantePositivo(char* mensaje){
    float valor;
    do {
        printf("%s", mensaje);
        scanf("%f", &valor);
    } while(valor <= 0);
    return valor;
}

float leerFlotante(char* mensaje){
    float num;
    printf("%s", mensaje);
    scanf("%f", &num);
    return num;
}

float leerFlotanteEntre(char* mensaje, float min, float max){
    float num;
    do {
        printf("%s", mensaje);
        scanf("%f", &num);
    } while(num < min || num > max);
    return num;
}

char leerCaracter(char* mensaje){
    char caracter;
    printf("%s", mensaje);
    scanf(" %c", &caracter);  // Nota: Espacio antes de %c para consumir cualquier espacio en blanco
    return caracter;
}

float leerFlotanteMayorIgual(char* mensaje, float lim){
    float num;
    do {
        printf("%s", mensaje);
        scanf("%f", &num);
    } while(num < lim);
    return num;
}
