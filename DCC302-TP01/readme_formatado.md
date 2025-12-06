# Trabalho Prático 01 - DCC302
## Índice Invertido Simplificado

### Objetivo
Implementar uma versão simplificada de um índice invertido utilizado em motores de busca.

---

### Entrada
Um arquivo no formato `.txt` contendo várias strings em várias linhas.

**Exemplo:** Um arquivo com frases, cada uma em uma linha diferente.

---

### Requisitos

1. **Leitura e Dicionário:** Ler o arquivo e construir um dicionário com todas as palavras distintas.

2. **Lista Encadeada:** Para cada palavra, criar uma lista encadeada (ou duplamente encadeada) com nós que armazenem:
   - **A)** O número da linha onde a palavra aparece
   - **B)** A quantidade de ocorrências nessa linha

3. **Estrutura do Dicionário:** Deve ser dinamicamente alocada e organizada em ordem alfabética.

4. **TADs e Estruturas Dinâmicas:** É obrigatório o uso de TADs e de estruturas dinâmicas (não pode usar structs globais ou vetores de tamanho fixo).

---

### Descrição de Funcionamento

O algoritmo implementado deve varrer o texto e criar um vetor contendo a lista de palavras (sem repetições) encontradas no arquivo inteiro (esse é o dicionário). 

Cada palavra do dicionário deve apontar para uma lista encadeada. Cada nó da lista encadeada deve possuir as informações sobre a linha e a quantidade de vezes que a palavra apareceu nesta linha. 

Se a palavra do dicionário aparecer em mais de uma linha, a lista encadeada deve apresentar um nó para cada uma dessas linhas.

---

### Saída do Programa

O programa deve imprimir no terminal a lista invertida criada a partir do arquivo texto dado como entrada, no seguinte formato:

```
Palavra1 : (X,Y), (X,Y)...
Palavra2 : (X,Y), (X,Y)...
```

Onde:
- **X** = número da linha
- **Y** = quantidade de vezes que a palavra apareceu na linha indicada

---

### Funcionalidades Extras (Obrigatórias)

- ✅ Implementar busca de palavra no índice (entrada pelo teclado)
- ✅ Permitir exclusão de uma palavra do índice e atualização das listas
- ✅ Calcular e exibir a palavra mais frequente no texto