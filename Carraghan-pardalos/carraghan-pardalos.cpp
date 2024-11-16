#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_size = 0;
vector<int> current_best_clique;
vector<int> path, best_clique;

void read_graph(vector<vector<int>> &graph, int m) {
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void clique(vector<int> V, int size, vector<vector<int>> graph) {
    if(V.empty()){
        if(size > max_size){
            max_size = size;
           
            best_clique = path;
            path.clear();
            return; /* verificar se o return é aqui mesmo */
        }
    }

    while(!V.empty()){
        if(size + V.size() <= max_size){
            path.clear();
            return;
        }

        int v = V[0];
        V.erase(V.begin());
        path.push_back(v);

        vector<int> new_V;
        for(int i : V){
            if(find(graph[v].begin(), graph[v].end(), i) != graph[v].end()){
                new_V.push_back(i);
            }
        }

        clique(new_V, size + 1, graph);
    }
}

void print_graph(vector<vector<int>> &graph) {
    for (int i = 1; i < graph.size() ; i++) {
        /* cout << i << "-> " <<  graph[i].size(); */
        cout << i << "-> ";
        for (int j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main () {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    read_graph(graph, m);
    


    /* Defino o conjunto V de vértices */
    vector<int> V;
    for (int i = 1; i <= n; i++) {
        V.push_back(i);
    }
    

    /* Ordeno do menor para o maior em relação ao grau */
    sort(V.begin(), V.end(), [&graph](int u, int v) {
        return graph[u].size() < graph[v].size();
    });

    clique(V, 0, graph);

    cout << "Tamanho do clique: " << max_size << endl;
    cout << "Clique Máxima Encontrada: ";
    for(int i : best_clique){
            cout << i << " " ;
        }
        cout << endl;
}