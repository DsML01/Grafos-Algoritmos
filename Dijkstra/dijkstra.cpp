#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<int>> &grafo, vector<int> &dist, vector<int> &pre, vector<vector<int>> &pesos)
{
    //indica que é uma priority queue, o pair<int,int> indica que o tipo de dado guardado, o vector<pair<int,in>> mosrta aonde os dados serão guardados e o
    //greater<pair<int,int>> indica que nós armazenaremos do menor para o maior, ou seja, os que tiverem menor número, terão maior prioridade.
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> fila; 

    fila.push({0, 1});

    while(!fila.empty())
    {
        //vértice atual
        int u = fila.top().second;
        //distancia do nó inicial até o nó atual
        int dist_ate_u = fila.top().first;
        fila.pop();

        if(dist_ate_u <= dist[u])
        {
            for(auto adjacente : grafo[u])
            {
                int v = adjacente;
                int peso_uv = pesos[u][v];

                if(dist[u] + peso_uv < dist[v])
                {
                    dist[v] = dist[u] + peso_uv;
                    pre[v] = u;
                    fila.push({dist[v], v});
                }
            }
        }
    }

    return;
}

int main(int argc, char **argv)
{
    string input_file = "";
    string output_file = "";
    int vert_inicial = 1;

    for(int i = 1; i < argc; i++) 
    {
        if (strcmp(argv[i], "-h") == 0)
        {
            cout << "Help:" << endl;
            cout << "-h: mostra o help" << endl;
            cout << "-o <arquivo>: redireciona a saida para o arquivo" << endl;
            cout << "-f <arquivo>: indica o 'arquivo' que contém o grafo de entrada" << endl;
            cout << "-i: vértice inicial" << endl;
            return 0;
        } 
        else if (strcmp(argv[i], "-o") == 0 && i < argc - 1) output_file = argv[++i];
        
        else if (strcmp(argv[i], "-f") == 0 && i < argc - 1) input_file = argv[++i];
        
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

    vector<int> dist(n + 1, numeric_limits<int>::max());
    dist[vert_inicial] = 0;
    vector<int> pre(n + 1, -1);
    // dist[vert_inicial] = 0; //vertice inicial = vertice 1, caso queira mudar, mudar com a flag -i ao compilar
    // for(int i = 1; i <= n; i++) if(i != vert_inicial) dist[i] = numeric_limits<int>::max();

    fin.close();

    if(!output_file.empty())
    {
        ofstream fout(output_file);
        if(!fout)
        {
            cerr << "Não foi possível abrir o arquivo de output: " << output_file << endl;
            return 1;
        }

        dijkstra(grafo, dist, pre, pesos);
        
        for(int i = 1; i <= n; i++)
        {
            if(dist[i] == numeric_limits<int>::max()) dist[i] = -1; //vectice inalcancavel
            
            fout << i << ":" << dist[i] << endl;
        }

        fout.close();
    }
    else
    {
        //Geralmente ele cai no else...
        dijkstra(grafo, dist, pre, pesos);

        for(int i = 1; i <= n; i++)
        {
            if(dist[i] == numeric_limits<int>::max()) dist[i] = -1; //vectice inalcancavel

            cout << i << ":" << dist[i];

            if(i != n) cout << " ";
            else cout << endl;
        }
    }

    return 0;
}