# Trabalho prático de Estrutura de Dados 1

Este projeto foi desenvolvido como trabalho prático para a disciplina Estrutura de Dados 1, ministrada pelo professor Filipe Dwan Pereira (UFRR). 
É a implementação de um índice invertido simplificado, a estrutura completa é utilizada em motores de busca para mapear palavras aos locais onde aparecem em um documento.

#### Participantes: 
  - João Paulo Gentil Ferreira
  - Gabriel Mineiro Brandão
  - Gabriel Guilherme Figueiredo

---

### Estrutura:
O projeto foi dividido em 4 arquivos principais:
  - `dicionario.h`     → Interface do TAD (tipos e assinaturas)
  - `dicionario.c`      → Implementação das operações do TAD
  - `main.c`            → Leitura do arquivo + integração geral
  - `teste.txt`       → Arquivo para teste do programa

---

### Como executar:

Se você tiver o GCC instalado (via MinGW ou WSL no Windows), basta rodar os dois comandos a seguir no terminal do VS Code: 

1. gcc -o programa main.c dicionario.c
2. ./programa
