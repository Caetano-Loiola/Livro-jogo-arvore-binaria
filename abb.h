#ifndef _ABB_H
#define _ABB_H

// Structs utilizadas
typedef struct output Output;
typedef struct no No;

// funcoes de manipulacao
void create(No **t);
int insert(No **t, Output dado);
No *getRightBranch(No **t);
int cut(No **t, int id);

// funcoes de visualizacao
void preOrdem(No *t);
void emOrdem(No *t);
void posOrdem(No *t);
No *viewRightBranch(No **t);
#endif