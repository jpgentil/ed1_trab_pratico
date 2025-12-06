Para executar:

Se você tiver o GCC instalado (via MinGW ou WSL no Windows), basta rodar os dois comandos a seguir no terminal do VS Code: 

1. gcc -o programa main.c dicionario.c
2. /programa

---

Objetivo: O trabalho consiste em implementar uma versão simplificada de um índice invertido utilizado em motores de busca. 

Entrada: Um arquivo no formato .txt, contendo várias strings em várias linhas. (exemplo: um arquivo com frases, cada uma em uma linha diferente)

Requisitos: 

1. Ler o arquivo e construir um dicionário com todas as palavras distintas.
2. Para cada palavra, criar uma lista encadeada (ou duplamente encadeada) com nós que armazenem:
A) o número da linha onde a palavra aparece; 
B) a quantidade de ocorrências nessa linha.
3. A estrutura do dicionário deve ser dinamicamente alocada e organizada em ordem alfabética. 
4. É obrigatório o uso de TADs e de estruturas dinâmicas (não pode usar struct globais ou vetores de tamanho fixo).

Descrição de funcionamento:

O algoritmo implementado deve varrer o texto e criar um vetor contendo a lista de palavras (sem repetições) encontradas no arquivo inteiro (esse é o dicionário). Cada palavra do dicionário deve apontar para uma lista encadeada. Cada nó da lista encadeada deve possuir as informações sobre a linha e a quantidade de vezes que a palavra apareceu nesta linha. Se a palavra do dicionário aparecer em mais de uma linha, a lista encadeada deve apresentar um nó para cada uma dessas linhas.

Saída do Programa:

O programa deve imprimir no terminal a lista invertida criada a partir do arquivo texto dado como entrada, no seguinte formato:
Palavra1 : (X,Y), (X,Y)... 
Palavra2 : (X,Y), (X,Y)
Onde X e Y são o numero da linha e a quantidade de vezes que a palavra apareceu na linha indicada, respectivamente.

Extras (obrigatórios): 
-- Implementar busca de palavra no índice (entrada pelo teclado).
-- Permitir exclusão de uma palavra do índice e atualização das listas.

-- Calcular e exibir a palavra mais frequente no texto.

