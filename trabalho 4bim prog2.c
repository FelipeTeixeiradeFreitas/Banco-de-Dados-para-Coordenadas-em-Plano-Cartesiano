#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */
#include <math.h> /* sqrt */
#include <string.h>

struct ponto {
    float x;
    float y;
    struct ponto *proximo;
    struct ponto *anterior;
};

typedef struct ponto Ponto;
 
void menu()
{
	printf("MENU\n 1-listar\n 2-remove ultimo\n 3-inserir\n 4-navegar\n 10-sair\n\n");
}

void menu_navegar()
{
	printf("MENU NAVEGAR\n 1 - navegar para a esquerda\n 2 navegar para direita\n 3-remover\n 0 - sair do menu navegar\n\n");
}


void removerNav(Ponto **listaPontos2)
{
	char remov[50];
	printf("Deseja remover?\n");
	printf("%f\n", (*listaPontos2)->x);
	printf("%f\n", (*listaPontos2)->y);
	printf("se deseja remover digite 'sim'\n");
	scanf("%s", remov);
	if (strcmp("sim", remov)==0)
	{
		printf("cond1\n");
		if((*listaPontos2)->x==3)
        { 
    	    printf("nao eh possivel apagar esse no\n");
    	    return;
	    }
	    Ponto *anter;
	    Ponto *prox;
	    anter=(*listaPontos2)->anterior;
	    prox=(*listaPontos2)->proximo;
        anter->proximo = prox;
        prox->anterior=anter;
        free(*listaPontos2);
    }
}



void navega(Ponto *listaPontos)
{
	
	int opcaoNav=10;
	while(opcaoNav!=0)
	{
	menu_navegar();
	printf("informe a opcao desejada\n");
	scanf("%d", &opcaoNav);
	if(opcaoNav==1)
	{
		listaPontos=listaPontos->anterior;
		/*if(listaPontos!=NULL)
		{
        printf("X: %f\n", listaPontos->x);
        printf("Y: %f\n", listaPontos->y);}
        else{
        	printf("inicio\n");
		}*/
		if(listaPontos->anterior==NULL)
		{
			printf("X: %f\n", listaPontos->x);
            printf("Y: %f\n", listaPontos->y);
            listaPontos=listaPontos->proximo;
		}
		else
		{
			printf("X: %f\n", listaPontos->x);
            printf("Y: %f\n", listaPontos->y);
		}
	}
	if(opcaoNav==2)
	{
		listaPontos=listaPontos->proximo;
        printf("X: %f\n", listaPontos->x);
        printf("Y: %f\n", listaPontos->y);
	}
    if(opcaoNav==3)
	{
		removerNav(&listaPontos);
	}
    }
}



Ponto* pto_cria (float x, float y) {
    Ponto* p = malloc(sizeof(Ponto));
    if (p == NULL) {
        printf("Memória insuficiente!\n");
        exit(1);
    }

    p->x = x;
    p->y = y;
    p->proximo = NULL;
    p->anterior=NULL;

    return p;
}

void pto_libera (Ponto* p) {
    free(p);
}

void pto_acessa (Ponto* p, float* x, float* y) {
    *x = p->x;
    *y = p->y;
}

void pto_atribui (Ponto* p, float x, float y) {
    p->x = x;
    p->y = y;
}

float pto_distancia (Ponto* p1, Ponto* p2) {
    float dx = p2->x-p1->x;
    float dy = p2->y-p1->y;
    return sqrt(dx*dx + dy*dy);
}

/*void mostra_distancia(Ponto *listaPontos)
{
	float x, y;
	while(listaPontos=!NULL)
	{
		pto_distancia(x,y)
	}
}*/
/*
void insere_pontos(Ponto **listaPontos, int x, int y)
{
    Ponto *aux = NULL;
    Ponto *novo = pto_cria(x, y);
    if(*listaPontos == NULL)
    {
        *listaPontos = novo;
    }
    else
    {
        aux = *listaPontos;
        while(aux->proximo!=NULL)
        {
            aux = aux->proximo;
        }
        aux->proximo = novo;
        novo->anterior=aux;
    }
}*/


void insere_pontos(Ponto **listaPontos, int x, int y)
{
    Ponto *aux;
    Ponto *novo = pto_cria(x, y);
    
    if(*listaPontos == NULL)
    {
        *listaPontos = novo;
        novo->proximo=novo;
        novo->anterior=novo;
    }
    else
    {
        aux = *listaPontos;
        while(aux->proximo!=(*listaPontos))
        {
            aux = aux->proximo;
        }
        aux->proximo = novo;
        novo->anterior=aux;
        (*listaPontos)->anterior=novo;
        novo->proximo=(*listaPontos);
    }
}



void lista_pontos(Ponto *listaPontos)
{
	Ponto *aux;
	printf("X:%f \n", listaPontos->x);
		printf("Y:%f\n\n", listaPontos->y);
		aux=listaPontos;
		aux=aux->proximo;
	while(aux->proximo!=listaPontos)
	{
		printf("X:%f \n", aux->x);
		printf("Y:%f\n\n", aux->y);
		aux=aux->proximo;
	}
}
/*
void remove_ultimo(Ponto **listaPontos)
{
    Ponto *ant = NULL;
    Ponto *aux = *listaPontos;
    if (*listaPontos == NULL)
        return;

    while(aux->proximo!=NULL)
    {
        ant = aux;
        aux = aux->proximo;
    }
    if (ant != NULL)
    {
        ant->proximo = NULL;
        free(aux);
    }
}*/


void remove_ultimo(Ponto **listaPontos)
{
    Ponto *ant=(*listaPontos);
    Ponto *aux=(*listaPontos);
    aux=aux->proximo;
    if (*listaPontos == NULL)
        return;

    while(aux!=(*listaPontos)->anterior)
    {
        ant = aux;
        aux = aux->proximo;
    }
    if (ant != (*listaPontos))
    {
        ant->proximo = (*listaPontos);
        (*listaPontos)->anterior=ant;
        free(aux);
    }
}


void pilha_push (Ponto** p, float x, float y)
{

}

void pilha_pop (Ponto** p, float *x, float *y)
{

}

int main()
{
	int opcao;
    Ponto *listaPontos1 = NULL;
    float x, y;

    x = 3;
    y = 4;

    // Exemplo de uso das funções
    while(x<10)
    {
        insere_pontos(&listaPontos1, x, y);
        x++;
        y++;
    }
while(opcao!=10)
{
	menu();
	printf("informe a opcao desejada\n");
	scanf("%d", &opcao);
	if(opcao==1)
	{
		lista_pontos(listaPontos1);
	}
	if(opcao==2)
	{
		remove_ultimo(&listaPontos1);
	}
	if(opcao==3)
	{
		insere_pontos(&listaPontos1, x, y);
        x++;
        y++;
	}
	if(opcao==4)
	{
		navega(listaPontos1);
	}
}
    
    

    printf("\nApos ultimo removido:\n");
    
    /*while(opcao!=10)
    {
    lista_pontos(listaPontos1);

    mostra_distancia(listaPontos1);
    }*/

    return 0;
}

