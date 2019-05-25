#include<iostream>
#include<vector>
#include<queue>

#include<stdio.h>

using namespace std;

class Tree
{

    vector<int> *graph;
    vector<int>::iterator it;
    queue<int> bfs_queue;
    int num_of_nodes;
    int *parents;
    bool *flag;

public:

    void GetNum()
    {
        cin >> num_of_nodes;
    }

    void CreateGraph()
    {
        //get number of nodes
        GetNum();
        graph = new vector<int>(num_of_nodes + 1);
        parents = new int[num_of_nodes + 1];
        flag = new bool[num_of_nodes + 1];
        //create graph

        int i = 0;
        while(i < num_of_nodes) {
            int node_1, node_2;
            scanf("%d %d", &node_1, &node_2);
            graph[node_1].push_back(node_2);
            graph[node_2].push_back(node_1);
            i++;
        }

    }

    void BFS()
    {
        //flush queue
        while(!bfs_queue.empty()) bfs_queue.pop();

    }

    
    

}