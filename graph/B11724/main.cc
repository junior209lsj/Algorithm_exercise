#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#include <cstdio>

using namespace std;

typedef vector< vector<int> > GRAPH;

struct Edges
{
    size_t first;
    size_t second;
};

struct Capacity
{
    size_t node_size;
    size_t edge_size;
};

class Graph
{
    GRAPH G;
    bool *flag;
    Capacity Size;

public:

    Graph(Capacity siz, Edges* edges)
    {
        Size = siz;
        G.reserve(siz.node_size + 1);
        for(int i = 0; i < siz.edge_size; i++) {
            G[edges[i].first].push_back(edges[i].second);
            G[edges[i].second].push_back(edges[i].first);
        }
        flag = new bool[siz.node_size+1];
    }

    ~Graph() { }

    void InitializeFlags()
    {
        for(int i = 1; i <= Size.node_size; i++) {
            flag[i] = false;
        }
    }

    void SortNodes()
    {
        for(int i = 1; i <= Size.node_size; i++)
        {
            sort(G[i].begin(), G[i].end());
        }
    }

    void StartDFS(size_t start)
    {
        DFS(start);
    }

    void DFS(size_t start)
    {

        flag[start] = true;

        for(int i = 0; i < G[start].size(); i++) {
            int tmp = G[start][i];
            if(flag[tmp] == false) {
                DFS(tmp);
            }
        }

    }

    void BFS(size_t start)
    {
        queue<int> q;
        flag[start] = true;
        q.push(start);
        while(!q.empty()) {
            int tmp = q.front();
            q.pop();
            for(int i = 0; i < G[tmp].size(); i++) {
                int temp = G[tmp][i];
                if(flag[temp] == false) {
                    flag[temp] = true;
                    q.push(temp);
                }
            }
        }
    }

    int FindMeshes()
    {
        InitializeFlags();
        int meshes = 0;

        while(1)
        {
            int tmpstart = -1;
            for(int i = 1; i <= Size.node_size; i++) {
                if(flag[i] == false) {
                    tmpstart = i;
                    break;
                }
            }

            if(tmpstart == -1) {
                break;
            }

            BFS(tmpstart);
            meshes++;
        }

        return meshes;
    }
};

int main()
{
    Capacity cap;
    cin >> cap.node_size >> cap.edge_size;
    Edges *edgestore = new Edges[cap.edge_size];
    for(int i = 0; i < cap.edge_size; i++) {
        cin >> edgestore[i].first >> edgestore[i].second;
    }

    Graph mygraph(cap, edgestore);
    mygraph.SortNodes();
    cout << mygraph.FindMeshes() << endl;

    return 0;
}