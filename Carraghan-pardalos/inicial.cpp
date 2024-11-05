#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int max_size = 0;
set<int> maximal_clique; // ver como definir dps esse '100' dinamicamente dps

void read_graph(vector<vector<int>> &graph, int m) {
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void print_graph(vector<vector<int>> &graph) {
    for (int i = 0; i < graph.size(); i++) {
        cout << i << "-> " <<  graph[i].size();
        /* for (int j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j] << " ";
        } */
        cout << endl;
    }
}



void carraghan_pardalos (vector<vector<int>> graph, vector<int> V, int size) {
    if(V.empty()) {
        if(size > max_size) {
            max_size = size; 
            // gravar a solucao aquimax_size
            return;
        }
    }

    while (!V.empty())
    {
        if(size + V.size() <= max_size) {
            return;
        }

        int v = V[0];
        V.erase(V.begin());
        
        vector<int> new_V;
        for (int i : V) {
            if (find(graph[v].begin(), graph[v].end(), i) != graph[v].end()) {
                new_V.push_back(i);
            }
        }

        carraghan_pardalos(graph, new_V, size + 1);
    }
    

    
}

vector<int> create_list_nodes(vector<vector<int>> &graph, int n) {
    vector<int> U;
    for (int i = 0; i < n; i++) {
        U.push_back(i);
    }
    return U;
}



int main() {
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    read_graph(graph, m);

    vector<int> set_nodes = create_list_nodes (graph, n);


    

    carraghan_pardalos(graph, set_nodes, 0);

    return 0;
}

