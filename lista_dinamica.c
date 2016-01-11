#include "lista_dinamica.h"

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

Lista *cria_lista(){
    Lista *li = (Lista *) malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

void libera_lista(Lista *li){
    if(li != NULL){
        Elem *no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
            free(no);
        }
        free(li);
    }
}

int tamanho_lista(Lista *li){
    if(li == NULL)
        return 0;
    int count = 0;
    Elem *no = *li;
    while(no != NULL){
        count++;
        no = no->prox;
    }
    return count;
}

int lista_vazia(Lista *li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

int insere_inicio_lista(Lista *li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*li);
    *li = no;
    return 1;
}
int insere_final_lista(Lista *li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL)
        *li = no;
    else{
        Elem *aux = *li;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = no;
    }
    return 1;
}

int insere_meio_lista(Lista *li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    if(lista_vazia(li)){
        no->prox = (*li);
        *li = no;
        return 1;
    }
    else{
        Elem *ant, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = ant->prox;
            ant->prox = no;
        }
    }
    return 1;
}

int remove_inicio_lista(Lista *li){
    if(li == NULL)
        return 0;
    Elem *no, *store;
    no = *li;
    no = no->prox;
    store = *li;
    free(store);
    *li = no;
    return 1;
}

int remove_final_lista(Lista *li){
    if(li == NULL)
        return 0;
    Elem *no, *store;
    no = *li;
    while(no->prox != NULL){
        store = no;
        no = no->prox;
    }
    if(no == (*li))
        *li = no->prox;
    else
        store->prox = no->prox;
    free(no);
    return 1;
}

int remove_meio_lista(Lista *li, int mat){
    if(li == NULL)
        return 0;
    Elem *no = *li, *store;
    while(no->prox != NULL && no->dados.matricula != mat){
        store = no;
        no->prox;
    }
    if(no == NULL) return 0;
    if(no == (*li))
        *li = no->prox;
    else
        store->prox = no->prox;
    free(no);
    return 1;
}

void Preenche(struct aluno *al){
    getchar();
    printf("\nNome do aluno: ");
    gets(al->nome);

    printf("Matricula: ");
    scanf("%d", &al->matricula);

    printf("Nota 1: ");
    scanf("%f", &al->n1);

    printf("Nota 2: ");
    scanf("%f", &al->n2);

    printf("Nota 3: ");
    scanf("%f", &al->n3);
    printf("\nAluno Inserido com sucesso!!!");
    printf("\n\n=============================================================\n\n");
}

void consulta_aluno(Lista *li){
    struct aluno al;
    int i, tam = tamanho_lista(li);
    Elem *no = (*li);
    for(i = 0; i < tam; i++){
        al = no->dados;
        printf("\n\tExibindo aluno\n");
        printf("Nome: %s \n", al.nome);
        printf("Matricula: %d \n", al.matricula);
        printf("Notas: %.1f \t %.1f \t %.1f \n", al.n1, al.n2, al.n3);
        printf("\n\n=============================================================\n\n");
        no = no->prox;
    }
}

int main(){
    int flag = -1;
    Lista *l = cria_lista();
    while(flag != 0){
        printf("\n\t\t\t====Opções====");
        printf("\n0 - Sair");
        printf("\n1 - Inserir no final da lista");
        printf("\n2 - Inserir no inicio da lista");
        printf("\n3 - Inserir no meio da lista");
        printf("\n4 - Remover no final da lista");
        printf("\n5 - Remover no inicio da lista");
        printf("\n6 - Remover no meio da lista");
        printf("\n7 - Consulta alunos inseridos");
        printf("\n\n=============================================================\n\n");
        printf("\n\nDigite uma opção: ");
        scanf("%d", &flag);

        struct aluno al;
        if(flag == 1 || flag == 2 || flag == 3)
            Preenche(&al);
        int result;
        if(flag == 1)
            result = insere_final_lista(l, al);
        if(flag == 2)
            result = insere_inicio_lista(l, al);
        if(flag == 3)
            result = insere_meio_lista(l, al);
        if(flag == 4)
            result = remove_final_lista(l);
        if(flag == 5)
            result = remove_inicio_lista(l);
        if(flag == 6){
            int mat;
            printf("\nEntre com a matricula do aluno que deseja remover. ");
            scanf("%d", &mat);
            result = remove_meio_lista(l, mat);
        }
        if(flag == 7){
            consulta_aluno(l);
        }
    }
    getchar();
    return 0;
}

