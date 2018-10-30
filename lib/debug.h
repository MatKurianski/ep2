#define B -1
#define E -2

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

NO* nodefy(int* chs, int n) {
  int b = 0;
  int e = 0;
  int i;
  for (i = 0; i < n; i++) {
    if (chs[i] == -1) b++;
    if (chs[i] == -2) e++;
  }
  if(b != e) {
    NO* p = (NO*) malloc(sizeof(NO));
    p->tipo = 1;
    p->chave = -1;
    p->prox = NULL;
    return p;
  }
  return create(chs, 0, n);
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
