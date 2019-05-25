#include <iostream>
#include <vector>
#include <queue>

#include <stdio.h>

using namespace std;

struct NodeData
{
    int adj_node;
    int length;
};

struct Tree
{
    vector<NodeData> info;
};

class Delimeter 
{
    Tree *T;
    queue<int> bfs_queue;
    
    bool *flag;
    int num_of_nodes;
    int *length;
    int far_node;

    public:

    void GetInfo()
    {
        int i;
        NodeData tmp;
        int node;
        int len, adj;
        cin >> num_of_nodes;

        T = new Tree[num_of_nodes + 1]; 
        flag = new bool[num_of_nodes + 1];
        length = new int[num_of_nodes + 1];

        for(i = 1; i <= num_of_nodes; i++) {
            cin >> node;
            while(true) {
                cin >> adj;
                if(adj == -1) break;
                cin >> len;
                tmp.adj_node = adj;
                tmp.length = len;

                T[node].info.push_back(tmp);
                tmp.adj_node = node;
                T[adj].info.push_back(tmp);
            }
        }
    }

    void FlagInitialize()
    {
        for(int i = 1; i <= num_of_nodes; i++) {
            flag[i] = false;
            length[i] = 0;
        }
    }

    void BFS(int start)
    {
        FlagInitialize();
        int tmp;
        int tmproot;

        while(!bfs_queue.empty()) bfs_queue.pop();

        flag[start] = true;
        for(size_t i = 0; i < T[start].info.size(); i++) {
            tmp = T[start].info[i].adj_node;
            flag[tmp] = true;
            length[tmp] += T[start].info[i].length;
            bfs_queue.push(tmp);
        }

        while(bfs_queue.empty()) {
            tmproot = bfs_queue.front();
            bfs_queue.pop();

            for (size_t i = 0; i < T[tmproot].info.size(); i++) {
                tmp = T[tmproot].info[i].adj_node;
                if(flag[tmp] == false) {
                    flag[tmp] = true;
                    length[tmp] += length[tmproot] + T[tmproot].info[i].length;
                    bfs_queue.push(tmp);
                }
            }
        }

        int maxind;
        for(int i = 1; i <= num_of_nodes; i++) {
            if(i == 1) {
                maxind = i;
            }
            else if(length[maxind] < length[i]) {
                maxind = i;
            } 
        }
        far_node = maxind;
    }

    void GetDelimeter()
    {
        int far;
        GetInfo();
        BFS(1);
        cout << length[far_node];
    }
};

int main()
{
    Delimeter a;
    a.GetDelimeter();
    return 0;
}