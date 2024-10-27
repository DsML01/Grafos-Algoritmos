#include <bits/stdc++.h>
using namespace std;

void prim(vector<vector<int>> &pesos, vector<vector<int>> &grafo, vector<int> &agm, vector<bool> &visited, vector<int> &dist, int init, int n)
{
    priority_queue<pair<int, pair<int, int>>> fila;

    dist[init] = 0;

    fila.push({0, {init, init}});

    int cont = 0;

    while(!fila.empty())
    {
        pair<int, int> edge = fila.top().second;
        fila.pop();

        int u = edge.first;//vertice atual
        int pai = edge.second;//vertice pai do atual

        visited[u] = true;

        if(cont != n && pai != u && pesos[pai][u] == dist[u])
        {
            if(agm[pai] == -1) agm[pai] = u;
            else if(agm[u] == -1) agm[u] = pai;
            cont++;
        }

        for(auto adjacente : grafo[u])
        {
            int v = adjacente;
            int peso_uv = pesos[u][v];

            if(visited[v]) continue;

            if(peso_uv < dist[v])
            {
                dist[v] = peso_uv;
                fila.push({-peso_uv, {v, u}});
            }
        }   
    }
}

vector<priority_queue<int>> sort_agm(vector<int> agm, int n)
{
    vector<priority_queue<int>> graph_agm(n + 1);

    //Ordenando a arvore
    for(int i = 0; i <= n; i++)
    {
        if(agm[i] != -1)
        {
            if(i > agm[i]) graph_agm[agm[i]].push(-i);
            else graph_agm[i].push(-agm[i]);
        }
    }
    return graph_agm;
}

int main(int argc, char **argv)
{
    string input_file = "";
    string output_file = "";
    bool ans = false;
    int vert_inicial = 1;

    for(int i = 1; i < argc; i++) 
    {
        if (strcmp(argv[i], "-h") == 0)
        {
            cout << "Help:" << endl;
            cout << "-h: mostra o help" << endl;
            cout << "-o <arquivo>: redireciona a saida para o arquivo" << endl;
            cout << "-f <arquivo>: indica o 'arquivo' que contém o grafo de entrada" << endl;
            cout << "-s: mostra a solução (em ordem crescente)" << endl;
            cout << "-i: vértice inicial" << endl;
            return 0;
        } 
        else if (strcmp(argv[i], "-o") == 0 && i < argc - 1) output_file = argv[++i];
        
        else if (strcmp(argv[i], "-f") == 0 && i < argc - 1) input_file = argv[++i];
        
        else if(strcmp(argv[i], "-s") == 0) ans = true;

        else if (strcmp(argv[i], "-i") == 0 && i < argc - 1) vert_inicial = atoi(argv[++i]);
    }

    if (input_file == "")
    {
        cerr << "Sem input especificado. Use o parametro -f" << endl;
        return 1;
    }

    ifstream fin(input_file);

    if (!fin)
    {
        //cerr eh usado para printar mensagens de erro
        cerr <<  "Não foi possível abrir o arquivo de input: " << input_file << endl;
        return 1;
    }

    int n, m;
    fin >> n >> m;

    //Inicializa com valores grandes
    vector<vector<int>> pesos(n + 1, vector<int>(n + 1, numeric_limits<int>::max()));
    vector<vector<int>> grafo(n + 1);

    for(int i = 1; i <= m; i++)
    {
        int u, v, peso;

        fin >> u >> v >> peso;
        if(u < 0 || v < 0 || peso < 0)
        {
            cout << "Entrada inválida !" << endl;
            return 0;
        }

        grafo[u].push_back(v); // lendo os arcos e pondo na lista de adj quem é vizinho de quem
        grafo[v].push_back(u);
        pesos[u][v] = peso;
        pesos[v][u] = peso;
    }

    vector<int> agm(n + 1, -1);
    vector<bool> visited(n + 1, false);
    vector<int> dist(n + 1, numeric_limits<int>::max());

    fin.close();

    prim(pesos, grafo, agm, visited, dist, vert_inicial, n);

    int soma = 0;

    for(int i = 1; i <= n; i++) if(dist[i] != numeric_limits<int>::max()) soma += dist[i];

    //fin.close();

    if (ans)
    {
        vector<priority_queue<int>> graph_agm = sort_agm(agm, n);

        for (int i = 0; i < graph_agm.size(); i++)
        {
            while (!graph_agm[i].empty())
            {
                int j = graph_agm[i].top();
                graph_agm[i].pop();

                cout << "(" << i << "," << -j << ") ";
            }
        }
        cout << endl;
    }
    else cout << soma << endl;


    if(!output_file.empty())
    {
        ofstream fout(output_file);
        if(!fout)
        {
            cerr << "Não foi possível abrir o arquivo de output: " << output_file << endl;
            return 1;
        }

        fout << "Cursto da agm = " << soma << endl;

        if(ans)
        {
            vector<priority_queue<int>> graph_agm = sort_agm(agm, n);

            for(int i = 0; i < graph_agm.size(); i++)
            {
                while(!graph_agm[i].empty())
                {
                    int j = graph_agm[i].top();
                    graph_agm[i].pop();

                    fout << "(" << i << "," << -j << ") ";
                }
            }
            fout << endl;            
        }
        else
        {
            for(int i = 1; i <= n; i++) fout << "(" << "," << agm[i] << ") ";
            fout << endl;
        }
    }

    return 0;
}