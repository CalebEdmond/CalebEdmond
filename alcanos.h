#ifndef _ALCANOS_H_
#define _ALCANOS_H_

#define MAXIMO_DE_CARBONOS 32

enum
{
    NINGUNO,
    SUPERIOR,
    INFERIOR
};

typedef struct alcano_s
{
    int count;
    struct
    {
        int hidrogenos;
        int posicion;
    } carbono[MAXIMO_DE_CARBONOS];
} Alcano;

// Nombre de cada sustituyente
extern const char *sustituyente[];
extern Alcano *alcanos;
extern int num_alcanos;

void agregar_carbono(Alcano*, int, int);
void decrecer_hidrogeno(Alcano*);
void leer_alcanos(const char *path);

Alcano *crear_alcanos(int n);
void imprimir_alcano(Alcano*); // solo por motivos de testeo, favor de ignorar


#endif