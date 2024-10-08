#include <bits/stdc++.h>

using namespace std;

void bfs(vector<vector<int>> grafo, vector<int> &pai, int vertice_inicial, vector<int> &pre)
{
    int cont = 0;

    vector <int> dist(grafo.size(), INT_MAX);

    queue<int> fila;

    fila.push(vertice_inicial);

    dist[vertice_inicial] = 0;

    //enquanto a fila não estiver vazia
    while(!(fila.empty()))
    {
        //pega o primeiro elemento sem tirar da fila
        int w = fila.front();

        pre[w] = cont++;

        fila.pop();

        //for vizinho in grafo[w]
        for(auto vizinho: grafo[w])
        {
            if(dist[w] + 1 < dist[vizinho])
            {
                dist[vizinho] = dist[w] + 1;
                pai[vizinho] = w;
                fila.push(vizinho);
            }
        }
    }

    cout << "distancia:" << endl;
    for(int i = 1; i < dist.size(); i++)
    {
        cout << i << ": " << dist[i]<< endl;
    }

    cout << endl;
}

void print_grafo(vector<vector<int>> grafo)
{
    for(int i = 0; i < grafo.size(); i++)
    {
        cout << i << ": ";
        for(auto print: grafo[i])//isso é basicamente um for in
        {
            cout << print << " -> ";
        }

        cout << endl;
    }
}

int main()
{
    int n, m;

    cin >> n >> m;

    vector<vector<int>> grafo(n + 1);//lista de adjacencia
    
    vector<int> pai(n + 1, -1);//inicializando cada item do vetor com "-1"
    
    vector<int> pre(n + 1, -1);//utilizamos para saber se já visitamos ou não o vértice

    for(int i = 0; i < m; i++)
    {
        int u,v;

        cin >> u >> v;

        grafo[u].push_back(v);//poe na lista de adj do vertice que v é vizinho de u, adicionando-o ao fim da lista
        //grafo[v].push_back(u); //Com essa linha, indicaria que o grafo não é direcionado
    }

    //funcao para printar o grafo que foi lido
    //print_grafo(grafo);

    bfs(grafo, pai, 1, pre);

    cout << "Está funcionando, mas tem algo de errado por aqui" << endl << endl;
    
    cout << "Valores do pai" << endl;

    for(int i = 1; i < n + 1; i++) cout << pai[i] << endl;

    cout << "Valores do pre" << endl;

    for(int i = 1; i < n + 1; i++) cout << pre[i] << endl;

    return 0;
}