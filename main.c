#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "abb.h"
#include "gamebook.h"

typedef struct output
{
    int id;
    char *txt;
} Output;

typedef struct no
{

    Output dado;
    struct no *esq;
    struct no *dir;
} No;

int main()
{
    // Cria as estruturas de dados iniciais e as variáveis
    Output dado;
    No *arvore;
    char select;
    create(&arvore);

    // Insere o prólogo no início da árvore
    dado.id = PROLOGO;
    gbchapter(&dado);
    insert(&arvore, dado);

    gbload(&arvore, &dado);

    do
    {
        refresh();
        if (dado.id == PROLOGO)
        {
            gbprintf(RED BOLD, TITULO);
            gbprintf(WHITE, dado.txt);
            dado.id = CAP1;
            gbchapter(&dado);
            insert(&arvore, dado);
            printf("\n");
            system("Pause");
        }
        else if (dado.id == FINAL)
        {
            gbprintf(BOLD WHITE, dado.txt);
            gbprintf(BOLD RED, "\n\n\tObrigado por jogar!\n\n");
            system("Pause");
            while (1)
                gbquit(&arvore);
            return 0;
        }
        else if (gbverifyBranch(dado.id))
        {
            gbprintf(BOLD WHITE, dado.txt);
            gbscanf(&arvore, &dado, &select);
        }
        else
        {
            gbprintf(BOLD WHITE, dado.txt);
            printf("\n");
            system("Pause");
            break;
        }
    } while (select != '0');

    if (select == '0')
    {
        gbsave(&arvore);
        gbquit(&arvore);
        printf("\n\n");
        system("Pause");
    }
    return 0;
}
