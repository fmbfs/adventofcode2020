/* LIBRARIES */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* MARCROS */
#define TAM   50

/* GLOBAL VARIABLES */

/* STRUCTS */
typedef struct dados
{
    int min;
    int max;
    char letra[2];
    char pass[TAM];
}dados_t;

/* HEADERS */


/* MAIN */
int main (void)
{
    FILE *arq = fopen("dados_p2.txt", "rb");
    char chr;
    register int i = 0, j = 0, cnt = 0, resultado = 0;
    unsigned long linesCount = 0;

    dados_t *info;

    /* Conta o numero de linhas do ficheiro */
    while((chr = fgetc(arq))!=EOF) if(chr=='\n') linesCount++;
    char arr[linesCount];
    rewind(arq);


    for(i = 0; i < linesCount; i++)
    {
        fgets(arr, sizeof(arr), arq);
        cnt = 0;

        /* guarda os valores até ao delimitador */
        info->min = atoi(strtok(arr, "-"));
        info->max = atoi(strtok(NULL, " "));

        strcpy(info->letra, strtok(NULL, ":"));
        strcpy(info->pass, strtok(NULL, "\n"));

        /* imprime o conteudo da estrutura so para verificacao*/
        printf("%d", info->min);
        printf("-%d ", info->max);
        printf("%s:", info->letra);
        printf("%s", info->pass);
        puts("");

        /* conta quantas vezes a letra existe na password */
        for(j = 0; info->pass[j] != '\0'; j++) if(info->letra[0] == info->pass[j]) cnt++;

        /* verificacao dos limites */
        if(cnt >= info->min && cnt <= info->max)
        {
            printf("Pass valida %d\n", cnt);
            resultado++;
        }
        else printf("Pass invalida %d\n", cnt);

        puts("");
    }
    printf("\nTOTAL DE VALIDAS: %d\n", resultado);


    fclose(arq);
    return 0;
}

/* FUNCTIONS */
