#include "libTrabalho.h"
/*
 * aloca string com parametro de tamanho dela e retorna ponteiro para memoria
 * lembrar de desalocar
 */
char *alocaString(int size)
{
    char *st = NULL;
    st = (char *)malloc(size * sizeof(char));
    if (st == NULL)
    {
        printf("\nMemória insuficiente - função alocaString\n");
    }
    return st;
}
