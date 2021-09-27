/* LIBRARIES */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* MACROS */


/* GLOBAL VARIABLES */

/* STRUCTS */

/* HEADERS */

/* MAIN */
int main(void)
{
    unsigned long linesCount = 0;
    register int i = 0, j = 0, z = 0;
    char chr;

	FILE *arq = fopen("dados.txt", "rb");

    while((chr = fgetc(arq))!=EOF) if(chr=='\n') linesCount++;
    rewind(arq); /* ponteiro retorna ao início do arquivo */

    unsigned long arr[linesCount];


    for (i = 0; i < linesCount+1; i++) fscanf(arq, "%lu,", &arr[i] );

    for (i = 0; i < linesCount+1; i++)
    {
        for (j = 0; j < linesCount+1; j++)
                if(arr[i] + arr[j] == 2020)
                {
                    printf("%lu ", arr[i] * arr[j]);
                    exit(0);
                }
    }

    fclose(arq);

 return 0;
}
