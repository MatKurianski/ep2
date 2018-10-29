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

NO* getUltLin(NO* atual) {
    NO* ult = NULL;
    while (atual) {
        if(atual->tipo == 1) ult = atual;
        atual = atual->prox;
    }
    return ult;
}

void exibir(NO* p) {
    while (p) {
        if (p->tipo == 1) printf("%i ", p->chave);
        else {
            printf("[I] ");
            exibir(p->sublista);
            printf("[F] ");
        }
        p = p-> prox;
    }
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
    int a[] = {1, B, 5, B, 8, E, E, 2, B, 6, B, B, 10, E, 9, E, E, 3, B, 7, E, 4};

    size_t n = sizeof(a)/sizeof(a[0]);
    NO* arranjo = create(a, 0, n);

    exibir(arranjo);
    printf("\n");
    exibir(listarChaves(arranjo));
}

// por favor nao inclua nenhum código abaixo da função main()

