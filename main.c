#include <stdio.h>
#include <string.h>
#include "funciones.h"
#define MAX_PRODUCTOS 5
#define MIN_PRODUCTOS 2


int main() {
    struct producto productos[MAX_PRODUCTOS];
    struct venta ventas[MAX_PRODUCTOS];
    int num_productos = 0;
    int num_ventas = 0;
    int opc;

    do {
        opc = menu(); // Actualizar la opción en cada iteración del bucle
        switch (opc) {
            case 1:
                ingresarProducto(productos, &num_productos);
                break;
            case 2:
                visualizarProductos(productos, num_productos);
                break;
            case 3:
                crearVenta(&ventas[num_ventas], productos, num_productos);
                if (num_ventas < MAX_PRODUCTOS) {
                    num_ventas++;
                } else {
                    printf("Límite de ventas alcanzado.\n");
                }
                break;
            case 4:
                imprimirVentas(ventas, num_ventas);
                break;
            case 5:
                buscarVenta(ventas, num_ventas);
                break;
            case 6:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción inválida. Por favor, intente de nuevo.\n");
        }
    } while (opc != 6);

    return 0;
}
