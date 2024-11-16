#include <iostream>
#include <vector>
#include <algorithm>
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

int main(){
    int n, m;
    int a, b, w;
    vector<pair<int, pair<int, int>>> edgeList;

    cin >> n >> m;

    fathers.resize(n + 1);
    for (int i = 0; i < n; i++)
    {
        fathers[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> w;
        edgeList.push_back(make_pair(w, make_pair(a, b)));
    }
    cout<<endl;
    //Kruskal 
    int mst_weight = 0, mst_edges = 0, mst_ni = 0;

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
            cout << "(" << a << "," << b << ") ";

            mst_edges++;
        }
        mst_ni++;
    }
    
    /* cout << "Peso total da MST: " << mst_weight << endl; */
    return 0;
}