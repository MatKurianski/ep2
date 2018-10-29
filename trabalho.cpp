#include "ep.h"
#include "debug.h"

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

    NO* ult = getUltLin(inicio);
    atual = entrada;
    int contador = 0;

    if (inicio == NULL) {
        contador++;
        NO* aux = NULL;
        while (atual) {
            if (!inicio) {
                inicio = duplicate(atual->sublista);
                aux = inicio;
                atual = atual->prox;
                continue;
            }
            aux->prox = duplicate(atual->sublista);
            atual = atual->prox;
            aux = aux->prox;
        }
    }

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
    int a[] = {B, B, B, B, B, 1, E, E, E, E, E};

    size_t n = sizeof(a)/sizeof(a[0]);
    NO* arranjo = create(a, 0, n);

    exibir(arranjo);
    printf("\n");
    exibir(listarChaves(arranjo));
}

// por favor nao inclua nenhum c�digo abaixo da fun��o main()

