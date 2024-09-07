#ifndef _GAMEBOOK_H
#define _GAMEBOOK_H

// Struct utilizada
typedef struct output Output;
typedef struct no No;

// Códigos de cores ANSI
#define RESET "\x1b[0m"
#define WHITE "\x1b[37m"
#define RED "\x1b[31m"
#define BOLD "\x1b[1m"

// Título do livro-jogo
#define TITULO "Livro-jogo: A Sombra sob Ravenshire\n\n"

// Definição dos ID's dos Capítulos
#define PROLOGO 0x001
#define CAP1 0x1100
#define CAP2 0x2200
#define CAP3 0x3300
#define CAP4 0x4400
#define CAP5 0x5500
#define CAP6 0x6600
#define CAP7 0x7700
#define FINAL 0x8800
#define MORTE1 0x10FF
#define MORTE2 0x21FF
#define MORTE3 0x32FF
#define MORTE4 0x43FF
#define MORTE5 0x54FF
#define MORTE6 0x65FF
#define MORTE7 0x76FF

// Aloca dinamicamente uma string através de um ponteiro de tipo char
void strmalloc(char **str, char txt[]);

// Melhoria ao printf, permitindo o uso de cores e exibição de texto gradual
void gbprintf(const char *color, const char *str);

// Um 'banco de dados', de acordo com o id ele retorna um capítulo do livro-jogo
void gbchapter(Output *data);

// Um 'banco de dados', de acordo com o id ele retorna as opções de escolha de um capítulo
void gbbranch(int id, char **str1, char **str2);

// Função auxiliar que executa a função gbbranch com as opções de escolha randomizadas, retornando qual opção é a correta
int gbselect(int id, char **str1, char **str2);

// Função que recebe o id seguinte da historia, de acordo com a variável n (0 pra morte, 1 pra prosseguimento)
void gbprogress(Output *data, int n);

// Executa uma lista em ordem da árvore e a remove por inteiro.
void gbquit(No **t);

// Limpa a tela e pula a linha inicial do terminal.
void refresh();

// Imprime e lê as opções que o usuário deseja escolher no ramo de decisões, e atualiza a estrutura de dados de acordo com a decisão.
void gbscanf(No **t, Output *data, char *select);

// Função auxiliar pra verificar se o id passado por parâmetro é um id de um capítulo que possui ramo de decisão.
int gbverifyBranch(int id);

// Salva o id do capítulo atual em um arquivo binário.
void gbsave(No **t);

// Carrega toda a estrutura e continua o livro-jogo de acordo com o arquivo de salvamento binário
int gbload(No **t, Output *data);

#endif