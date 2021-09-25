#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "alcanos.h"

void escribir_salida(const char *path); // definido en 'salida.c'
void escribir_diagramas(const char *path); // definido en 'diagramas.c'

int main()
{
    leer_alcanos("alcanos.txt");

    escribir_salida("salida.txt");
    escribir_diagramas("diagramas.txt");

#if 0
    printf("lineas: %d\n", num_alcanos);
    for (int i = 0; i < num_alcanos; i++)
    {
        printf("alcano numero %d\n", i + 1);
        imprimir_alcano(&alcanos[i]);
    }
#endif

    free(alcanos);
    return 0;
}
