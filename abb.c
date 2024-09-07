#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb.h"

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

void create(No **t)
{
    *t = NULL;
}

int insert(No **t, Output dado)
{

    if (*t == NULL)
    {
        *t = (No *)malloc(sizeof(No));
        if (*t == NULL)
            return 0;

        (*t)->dado = dado;
        (*t)->esq = NULL;
        (*t)->dir = NULL;

        return 1;
    }

    if (dado.id < (*t)->dado.id)
        return insert(&(*t)->esq, dado);

    return insert(&(*t)->dir, dado);
}

No *getRightBranch(No **t)
{
    if ((*t)->dir != NULL) // enquanto nao chegar no No mais a direita, vou descendo para a direita
        return getRightBranch(&(*t)->dir);

    No *aux = *t;
    if ((*t)->esq != NULL) // se meu no escolhido tiver um filho a esquerda
        *t = (*t)->esq;    // eu movo ele para a sua antiga posicao
    else
        *t = NULL; // se o escolhido nao tem filho, entao quem esta apontando pra ele deve apontar pra NULL

    return aux; // devolvo o no escolhido
}

No *viewRightBranch(No **t)
{
    if ((*t)->dir != NULL) // enquanto nao chegar no No mais a direita, vou descendo para a direita
        return getRightBranch(&(*t)->dir);
    No *aux = *t;
    return aux;
}

int cut(No **t, int id)
{

    if (*t == NULL)
        return 0;

    if (id < (*t)->dado.id)
        return cut(&(*t)->esq, id);

    if (id > (*t)->dado.id)
        return cut(&(*t)->dir, id);

    No *aux = *t;

    if (((*t)->esq == NULL) && ((*t)->dir == NULL))
    {
        *t = NULL;
        free(aux);
        return 1;
    }

    if ((*t)->dir == NULL)
    {
        *t = (*t)->esq;
        free(aux);
        return 1;
    }

    if ((*t)->esq == NULL)
    {
        *t = (*t)->dir;
        free(aux);
        return 1;
    }

    No *overwrite = getRightBranch(&(*t)->esq);
    overwrite->esq = (*t)->esq;
    overwrite->dir = (*t)->dir;
    *t = overwrite;
    free(aux);
    return 1;
}

void preOrdem(No *t)
{

    if (t != NULL)
    {
        printf("%s\n\n", t->dado.txt);
        preOrdem(t->esq);
        preOrdem(t->dir);
    }
}

void emOrdem(No *t)
{

    if (t != NULL)
    {
        emOrdem(t->esq);
        printf("%s\n\n", t->dado.txt);
        emOrdem(t->dir);
    }
}

void posOrdem(No *t)
{

    if (t != NULL)
    {
        posOrdem(t->esq);
        posOrdem(t->dir);
        printf("%s\n\n", t->dado.txt);
    }
}