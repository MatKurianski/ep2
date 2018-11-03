#include "ep.h"
#include "lib/debug.h"

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
                resp = duplicate(atual);
                inicio = resp;
            } else {
                resp -> prox = duplicate(atual);
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
                inicio = duplicate(atual->sublista);
                aux = inicio;
                if (!aux) {
                    atual = atual->prox;
                    continue;
                }
                while(aux->prox) aux = aux->prox;
                atual = atual->prox;
                continue;
            }
            aux->prox = duplicate(atual->sublista);
            atual = atual->prox;
            while(aux->prox) aux = aux->prox;
        }
    }

    if (!inicio) return NULL;

    NO* ult = getUltLin(inicio);
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
    int a[] = {1, B, 5, B, 8, E, E, 2, B, 6, B, B, 10, E, 9, E, E, 3, B, 7, E, 4};

    size_t n = sizeof(a)/sizeof(a[0]);
    NO* arranjo = nodefy(a, n);

    exibir(arranjo);
    printf("\n");
    exibir(listarChaves(arranjo));
}

// por favor nao inclua nenhum c�digo abaixo da fun��o main()

