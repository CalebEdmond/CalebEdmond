#include <stdio.h>
#include <string.h>
#include "alcanos.h"

#define MIN(a,b) (a)<(b)?(a):(b)

static void replace(char *buf, char *v, int off, int n)
{
    for (int i = 0; i < n; ++i)
        buf[off + i] = v[i];
}

void escribir_diagramas(const char *path)
{
    FILE *fp = fopen(path, "w");

    char hc[3] = "CH0";

    char lines[5][MAXIMO_DE_CARBONOS * 3 + 1];

    for (int i = 0; i < num_alcanos; i++)
    {
        int sp = 0, sup = 0, inf = 0;
        Alcano *a = &alcanos[i];
        memset(lines, ' ', sizeof(lines));
        int pre = 0;

        for (int j = 0; j < a->count; j++)
        {
            int hidrogenos = a->carbono[j].hidrogenos;
            int posicion = a->carbono[j].posicion;

            hc[2] = '0' + hidrogenos;

            switch (posicion)
            {
            case SUPERIOR:
                if (sup == 0)
                    lines[1][pre] = '|';

                replace(lines[0], hc, pre + sup, 3);
                sup += 3;
                break;

            case INFERIOR:
                if (inf == 0)
                    lines[3][pre] = '|';

                replace(lines[4], hc, pre + inf, 3);
                inf += 3;
                break;

            default:
                int d = MIN(hidrogenos+1, 3);
                replace(lines[2], hc, sp, d);
                pre = sp;
                sp += d;
                sup = 0;
                inf = 0;
                break;
            }
        }

        for (int i = 0; i < 5; i++)
        {
            char *line = lines[i];
            line[sp] = '\n';
            line[sp + 1] = 0;

            fputs(line, fp);
        }
        fputc('\n', fp);
    }

    fclose(fp);
}