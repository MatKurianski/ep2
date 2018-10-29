#include "ep.h"
#define B -1
#define E -2

// ######### ESCREVA O NUMERO DO SEU GRUPO AQUI, CONFORME LINK NA ESPECIFICACAO DO EP
// ignore os warning to compilador, se houver
char* grupo() {
    return("00");
}

// ######### ESCREVA O NROUSP DO PRIMEIRO INTEGRANTE AQUI
// ignore os warning to compilador, se houver
char* nroUSP1() {
    return("0000000");
}

// ######### ESCREVA O NROUSP DO SEGUNDO INTEGRANTE AQUI (OU DEIXE COM ZERO)
// ignore os warning to compilador, se houver
char* nroUSP2() {
    return("0000000");
}

NO* push (NO* *lista, int tipo, int ch) {
    NO* resp = (NO*) malloc(sizeof(NO));
    resp -> prox = NULL;
    resp -> tipo = tipo;

    if (*lista == NULL) {
        *lista = resp;
    } else {
        NO* atual = *lista;
        while (atual->prox) atual = atual->prox;
        atual->prox = resp;
    }

    if (tipo == 1)
        resp -> chave = ch;
    else if (tipo == 2)
        resp -> sublista = NULL;
    return resp;
}

NO* create(int* chs, int j, int n) {
    NO* p = NULL;
    int i = j;
    for (i; i < n; i++) {
        //printf("%i\n", chs[i]);
        if (chs[i] == -1) {
            NO* psub = push(&p, 2, -10);
            psub->sublista = create(chs, i+1, n);
            while (chs[i] != -2) i++;
            chs[i] = NULL;
        } else if (chs[i] == -2 && j != 0) {
            return p;
        } else push(&p, 1, chs[i]);
    }
    return p;
}

NO* duplicate (NO* p) {
    NO* resp = NULL;
    if (p) {
        resp = (NO*) malloc(sizeof(NO));
        resp->tipo = p->tipo;
        if (p->tipo == 1) resp->chave = p->chave;
        else resp ->sublista = duplicate(p->sublista);
        resp->prox = duplicate(p->prox);
    }
    return resp;
}

NO* getUltLin(NO* atual, bool requireCh) {
    NO* ult = NULL;
    while (atual) {
        if (requireCh)
            if(atual->tipo == 1) ult = atual;
        else ult = atual;
        atual = atual->prox;
    }
    if(ult) printf("%i", ult->tipo);
    return ult;
}

void exibir(NO* p) {
    while (p) {
        if (p->tipo == 1) printf("%i ", p->chave);
        else {
            printf("[sub] ");
            exibir(p->sublista);
            printf("[fim_sub]");
        }
        p = p-> prox;
    }
}

// o EP consiste em implementar esta funcao
NO* listarChaves(NO* entrada) {
    //printf("Chamada!\n");
    NO* atual = entrada;
    NO* resp = NULL;
    NO* inicio = NULL;
    while (atual) {
        if (atual->tipo == 1) {
            if (!resp) {
                resp = duplicate(atual);
                inicio = resp;
            } else {
                resp -> prox = duplicate(atual);
                resp = resp -> prox;
            }
        }
        atual = atual->prox;
    }

    NO* ult = getUltLin(inicio, true);


    atual = entrada;

    if (ult == NULL) {
        inicio = duplicate(atual->sublista);
        NO* aux = inicio;
        atual = atual->prox;
        while (atual) {
            aux->prox = duplicate(atual->sublista);
            atual = atual->prox;
            aux = aux->prox;
        }
    }


    int contador = 0;

    while(atual) {
        if (atual->tipo == 2) {
            ult->prox = duplicate(atual->sublista);
            contador++;
            while (ult->prox) ult = ult->prox;
        }
        atual = atual->prox;
    }
    if (contador > 0) inicio = listarChaves(inicio);
    return inicio;
}




//---------------------------------------------------------
// use main() para fazer chamadas de teste ao seu programa
//---------------------------------------------------------



int main() {

	NO* p = NULL;

	NO* teste = NULL;
	push(&teste, 1, 1);
	NO* sub1 = push(&teste, 2, -1);
        push(&sub1->sublista, 1, 5);
        NO* sub2 = push(&sub1->sublista, 2, -1);
            push(&sub2->sublista, 1, 8);
    push(&teste, 1, 2);
    NO* sub3 = push(&teste, 2, -1);
        push(&sub3->sublista, 1, 6);
        NO* sub4 = push(&sub3->sublista, 2, -1);
            NO* sub5 = push(&sub4->sublista, 2, -1);
                push(&sub5, 1, 9);
                push(&sub5->sublista, 1, 10);
    push(&teste, 1, 3);
    NO* sub7 = push(&teste, 2, -1);
        push(&sub7->sublista, 1, 7);
    push(&teste, 1, 4);
    NO* debug = push(&teste, 2, 5);
    push(&debug->sublista, 1, 12);

    int a[] = {B, 5 ,E, B, 5, E, B, 5, E, B, 5, E};

    size_t n = sizeof(a)/sizeof(a[0]);
    NO* teste3 = create(a, 0, n);

    exibir(teste3);
    printf("\n");
    exibir(listarChaves(teste3));
}

// por favor nao inclua nenhum código abaixo da função main()

