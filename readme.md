# Teoria dos Grafos | Instituto de Computação (UFAL)

## Descrição 
Este projeto apresenta a implementação de cinco algoritmos fundamentais de Teoria dos Grafos, abordados na disciplina. Cada algoritmo foi desenvolvido com o objetivo de resolver problemas específicos relacionados a grafos, como cálculo de caminhos mínimos, árvores geradoras mínimas e análise de componentes fortemente conexas.

## Alunos
- Davi Melo
- Josué Medino da Silva

## Algoritmos Implementados

1. **Algoritmo de Prim**
   - Constrói a árvore geradora mínima de um grafo conectado e ponderado, selecionando as arestas de menor peso enquanto evita ciclos.

2. **Algoritmo de Dijkstra**
   - Encontra o caminho mais curto de um vértice origem para todos os outros vértices em um grafo com arestas de pesos não negativos.

3. **Algoritmo de Kruskal**
   - Determina a árvore geradora mínima de um grafo conectado e ponderado, ordenando as arestas pelo peso e adicionando-as progressivamente enquanto evita ciclos.

4. **Algoritmo de Carraghan-Pardalos**
   - Resolve o problema de clique máximo, identificando o maior conjunto de vértices mutuamente conectados em um grafo.

5. **Algoritmo de Kosaraju**
   - Identifica componentes fortemente conectadas em grafos direcionados, utilizando uma abordagem baseada em duas passagens do grafo.

## Tecnologias Utilizadas
- Linguagem : C++

## Como Executar

1. Clone este repositório:
   ```bash
   git clone https://github.com/DsML01/Grafos-Algoritmos.git

2. Navegue para o diretório do algorítimo específico
   ```bash
   cd <DIRETÓRIO>

3. Executando o algorítimo
   ```bash
   make all