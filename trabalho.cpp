#include "ep.h"

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

    if (tipo == 1) {
        resp -> chave = ch;
        printf("%i", resp -> chave);
    } else if (tipo == 2) {
        resp -> sublista = NULL;
    }

    return resp;
}

// o EP consiste em implementar esta funcao
NO* listarChaves(NO* entrada) {
    NO* resp = NULL;

    // sua rotina aqui (o exemplo cria apenas um elemento de chave 1)
    resp = (NO*) malloc(sizeof(NO));
    resp->chave = 1;
    resp->prox = NULL;

    return resp;

}





//---------------------------------------------------------
// use main() para fazer chamadas de teste ao seu programa
//---------------------------------------------------------



int main() {

	NO* p = NULL;

	// aqui vc pode incluir codigo para inserir elementos
	// de teste na sua lista apontada por p

	// o EP sera testado com chamadas deste tipo
	NO* teste = NULL;
	push(&teste, 1, 5);
	push(&teste, 1, 1);
	NO* sub1 = push(&teste, 2, 5);
	push(&sub1, 1, 6);
	// e aqui vc deveria percorrer a lista teste para ver se ficou correta etc.
}

// por favor nao inclua nenhum código abaixo da função main()
