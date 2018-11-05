#include "ep.h"
#include "lib/debug.h"
#include <time.h>

// ######### ESCREVA O NUMERO DO SEU GRUPO AQUI, CONFORME LINK NA ESPECIFICACAO DO EP
// ignore os warning to compilador, se houver
char* grupo() {
    return("09");
}

// ######### ESCREVA O NROUSP DO PRIMEIRO INTEGRANTE AQUI
// ignore os warning to compilador, se houver
char* nroUSP1() {
    return("10687541");
}

// ######### ESCREVA O NROUSP DO SEGUNDO INTEGRANTE AQUI (OU DEIXE COM ZERO)
// ignore os warning to compilador, se houver
char* nroUSP2() {
    return("10687882");
}

void destruirLista(NO* p) {
    NO* aux;
    while (p) {
        aux = p;
        if(p->tipo == 2) destruirLista(p->sublista);
        p = p-> prox;
        free(aux);
    }
}

NO* copiarTipo1 (NO* p) {
    NO* resp = NULL;
    if (p) {
        if (p->tipo == 1) {
            resp = (NO*) malloc(sizeof(NO));
            resp->tipo = p->tipo;
            resp->chave = p->chave;
            resp->prox = NULL;
        }
    }
    return resp;
}

NO* copiarTipo2 (NO* p) {
    NO* resp = NULL;
    if (p) {
        resp = (NO*) malloc(sizeof(NO));
        resp->tipo = p->tipo;
        if (p->tipo == 1) resp = copiarTipo1(p);
        else resp ->sublista = copiarTipo2(p->sublista);
        resp->prox = copiarTipo2(p->prox);
    }
    return resp;
}

NO* getUltLin(NO* atual) {
    NO* ult = NULL;
    while (atual) {
        if(atual->tipo == 1) ult = atual;
        atual = atual->prox;
    }
    return ult;
}

// o EP consiste em implementar esta funcao
NO* listarChaves(NO* entrada) {

    NO* atual = entrada;
    NO* resp = NULL;
    NO* inicio = NULL;

    while (atual) {
        if (atual->tipo == 1) {
            if (!resp) {
                resp = copiarTipo1(atual);
                inicio = resp;
            } else {
                resp -> prox = copiarTipo1(atual);
                resp = resp -> prox;
            }
        }
        atual = atual->prox;
    }

    atual = entrada;
    int contador = 0;

    if (inicio == NULL) {
        contador++;
        NO* aux = NULL;
        while (atual) {
            if (!inicio) {
                inicio = copiarTipo2(atual->sublista);
                aux = inicio;
                if (!aux) {
                    atual = atual->prox;
                    continue;
                }
                while(aux->prox) aux = aux->prox;
                atual = atual->prox;
                continue;
            }
            aux->prox = copiarTipo2(atual->sublista);
            atual = atual->prox;
            while(aux->prox) aux = aux->prox;
        }
    }

    if (!inicio) return NULL;

    NO* ult = getUltLin(inicio);
    while(atual) {
        if (atual->tipo == 2) {
            ult->prox = copiarTipo2(atual->sublista);
            contador++;
            while (ult->prox) ult = ult->prox;
        }
        atual = atual->prox;
    }
    if (contador > 0) {
        NO* aux = inicio;
        inicio = listarChaves(inicio);
        destruirLista(aux);
    }
    return inicio;
}


//---------------------------------------------------------
// use main() para fazer chamadas de teste ao seu programa
//---------------------------------------------------------


int main() {
    int a[] = {1, B, 5, B, 8, E, E, 2, B, 6, B, B, 10, E, 9, E, E, 3, B, 7, E, 4};

    size_t n = sizeof(a)/sizeof(a[0]);
    NO* arranjo = nodefy(a, n);

    printf("Remodelada: ");
    exibir(listarChaves(arranjo));
    printf("\n\nOriginal: ");
    exibir(arranjo);
    printf("\n");

    return 0;
}

// por favor nao inclua nenhum c�digo abaixo da fun��o main()

