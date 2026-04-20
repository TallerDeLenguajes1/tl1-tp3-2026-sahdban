#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *TiposProductos[] = {"Galeltas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

typedef struct
{
    int ProductoID;
    int Cantidad;
    char *tipoProducto;
    float PrecioUnitario;
}Producto;

typedef struct
{
    int ClienteID;
    char *NombreCliente;
    int CantidadProcudtoAPedir;
    Producto *Productos;
}Cliente;

float costoProducto(Producto producto);
void liberarCliente(Cliente clientes);

int main(){
    int cantClientes;
    printf("Ingresar la cantidad de clientes: ");
    scanf("%d", &cantClientes);
    Cliente *Clientes; 
    Clientes = (Cliente *)malloc(sizeof(Cliente) * cantClientes);
    char buffer[20];
    printf("\nIngrese el nombre de los clientes 1 a 1: \n");
    float *costoTotal;
    costoTotal = malloc(sizeof(float) * cantClientes);
    for (int i = 0; i < cantClientes; i++)
    {
        scanf("%s", buffer);
        Clientes[i].NombreCliente = malloc(sizeof(char) * strlen(buffer));
        strcpy(Clientes[i].NombreCliente, buffer);
        Clientes[i].ClienteID = i;
        Clientes[i].CantidadProcudtoAPedir = (rand() % 5) + 1;
        Clientes[i].Productos = (Producto *)malloc(sizeof(Producto) * Clientes[i].CantidadProcudtoAPedir);
        costoTotal[i] = 0;
        for (int j = 0; j < Clientes[i].CantidadProcudtoAPedir; j++)
        {
            Clientes[i].Productos[j].ProductoID = j;
            Clientes[i].Productos[j].Cantidad = (rand() % 10) + 1;
            Clientes[i].Productos[j].tipoProducto = malloc(sizeof(char) * strlen(TiposProductos[j]));
            strcpy(Clientes[i].Productos[j].tipoProducto, TiposProductos[j]);
            Clientes[i].Productos[j].PrecioUnitario = (rand() % 91) + 10;
            costoTotal[i] += costoProducto(Clientes[i].Productos[j]);
        }
    }
    for (int i = 0; i < cantClientes; i++)
    {
        printf("Id del cliente: %d\n", Clientes[i].ClienteID);
        printf("Nombre del cliente: %s\n", Clientes[i].NombreCliente);
        printf("Cantidad de productos del cliente %d\n", Clientes[i].CantidadProcudtoAPedir);
        printf("A continuacion los productos del cliente\n\n");
        for (int j = 0; j < Clientes[i].CantidadProcudtoAPedir; j++)
        {
            printf("Id del producto: %d\n", Clientes[i].Productos[j].ProductoID);
            printf("cantidad del producto: %d\n", Clientes[i].Productos[j].Cantidad);
            printf("tipo del producto: %s\n", Clientes[i].Productos[j].tipoProducto);
            printf("precio unitario del producto: %f\n", Clientes[i].Productos[j].PrecioUnitario);
        }
        printf("\nTotal a pagar por el cliente: %f\n", costoTotal[i]);
    }
    
    for (int i = 0; i < cantClientes; i++)
    {
        liberarCliente(Clientes[i]);
    }
    free(Clientes);    
    free(costoTotal);

    return 0;
}

float costoProducto(Producto producto){
    float precio = producto.Cantidad * producto.PrecioUnitario;
    return precio;
}

void liberarCliente(Cliente clientes){
    for (int i = 0; i < clientes.CantidadProcudtoAPedir; i++)
    {
        free(clientes.Productos[i].tipoProducto);
    }
    free(clientes.Productos);
}