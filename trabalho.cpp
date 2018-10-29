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

    if (tipo == 1)
        resp -> chave = ch;
    else if (tipo == 2)
        resp -> sublista = NULL;
    return resp;
}

NO* duplicate (NO* p) {
    NO* resp = NULL;
    if (p) {
        resp = (NO*) malloc(sizeof(NO));
        resp->tipo = p->tipo;
        if (p->tipo == 1) resp->chave = p->chave;
        else resp -> sublista = duplicate(p->sublista);
    }
    resp = resp->prox;
    return resp;
}

//NO* getUltLin(NO* atual) {
//    NO* ult = NULL;
//    while (atual) {
//        if (atual->tipo == 1) ult = atual;
//        atual = atual->prox;
//    }
//    return ult;
//}

// o EP consiste em implementar esta funcao
NO* listarChaves(NO* entrada) {
//    NO* resp = duplicate(entrada);
//    NO* atual = entrada->prox;
//    NO* inicio = resp;
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

//    NO* ult = getUltLin(inicio);
//    atual = entrada;
//
//    int contador = 0;



//    NO* resp = NULL;
//
//    // sua rotina aqui (o exemplo cria apenas um elemento de chave 1)
//    resp = (NO*) malloc(sizeof(NO));
//    resp->chave = 1;
//    resp->prox = NULL;

    return inicio;

}

void exibir(NO* p) {
    while (p) {
        if (p->tipo == 1) printf("%i ", p->chave);
        else exibir(p->sublista);
        p = p-> prox;
    }
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
	push(&teste, 1, 1);
	NO* sub1 = push(&teste, 2, -1);
        push(&sub1->sublista, 1, 5);
        NO* sub2 = push(&sub1, 2, -1);
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

    NO* teste2 = duplicate(teste);
    exibir(teste);
    printf("\n");
    //exibir(teste);
	//teste = listarChaves(p);

	// e aqui vc deveria percorrer a lista teste para ver se ficou correta etc.
}

// por favor nao inclua nenhum código abaixo da função main()

