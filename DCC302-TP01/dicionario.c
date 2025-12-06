#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dicionario.h"

// Cria um nó de ocorrência
Ocorrencia* criarOcorrencia(int linha) {
    Ocorrencia* novo = malloc(sizeof(Ocorrencia));
    novo->linha = linha;
    novo->qtd = 1;
    novo->prox = NULL;
    return novo;
}

// Cria um nó de palavra
Palavra* criarPalavra(const char* texto, int linha) {
    Palavra* p = malloc(sizeof(Palavra));
    p->texto = strdup(texto);
    p->ocorrencias = criarOcorrencia(linha);
    p->prox = NULL;
    return p;
}

// Insere palavra em ordem alfabética
void inserirPalavra(Palavra** dicionario, const char* texto, int linha) {
    Palavra *atual = *dicionario, *anterior = NULL;
    
    while (atual != NULL && strcmp(atual->texto, texto) < 0) {
        anterior = atual;
        atual = atual->prox;
    }
    
    if (atual != NULL && strcmp(atual->texto, texto) == 0) {
        // Atualiza ocorrência
        Ocorrencia* oc = atual->ocorrencias;
        while (oc != NULL) {
            if (oc->linha == linha) {
                oc->qtd++;
                return;
            }
            if (oc->prox == NULL) break;
            oc = oc->prox;
        }
        oc->prox = criarOcorrencia(linha);
    } else {
        // Insere nova palavra
        Palavra* nova = criarPalavra(texto, linha);
        if (anterior == NULL) {
            nova->prox = *dicionario;
            *dicionario = nova;
        } else {
            nova->prox = atual;
            anterior->prox = nova;
        }
    }
}

// Imprime índice invertido
void imprimirIndice(Palavra* dicionario) {
    while (dicionario != NULL) {
        printf("%s :", dicionario->texto);
        Ocorrencia* oc = dicionario->ocorrencias;
        while (oc != NULL) {
            printf(" (%d,%d)", oc->linha, oc->qtd);
            oc = oc->prox;
        }
        printf("\n");
        dicionario = dicionario->prox;
    }
}

// Busca palavra no dicionário
Palavra* buscarPalavra(Palavra* dicionario, const char* texto) {
    while (dicionario != NULL) {
        if (strcmp(dicionario->texto, texto) == 0) return dicionario;
        dicionario = dicionario->prox;
    }
    return NULL;
}

// Exclui palavra do dicionário
int excluirPalavra(Palavra** dicionario, const char* texto) {
    Palavra *atual = *dicionario, *anterior = NULL;
    while (atual != NULL && strcmp(atual->texto, texto) != 0) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual == NULL) return 0; // não encontrou

    // Remove ocorrências
    Ocorrencia* oc = atual->ocorrencias;
    while (oc != NULL) {
        Ocorrencia* temp = oc;
        oc = oc->prox;
        free(temp);
    }

    if (anterior == NULL) *dicionario = atual->prox;
    else anterior->prox = atual->prox;

    free(atual->texto);
    free(atual);
    return 1;
}

// Retorna palavra mais frequente
char* palavraMaisFrequente(Palavra* dicionario) {
    Palavra* p = dicionario;
    Palavra* maisFreq = NULL;
    int max = 0;

    while (p != NULL) {
        int total = 0;
        Ocorrencia* oc = p->ocorrencias;
        while (oc != NULL) {
            total += oc->qtd;
            oc = oc->prox;
        }
        if (total > max) {
            max = total;
            maisFreq = p;
        }
        p = p->prox;
    }
    return (maisFreq) ? maisFreq->texto : NULL;
}

// Libera memória do dicionário
void liberarDicionario(Palavra* dicionario) {
    while (dicionario != NULL) {
        Palavra* tempP = dicionario;
        dicionario = dicionario->prox;

        Ocorrencia* oc = tempP->ocorrencias;
        while (oc != NULL) {
            Ocorrencia* tempO = oc;
            oc = oc->prox;
            free(tempO);
        }
        free(tempP->texto);
        free(tempP);
    }
}
