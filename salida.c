#include <stdio.h>

void escribir_salida(const char *path)
{
    FILE *fp = fopen(path, "w");

    fclose(fp);
}
