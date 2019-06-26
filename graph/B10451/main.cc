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
    Capacity Size;

public:
    size_t cnt;
    bool *flag;

    Graph(Capacity siz, Edges* edges)
    {
        Size = siz;
        G.reserve(siz.node_size + 1);
        //단방향 그래프
        for(int i = 0; i < siz.edge_size; i++) {
            G[edges[i].first].push_back(edges[i].second);
            //G[edges[i].second].push_back(edges[i].first);
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

    void DFS(size_t start)
    {
        if(flag[start] == true) {
            return;
        }
        
        flag[start] = true;

        for(int i = 0; i < G[start].size(); i++) {
            int tmp = G[start][i];
            if(flag[tmp] == false) {
                DFS(tmp);
            }
            else {
                cnt++;
                break;
            }
        }
    }

};

int main()
{
    int T;
    cin >> T;
    for(int test = 0; test < T; test++) {
        Capacity c;
        cin >> c.node_size;
        c.edge_size = c.node_size;
        Edges *e = new Edges[c.edge_size];

        for(int i = 1; i <= c.node_size; i++) {
            e[i-1].first = i;
            cin >> e[i-1].second;
        }

        Graph G(c, e);
        G.cnt = 0;
        G.InitializeFlags();
        for(int i = 1; i <= c.node_size; i++) {
            if(G.flag[i] == false) {
                G.DFS(i);
            }
        }

        cout << G.cnt << endl;
    }
    return 0;
}