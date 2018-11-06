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

NO* copiarListaGen(NO* p) {
  NO* novo;
  NO* abaixo;
  NO* dir;
  int tipo;
  novo = NULL;
  if (p) {
    tipo = p->tipo;
    if( tipo == 2)
      abaixo = copiarListaGen(p->sublista);
      dir = copiarListaGen(p->prox);
      novo = (NO *) malloc(sizeof(NO));
      novo->tipo = tipo;
      novo->prox = dir;
    if( tipo == 1)
      novo->chave = p->chave;
    else
      novo->sublista = abaixo;
  }
  return(novo);
}

NO* getUltLin(NO* atual) {
    NO* ult = NULL; 
    while (atual->prox) atual = atual->prox;
    ult = atual;
    return ult;
}

NO* reconfigurarLista(NO* entrada) {
  bool fim = false;
  NO* atual = entrada;
  NO* ult = getUltLin(entrada);
  
  while(atual) {
    if (atual->tipo == 2) {
      if (atual->sublista) {
        ult->prox = atual->sublista;
        atual->sublista = NULL;
        ult = getUltLin(ult);
      }
    }
    atual = atual->prox;
  }

  atual = entrada;
  NO* inicio = NULL;
  NO* antTipo1 = NULL;
  NO* aux;

  while(atual) {
    if (atual->tipo == 2) {
      aux = atual;
      atual = atual->prox;
      free(aux);
      continue;
    } else {
      if (!antTipo1) {
        antTipo1 = atual;
        inicio = antTipo1;
      } else {
        antTipo1->prox = atual;
        antTipo1 = antTipo1->prox;
      }
    }
    atual = atual->prox;
  }

  if(antTipo1) antTipo1->prox = NULL;
  return inicio;
}

// o EP consiste em implementar esta funcao
NO* listarChaves(NO* entrada) {
  NO* nova = copiarListaGen(entrada);
  return reconfigurarLista(nova);
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

