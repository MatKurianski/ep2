#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

using namespace std;

typedef struct s {
    int tipo; //1=elemento 2=sublista

    union{
        int chave;
        struct s* sublista;
    };

    struct s* prox;

} NO;

char* nroUSP1();
char* nroUSP2();
char *grupo();



