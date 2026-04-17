#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MostrarPersonas(char *personas[]);

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

}

void MostrarPersonas(char *personas[]){

    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", personas[i]);
    }
    
}