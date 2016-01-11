#include <stdio.h>
#include <stdlib.h>

struct aluno{
    int matricula;
    char nome[70];
    float n1, n2, n3;
};

typedef struct elemento *Lista;


Lista *cria_lista();

void libera_lista(Lista *li);

int tamanho_lista(Lista *li);

int lista_vazia(Lista *li);

int insere_inicio_lista(Lista *li, struct aluno al);

int insere_final_lista(Lista *li, struct aluno al);

int insere_meio_lista(Lista *li, struct aluno al);

int remove_inicio_lista(Lista *li);

int remove_final_lista(Lista *li);

int remove_meio_lista(Lista *li, int matricula);

void Preenche(struct aluno *al);

void consulta_aluno(Lista *li);
