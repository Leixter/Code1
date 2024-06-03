#include <string.h>
#include <stdio.h>
#include "funciones.h"

#define MaxProducto 1000
#define MaxNombre 60
#define MaxDatos 1000

void leerProducto(int canti, char productis[MaxProducto][MaxDatos]) {
    if (canti < MaxProducto && canti > 0) {
        for (int i = 0; i < canti; i++) {
            char nombre[MaxNombre];
            float precio;
            int cantidad;
            char datos[MaxDatos];
            printf("Escribe el nombre del producto %d: ", i + 1); 
            fgets(nombre, sizeof(nombre), stdin);//el fgets es un funcion que hace que guando lo usamos lee nombres y frases, pero pone un \n al final, por eso tenemos que eliminar eso despues
            nombre[strcspn(nombre, "\n")] = 0; // esta funcion busa el \n en toda la cadena y la remplaza por un valor nulo que es el 0

            printf("Ingrese el precio del producto %d: ", i + 1);
            scanf("%f", &precio);
            while (getchar() != '\n');
            printf("Ingrese la cantidad del producto %d: ", i + 1);
            scanf("%d", &cantidad);
            while (getchar() != '\n');
            // con esta funcion lo que hace es escribir un array de caracteres, como si fuera un printf pero en un array, se pone a donde o a que array quieres enviar y luego pones el tamaño, luego como si fuera un printf y listo.
            snprintf(datos, MaxDatos, "\nNombre: %s\nPrecio: %.2f\nCantidad: %d\n", nombre, precio, cantidad);

            // esta funcion solo copia los datos y los mada a productos [i] y por lo que esta en un bucle, cada dato va a un nuevo indice.
            strcpy(productis[i], datos);
        }
    } else {
        printf("Cantidad de productos no está correcta\n");
    }
}

void mostrarProductos(int canti, char productis[MaxProducto][MaxDatos]) {
    for (int i = 0; i < canti; i++) {
        printf("\n\nProducto %d:%s\n", i + 1, productis[i]);
    }
}

void editarProducto(int indice, char productis[MaxProducto][MaxDatos]) {
    if (indice >= 0 && indice < MaxProducto) {
        char nombre[MaxNombre];
        float precio;
        int cantidad;
        char datos[MaxDatos];
        printf("Escribe el nuevo nombre del producto %d: ", indice + 1);
        getchar(); //esta funcion es para limpiar el buffer (aun no entiendo bien esto, averiguar)
        fgets(nombre, sizeof(nombre), stdin);
        nombre[strcspn(nombre, "\n")] = 0; 

        printf("Ingrese el nuevo precio del producto %d: ", indice + 1);
        scanf("%f", &precio);

        printf("Ingrese la nueva cantidad del producto %d: ", indice + 1);
        scanf("%d", &cantidad);


        snprintf(datos, MaxDatos, "\nNombre: %s\nPrecio: %.2f\nCantidad: %d\n", nombre, precio, cantidad);


        strcpy(productis[indice], datos);
    } else {
        printf("Índice de producto no válido\n");
    }
}

void eliminarProducto(int indice, char productis[MaxProducto][MaxDatos], int *cantidad) {
    if (indice >= 0 && indice < *cantidad) {
        for (int i = indice; i < *cantidad - 1; i++) {
            strcpy(productis[i], productis[i + 1]);
        }
        (*cantidad)--;
    } else {
        printf("Índice de producto no válido\n");
    }
}