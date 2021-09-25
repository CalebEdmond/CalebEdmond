#include <stdio.h>
#include <stdlib.h>
#include "alcanos.h"

Alcano *alcanos;
int num_alcanos;

const char *sustituyente[] = {"metil", "etil", "protil", "butil", "pentil"};

void parsear(FILE *fp, int n); // definido en 'parsear.c'

void decrecer_hidrogeno(Alcano *a) {
    int count = a->count;
    a->carbono[count-1].hidrogenos--;
}

void leer_alcanos(const char *path)
{
    FILE *fp = fopen(path, "r");

    fscanf(fp, "%d\n", &num_alcanos);

    alcanos = crear_alcanos(num_alcanos);

    parsear(fp, num_alcanos);
}

Alcano *crear_alcanos(int n) {
    Alcano *alcanos = malloc(sizeof(Alcano) * n);

    for (int i = 0; i < n; i++)
        alcanos[i].count = 0;

    return alcanos;
}

void agregar_carbono(Alcano *alc, int hidrogenos, int position)
{
    int i = alc->count;
    alc->carbono[i].hidrogenos = hidrogenos;
    alc->carbono[i].posicion = position;
    alc->count++;
}

void imprimir_alcano(Alcano *a)
{
    const char chrs[3] = "psi";
    for (int i = 0; i < a->count; i++)
    {
        printf("%d %c\n", a->carbono[i].hidrogenos, chrs[a->carbono[i].posicion]);
    }
}