#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "alcanos.h"

enum
{
    TOK_NONE,
    TOK_SUPURIOR,
    TOK_INFERIOR,
    TOK_AMBOS,
};

void parsear(FILE *fp, int n)
{
    const int conv[] = {NINGUNO, SUPERIOR, INFERIOR, SUPERIOR};
    int i = 0, chr;
    bool gato = false;

    int tok = TOK_NONE;

    while ((chr = fgetc(fp)) != EOF && i < n)
    {
        if (chr == '#')
        {
            if (tok == TOK_NONE)
            {
                fprintf(stderr, "error: no se encuentra prensente el sustituyente");
                exit(1);
            }

            if (gato)
            {
                if (tok != TOK_AMBOS)
                    agregar_carbono(&alcanos[i], 2, NINGUNO);

                gato = false;
                tok = tok == TOK_AMBOS ? TOK_INFERIOR : TOK_NONE;
            }
            else
            {
                gato = true;
            }
        }
        else if (chr >= '2' && chr <= '3')
            agregar_carbono(&alcanos[i], chr - '0', conv[tok]);
        else if (chr == '\n')
            i++;
        else if (chr == '-' && tok < TOK_INFERIOR)
        {
            decrecer_hidrogeno(&alcanos[i]);
            tok |= TOK_INFERIOR;
        }
        else if (chr == '+' && tok == TOK_NONE)
        {
            decrecer_hidrogeno(&alcanos[i]);
            tok = TOK_SUPURIOR;
        }
        else
        {
            fprintf(stderr, "error: operacion invalida '%c'\n", chr);
            exit(1);
        }

        putchar(chr);
    }
}
