#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dicionario.h"

void menu() {
    printf("\n=== MENU ===\n");
    printf("1 - Buscar palavra\n");
    printf("2 - Excluir palavra\n");
    printf("3 - Imprimir indice completo\n");
    printf("4 - Palavra mais frequente\n");
    printf("5 - Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    FILE* arquivo = fopen("teste.txt", "r");
    if (!arquivo) {
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    Palavra* dicionario = NULL;
    char linha[256];
    int numLinha = 1;

    while (fgets(linha, sizeof(linha), arquivo)) {
        char* token = strtok(linha, " \t\n,.!?;:");
        while (token) {
            for (int i = 0; token[i]; i++) token[i] = tolower(token[i]);
            inserirPalavra(&dicionario, token, numLinha);
            token = strtok(NULL, " \t\n,.!?;:");
        }
        numLinha++;
    }
    fclose(arquivo);

    int opcao;
    char palavra[50];

    do {
        menu();
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {
            case 1:
                printf("Digite a palavra para buscar: ");
                scanf("%s", palavra);
                for (int i = 0; palavra[i]; i++) palavra[i] = tolower(palavra[i]);

                Palavra* p = buscarPalavra(dicionario, palavra);
                if (p) {
                    printf("%s :", p->texto);
                    Ocorrencia* oc = p->ocorrencias;
                    while (oc != NULL) {
                        printf(" (%d,%d)", oc->linha, oc->qtd);
                        oc = oc->prox;
                    }
                    printf("\n");
                } else {
                    printf("Palavra '%s' nao encontrada.\n", palavra);
                }
                break;

            case 2:
                printf("Digite a palavra para excluir: ");
                scanf("%s", palavra);
                for (int i = 0; palavra[i]; i++) palavra[i] = tolower(palavra[i]);

                if (excluirPalavra(&dicionario, palavra)) {
                    printf("Palavra '%s' excluida com sucesso.\n", palavra);
                } else {
                    printf("Palavra '%s' nao encontrada.\n", palavra);
                }
                break;

            case 3:
                imprimirIndice(dicionario);
                break;

            case 4: {
                char* maisFreq = palavraMaisFrequente(dicionario);
                if (maisFreq)
                    printf("Palavra mais frequente: %s\n", maisFreq);
                else
                    printf("Dicionario vazio.\n");
                break;
            }

            case 5:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while(opcao != 5);

    liberarDicionario(dicionario);
    return 0;
}