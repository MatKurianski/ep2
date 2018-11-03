# GLL Nodefy

## Descrição

Biblioteca para a criação automatizada de listas ligadas generalizadas seguindo a seguinte estrutura:

```C
typedef struct s {
    int tipo;

    union{
        int chave;
        struct s* sublista;
    };

    struct s* prox;
} NO;
```

## Uso

```C
nodefy(int* chs, int n);

//  chs*: Array.
//  n: Tamanho do Array.
//  retorna: NO* de início de uma lista generalizada. 
```

A criação se dá passando como parâmetro um array de inteiros. Para listas simples, basta inserir os valores em um array, que serão tratadas como chaves dos elementos. Para inserir sublistas, insira entre dois elementos do array de valores -1 e -2 as chaves dos elementos da sublista. 

ATENÇÃO: NÃO INSERIR ESTES DOIS INTEIROS COM ESSES VALORES NO ARRAY CASO NÃO QUEIRA CRIAR UMA SUBLISTA.

## Exemplos
Nota: Para os exemplos a seguir, considere B como -1 (Begin) e E como -2 (End). Aconselha-se definir estas letras como esses respectivos valores com o auxílio de #define.

```C
int a[] = {1, 2, 3, B, 5, E};
size_t n = sizeof(a)/sizeof(a[0]); // Aconselha-se para obter o tamanho do Array.

NO* arranjo = nodefy(a, n);
```

Retorna: lista generalizada de elementos de chave 1, 2, 3 e com uma sublista que contém um elemento de chave 5.

```C
int a[] = {B, E, B, 1, E, B, 2, 3, E};
size_t n = sizeof(a)/sizeof(a[0]); // Aconselha-se para obter o tamanho do Array.

NO* arranjo = nodefy(a, n);
```

Retorna: lista generalizada onde todos os elementos são sublistas, sendo a primeira vazia, a segunda contendo o elemento de chave 1 e a terceira contendo dois elementos de chave 2 e 3, respectivamente.