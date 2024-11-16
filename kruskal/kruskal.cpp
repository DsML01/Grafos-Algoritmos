#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <fstream>
using namespace std;

vector<int> fathers;

int find(int x) {
    if (fathers[x] == x) {
        return x;
    }
    return find(fathers[x]);
}

void unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    fathers[fx] = fy;
}

int main(int argc, char **argv){
    string input_file = "";
    string output_file = "";
    bool answer = false;
    
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
        
        else if(strcmp(argv[i], "-s") == 0) answer = true;
    }

    if (input_file == "")
    {
        cerr << "Sem input especificado. Use o parametro -f" << endl;
        return 1;
    }


    ifstream fin(input_file);
    // if (fin == NULL)
    if (!fin)
    {
        //cerr eh usado para printar mensagens de erro
        cerr << "Não foi possível abrir o arquivo de input: " << input_file << endl;
        return 1;
    }


    int n, m;
    fin >> n >> m;

    int a, b, w;
    vector<pair<int, pair<int, int>>> edgeList;


    fathers.resize(n + 1);
    for (int i = 0; i < n; i++)
    {
        fathers[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        fin >> a >> b >> w;
        edgeList.push_back(make_pair(w, make_pair(a, b)));
    }

    //Kruskal 
    int mst_weight = 0, mst_edges = 0, mst_ni = 0;
    vector <pair<int, int>> agm;

    sort(edgeList.begin(), edgeList.end());

    while ((mst_edges < n-1) || (mst_ni < m))
    {
        int w = edgeList[mst_ni].first;
        int a = edgeList[mst_ni].second.first;
        int b = edgeList[mst_ni].second.second;

        if (find(a) != find(b))
        {
            unite(a, b);
            mst_weight += w;
            
            agm.push_back(make_pair(a, b));
            
            mst_edges++;
        }
        mst_ni++;
    }
    
    if(output_file != "") {
        ofstream fout(output_file);
        if(!fout)
        {
            cerr << "Não foi possível abrir o arquivo de output: " << output_file << endl;
            return 1;
        }
        fout << mst_weight << endl;

        if(!answer) {
           fout << mst_weight << endl;
        } else {
            for (int i = 0; i < agm.size(); i++)
            {
            fout << "(" << agm[i].first << "," << agm[i].second << ")";

            (i < agm.size() - 1) ? fout << " " : fout << endl; 
            }
            
        }
        fout.close();
    }  
    else {
        if(answer) {
            for (int i = 0; i < agm.size(); i++)
            {
            cout << "(" << agm[i].first << "," << agm[i].second << ")";

            (i < agm.size() - 1) ? cout << " " : cout << endl; 
            }
        } else {
            cout << mst_weight << endl;
        }
    }
    return 0;
}