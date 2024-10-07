#include <bits/stdc++.h>

using namespace std;

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
    int n, m, cont = 0;

    cin >> n >> m;

    vector<vector<int>> grafo(n + 1);//lista de adjacencia
    
    vector<int> pai(n + 1, -1);//inicializando cada item do vetor com "-1"
    
    vector<int> pre(n + 1, -1);//utilizamos para saber se já visitamos ou não o vértice

    for(int i = 0; i < m; i++)
    {
        int u,v;

        cin >> u >> v;

        grafo[u].push_back(v);//poe na lista de adj do vertice que v é vizinho de u, adicionando-o ao fim da lista
        grafo[v].push_back(u);
    }

    print_grafo(grafo);

    return 0;
}