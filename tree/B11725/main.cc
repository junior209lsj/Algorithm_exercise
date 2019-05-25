#include<iostream>
#include<vector>
#include<queue>

#include<stdio.h>

using namespace std;

struct Pair
{
    int first;
    int second;
};

struct GraphInfo
{
    vector<int> info;
};

class Tree
{
    GraphInfo *gp;
    queue<int> bfs_queue;

    Pair *nodes;
    int num_of_nodes;
    int *parents;
    bool *flag;

public:

    void GetNum()
    {
        cin >> num_of_nodes;
        nodes = new Pair[num_of_nodes+1];
        for(int i = 1; i < num_of_nodes; i++) {
            cin >> nodes[i].first >> nodes[i].second;
        }
    }

    void CreateGraph()
    {
        //get number of nodes
        GetNum();
        gp = new GraphInfo[num_of_nodes + 1];
        parents = new int[num_of_nodes + 1];
        flag = new bool[num_of_nodes + 1];
        //create graph

        int i = 1;
        while(i < num_of_nodes) {
            gp[nodes[i].first].info.push_back(nodes[i].second);
            gp[nodes[i].second].info.push_back(nodes[i].first);
            i++;
        }

    }

    void BFS()
    {
        int tmp;
        int tmproot;
        //flush queue
        while(!bfs_queue.empty()) bfs_queue.pop();

        for(int i = 1; i <= num_of_nodes; i++) {
            flag[i] = false;
        }

        //visit first node
        flag[1] = true;
        while(!gp[1].info.empty()) {
            tmp = gp[1].info.back();
            gp[1].info.pop_back();
            flag[tmp] = true;
            parents[tmp] = 1;
            bfs_queue.push(tmp);
        }
        
        //BFS search
        while(!bfs_queue.empty()) {

            tmproot = bfs_queue.front();
            bfs_queue.pop();

            while(!gp[tmproot].info.empty()) {
                tmp = gp[tmproot].info.back();
                gp[tmproot].info.pop_back();
                if(flag[tmp] == false) {
                    flag[tmp] = true;
                    parents[tmp] = tmproot;
                    bfs_queue.push(tmp);
                }
            }

        }

        //print results
        for(int i = 2; i <= num_of_nodes; i++) {
            printf("%d\n", parents[i]);
        }
    }
};

int main()
{
    Tree a;
    a.CreateGraph();
    a.BFS();
    return 0;
}