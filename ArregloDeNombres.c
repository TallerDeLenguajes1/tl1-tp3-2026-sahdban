#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MostrarPersonas(char *personas[]);
int BuscarNombre(char *personas[], int id);

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
    MostrarPersonas(V);
    int id1 = -1;
    int id2 = 6;
    int id3 = 0;

    BuscarNombre(V, id1);
    BuscarNombre(V, id2);
    BuscarNombre(V, id3);
}

void MostrarPersonas(char *personas[]){

    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", personas[i]);
    }
    
}

int BuscarNombre(char *personas[], int id){
    if (id < 0 || id > 4)
    {
        printf("no se encontro el valor buscado\n");
    } else {
        printf("%s\n", personas[id]);
    }
}