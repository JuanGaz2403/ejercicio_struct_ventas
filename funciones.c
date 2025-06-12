/*Se deas desarrollar un sistema de gestion de ventas de que tenga las siguientes funcionalidades, 
visualizar productos, crear venta, imprimir ventas, y buscar la venta, los atributos del producto son: nombre del cliente
, cedula, total de la venta, productos vendidos. Los atributos del producto serian, nombre del producto y precio, maximo 5 minimo 2. 
Atributos de la venta
1. nombre del cliente
2. cedula
3. total de 1 venta
4. total de productos vendidos
 */

#include <stdio.h>
#include <string.h>
#include "funciones.h"
#define MAX_PRODUCTOS 5
#define MIN_PRODUCTOS 2

void ingresarProducto(struct producto productos[], int *num_productos) {
    int cantidad;

    // Preguntar al usuario cuántos productos desea ingresar
    printf("Cuantos productos desea ingresar? (Minimo %d, Maximo %d): ", MIN_PRODUCTOS, MAX_PRODUCTOS);
    if (scanf("%d", &cantidad) != 1 || cantidad < MIN_PRODUCTOS || cantidad > MAX_PRODUCTOS) {
        printf("Entrada invalida. Por favor, ingrese un número entre %d y %d.\n", MIN_PRODUCTOS, MAX_PRODUCTOS);
        while (getchar() != '\n'); // Limpiar el buffer
        return; // Salir de la función si la entrada es inválida
    }

    // Validar si hay espacio suficiente para agregar los productos
    if (*num_productos + cantidad > MAX_PRODUCTOS) {
        printf("No hay espacio suficiente para agregar %d productos. Puede agregar hasta %d más.\n", 
               cantidad, MAX_PRODUCTOS - *num_productos);
        return; // Salir de la función si no hay espacio suficiente
    }

    // Ingresar los productos
    for (int i = 0; i < cantidad; i++) {
        struct producto nuevo_producto;
        printf("Ingrese el nombre del producto %d: ", i + 1);
        scanf("%19s", nuevo_producto.nombre); // Limitar a 19 caracteres para evitar desbordamiento
        printf("Ingrese el precio del producto %d: ", i + 1);
        if (scanf("%f", &nuevo_producto.precio) != 1) {
            printf("Entrada inválida. Por favor, ingrese un número válido.\n");
            while (getchar() != '\n'); // Limpiar el buffer
            i--; // Reintentar el ingreso del producto actual
            continue;
        }

        productos[*num_productos] = nuevo_producto;
        (*num_productos)++;
        printf("Producto %d agregado exitosamente.\n", i + 1);
    }

    printf("Todos los productos han sido ingresados exitosamente.\n");
    return; // Salir del bucle si se ingresaron todos los productos
}

void visualizarProductos(struct producto productos[], int num_productos) {
    if (num_productos == 0) {
        printf("No hay productos para mostrar.\n");
        return;
    }
    printf("Productos disponibles:\n");
    for (int i = 0; i < num_productos; i++) {
        printf("Producto %d: Nombre: %s, Precio: %.2f\n", i + 1, productos[i].nombre, productos[i].precio);
    }
}

void crearVenta(struct venta ventas[], struct producto productos[], int num_productos) {
    if (num_productos < MIN_PRODUCTOS) {
        printf("No hay suficientes productos para crear una venta. Mínimo %d productos requeridos.\n", MIN_PRODUCTOS);
        return;
    }

    printf("Ingrese el nombre del cliente: ");
    scanf("%s", ventas->nombre_C); 
    printf("Ingrese la cédula del cliente: ");
    scanf("%s", ventas->cedula); 

    ventas->total_venta = 0.0;
    ventas->total_productos_vendidos = 0;
    ventas->num_productos = 0;

    int opc;
    do {
        // Mostrar los productos disponibles
        printf("Productos disponibles:\n");
        for (int i = 0; i < num_productos; i++) {
            printf("%d. Nombre: %s, Precio: %.2f\n", i + 1, productos[i].nombre, productos[i].precio);
        }

        printf("Seleccione un producto para agregar a la venta (1-%d): ", num_productos);
        if (scanf("%d", &opc) != 1 || opc < 1 || opc > num_productos) {
            printf("Selección inválida. Por favor, ingrese un número válido.\n");
            while (getchar() != '\n'); // Limpiar el buffer
            opc = 0; // Reiniciar opc para evitar salir del bucle
        }
    } while (opc < 1 || opc > num_productos);

    ventas->productos[ventas->num_productos] = productos[opc - 1];
    ventas->total_venta += productos[opc - 1].precio;
    ventas->total_productos_vendidos++;
    ventas->num_productos++;

    printf("Producto agregado exitosamente a la venta.\n");
}

void imprimirVentas(struct venta ventas[], int num_ventas) {
    if (num_ventas == 0) {
        printf("No hay ventas para mostrar.\n");
        return;
    }
    printf("Ventas realizadas:\n");
    for (int i = 0; i < num_ventas; i++) {
        printf("Venta %d: Nombre del cliente: %s, Cédula: %s, Total de venta: %.2f, Productos vendidos: %d\n",
               i + 1, ventas[i].nombre_C, ventas[i].cedula, ventas[i].total_venta, ventas[i].total_productos_vendidos);
        printf("Productos vendidos:\n");
        for (int j = 0; j < ventas[i].num_productos; j++) {
            printf("Producto %d: Nombre: %s, Precio: %.2f\n", j + 1, ventas[i].productos[j].nombre, ventas[i].productos[j].precio);
        }
    }
}

void buscarVenta(struct venta ventas[], int num_ventas) {
    if (num_ventas == 0) {
        printf("No hay ventas para buscar.\n");
        return;
    }

    char cedula[20];
    printf("Ingrese la cédula del cliente para buscar la venta: ");
    scanf("%s", cedula);

    int encontrado = 0;
    for (int i = 0; i < num_ventas; i++) {
        if (strcmp(ventas[i].cedula, cedula) == 0) {
            printf("Venta encontrada:\n");
            printf("Nombre del cliente: %s, Cédula: %s, Total de venta: %.2f, Productos vendidos: %d\n",
                   ventas[i].nombre_C, ventas[i].cedula, ventas[i].total_venta, ventas[i].total_productos_vendidos);
            printf("Productos vendidos:\n");
            for (int j = 0; j < ventas[i].num_productos; j++) {
                printf("Producto %d: Nombre: %s, Precio: %.2f\n", j + 1, ventas[i].productos[j].nombre, ventas[i].productos[j].precio);
            }
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("No se encontró ninguna venta con la cédula proporcionada.\n");
    }
}

int menu() {
    int opcion;
    printf("Sistema de Gestión de Ventas\n");
    printf("1. Ingresar Productos\n");
    printf("2. Visualizar Productos\n");
    printf("3. Crear Venta\n");
    printf("4. Imprimir Ventas\n");
    printf("5. Buscar Venta\n");
    printf("6. Salir\n");
    scanf("%d", &opcion);
    return opcion;
}
