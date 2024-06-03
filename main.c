#include <stdio.h>
#include <string.h>
#include "funciones.h"
#include "lecturas.h"

#define MaxProducto 1000
#define MaxNombre 60
#define MaxDatos 1000


int main(void) {
    int cantidadProduct;
    char Productos[MaxProducto][MaxDatos];
    int opcion;
    int indice;

    printf("           Bienvenidos a TuTienda\n");
    printf("Cantidad de productos a ingresar (máximo %d): ", MaxProducto);
    scanf("%d", &cantidadProduct);
    getchar(); 

    leerProducto(cantidadProduct, Productos);

    do {
        printf("\nMenu:\n");
        printf("1. Mostrar productos\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Salir\n\n");
        printf("Seleccione una opción: ");
        scanf("%d\n", &opcion);
        printf("\n\n");

        switch (opcion) {
            case 1:
                mostrarProductos(cantidadProduct, Productos);
                break;
            case 2:
                printf("Ingrese el producto a editar (1-%d): ", cantidadProduct);
                scanf("%d", &indice);

                editarProducto(indice - 1, Productos);
                break;
            case 3:
                printf("Ingrese el producto a eliminar (1-%d): ", cantidadProduct);
                scanf("%d", &indice);

                eliminarProducto(indice - 1, Productos, &cantidadProduct);
                break;
            case 4:
                printf("Salendo...\n");
                break;
            default:
                printf("Opción no válida\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}
