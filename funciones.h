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
#define MAX_PRODUCTOS 5
#define MIN_PRODUCTOS 2

struct producto
{
    char nombre[50];
    float precio;
};

struct venta
{
    char nombre_C[50];
    char cedula[20];
    float total_venta;
    int total_productos_vendidos;
    struct producto productos[MAX_PRODUCTOS];
    int num_productos; // Número actual de productos vendidos
};

int menu();
void ingresarProducto(struct producto productos[], int *num_productos);
void visualizarProductos(struct producto productos[], int num_productos);
void crearVenta(struct venta ventas[], struct producto productos[], int num_productos);
void imprimirVentas(struct venta ventas[], int num_ventas);
void buscarVenta(struct venta ventas[], int num_ventas);
