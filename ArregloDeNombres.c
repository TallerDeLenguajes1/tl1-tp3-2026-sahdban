#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MostrarPersonas(char *personas[]);
int BuscarNombreClave(char *personas[], char palabra[]);
int BuscarNombreID(char *personas[], int id);

int main(){

    char *V[5];
    char buffer[20];
    printf("Ingrese los nombres a continuacion: ");
    for (int i = 0; i < 5; i++)
    {
        scanf("%s",buffer);
        int tam = strlen(buffer);
        V[i] = malloc(sizeof(char)*tam);
        strcpy(V[i], buffer);
    }

    printf("Ingrese la accion que desea realizar: \n1_Busqueda por ID\n2_Busqueda por palabra\n");
    int opcion = 0;
    scanf("%d", &opcion);
    if (opcion == 1){
        printf("ingrese la ID: ");
        int id;
        scanf("%d", &id);
        int busqueda = BuscarNombreID(V, id);
    } 
    if (opcion == 2) {
        printf("ingrese la clave: ");
        char clave[20];
        scanf("%s", clave);
        int busqueda = BuscarNombreClave(V, clave);
        if (busqueda != -1) printf("%s", V[busqueda]);
    }

}

void MostrarPersonas(char *personas[]){

    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", personas[i]);
    }
    
}

int BuscarNombreClave(char *personas[], char palabra[]){
    for (int i = 0; i < 5; i++)
    {
        if (strstr(personas[i], palabra) != NULL)
        {
            return i;
        }
    }
    return -1;
}

int BuscarNombreID(char *personas[], int id) {
    if (id < 0 || id > 4)
    {
        printf("no se encontro el valor buscado\n");
    } else {
        printf("%s\n", personas[id]);
    }
    return 1;
}