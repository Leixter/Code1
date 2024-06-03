#define MaxProducto 1000
#define MaxNombre 60
#define MaxDatos 1000
void leerProducto(int canti, char productis[MaxProducto][MaxDatos]);
void mostrarProductos(int canti, char productis[MaxProducto][MaxDatos]);
void editarProducto(int indice, char productis[MaxProducto][MaxDatos]);
void eliminarProducto(int indice, char productis[MaxProducto][MaxDatos], int *cantidad);