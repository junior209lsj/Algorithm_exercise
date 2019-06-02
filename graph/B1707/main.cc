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
    int *flag;
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
        flag = new int[siz.node_size+1];
    }

    ~Graph() { }

    void InitializeFlags()
    {
        for(int i = 1; i <= Size.node_size; i++) {
            flag[i] = -1;
        }
    }

    bool IsBipart(int start)
    {
        InitializeFlags();
        queue<int> q;
        flag[start] = 1;
        q.push(start);
        while (!q.empty()) {
            int tmp = q.front();
            q.pop();
            for (int i = 0; i < G[tmp].size(); i++) {

                int temp = G[tmp][i];

                if (flag[temp] == -1) {
                    if(flag[tmp] == 1) {
                        flag[temp] = 2;
                    }
                    else {
                        flag[temp] = 1;
                    }
                    q.push(temp);
                }

                else {
                    if(flag[temp] == flag[tmp]) {
                        cout << "NO" << endl;
                        return false;
                    }
                }

            }
        }

        cout << "YES" << endl;
        return true;
    }

};

int main()
{
    int test_size;
    cin >> test_size;
    for(int i = 0; i < test_size; i++) {
        Capacity cap;
        cin >> cap.node_size >> cap.edge_size;
        Edges *edge = new Edges[cap.edge_size];
        for(int i = 0; i < cap.edge_size; i++) {
            cin >> edge[i].first >> edge[i].second;
        }
        Graph mygraph(cap, edge);
        mygraph.IsBipart(1);
    }

    return 0;
}