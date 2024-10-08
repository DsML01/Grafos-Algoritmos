#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> grafo, vector<int> &pre, int vertice_inicial, vector<int> &pai, int &cont)
{
    //cout << vertice_inicial << endl;

    pre[vertice_inicial] = ++cont;

    for (auto u : grafo[vertice_inicial])
    {
        if (pre[u] == -1)
        {  // Se o vértice adjacente 'u' ainda não foi visitado
            pai[u] = vertice_inicial;   // Define o vértice atual como o pai do vértice 'u'
            dfs(grafo, pre, u, pai, cont);  // Chamada recursiva para o vértice 'u'
        }
    }
}

void print_grafo(vector<vector<int>> grafo)
{
    for(int i = 1; i < grafo.size(); i++)
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
    int n, m, cont = 0;

    cin >> n >> m;

    vector<vector<int>> grafo(n + 1);

    vector<int> pre(n + 1, -1);

    vector<int> pai(n + 1, -1);

    for(int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        grafo[u].push_back(v);
    }

    //print_grafo(grafo);

    dfs(grafo, pre, 1, pai, cont);

    // Exibe os pais de cada vértice
    cout << "\nVértice pai para cada vértice:" << endl;
    for (int i = 1; i <= n; i++) cout << "Vértice " << i << ", Pai: " << pai[i] << endl;

    // Exibe a ordem de visita de cada vértice
    cout << "\nOrdem de visitação (pre):" << endl;
    for (int i = 1; i <= n; i++) cout << "Vértice " << i << ", Ordem de visita: " << pre[i] << endl;

    return 0;
}