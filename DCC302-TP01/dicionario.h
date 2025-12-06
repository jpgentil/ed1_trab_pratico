#ifndef DICIONARIO_H
#define DICIONARIO_H

typedef struct Ocorrencia {
    int linha;
    int qtd;
    struct Ocorrencia* prox;
} Ocorrencia;

typedef struct Palavra {
    char* texto;
    Ocorrencia* ocorrencias;
    struct Palavra* prox;
} Palavra;

Palavra* criarPalavra(const char* texto, int linha);
Ocorrencia* criarOcorrencia(int linha);
void inserirPalavra(Palavra** dicionario, const char* texto, int linha);
void imprimirIndice(Palavra* dicionario);
Palavra* buscarPalavra(Palavra* dicionario, const char* texto);
int excluirPalavra(Palavra** dicionario, const char* texto);
char* palavraMaisFrequente(Palavra* dicionario);
void liberarDicionario(Palavra* dicionario);

#endif
