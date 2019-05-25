#include<iostream>
#include<vector>
#include<queue>

#include<stdio.h>

using namespace std;

struct NodeData
{
    int adj_node;
    int length;
};

vector<NodeData> Tree[100001];

int main()
{
    queue<int> bfs_q;
    bool *flag;
    int num_of_nodes;
    int *length_table;
    int far_node;

//입력받기
    NodeData tmp;
    int tmpnode;
    int tmplen, tmpadj;

    cin >> num_of_nodes;
    flag = new bool[num_of_nodes + 1];
    length_table = new int[num_of_nodes + 1];

    for (int i = 1; i <= num_of_nodes; i++)
    {
        cin >> tmpnode;
        while (true)
        {
            cin >> tmpadj;
            if (tmpadj == -1)
                break;
            cin >> tmplen;
            tmp.adj_node = tmpadj;
            tmp.length = tmplen;

            Tree[tmpnode].push_back(tmp);
            tmp.adj_node = tmpnode;
            Tree[tmpadj].push_back(tmp);
        }
    }

    for (int i = 1; i <= num_of_nodes; i++)
    {
        flag[i] = false;
        length_table[i] = 0;
    }

    int iter;
    int iter_root;
    while (!bfs_q.empty())
        bfs_q.pop();

    flag[1] = true;
    for (size_t i = 0; i < Tree[1].size(); i++)
    {
        iter = Tree[1][i].adj_node;
        flag[iter] = true;
        length_table[iter] += Tree[1][i].length;
        bfs_q.push(iter);
    }

    while (bfs_q.empty())
    {
        iter_root = bfs_q.front();
        bfs_q.pop();

        for (size_t i = 0; i < Tree[iter_root].size(); i++)
        {
            iter = Tree[iter_root][i].adj_node;
            if (flag[iter] == false)
            {
                flag[iter] = true;
                length_table[iter] += length_table[iter_root] + Tree[iter_root][i].length;
                bfs_q.push(iter);
            }
        }
    }

    int maxind;
    for (int i = 1; i <= num_of_nodes; i++)
    {
        if (i == 1)
        {
            maxind = i;
        }
        else if (length_table[maxind] < length_table[i])
        {
            maxind = i;
        }
    }
    far_node = maxind;

    for (int i = 1; i <= num_of_nodes; i++)
    {
        flag[i] = false;
        length_table[i] = 0;
    }


    flag[far_node] = true;
    for (size_t i = 0; i < Tree[far_node].size(); i++)
    {
        iter = Tree[far_node][i].adj_node;
        flag[iter] = true;
        length_table[iter] += Tree[far_node][i].length;
        bfs_q.push(iter);
    }

    while (bfs_q.empty())
    {
        iter_root = bfs_q.front();
        bfs_q.pop();

        for (size_t i = 0; i < Tree[iter_root].size(); i++)
        {
            iter = Tree[iter_root][i].adj_node;
            if (flag[iter] == false)
            {
                flag[iter] = true;
                length_table[iter] += length_table[iter_root] + Tree[iter_root][i].length;
                bfs_q.push(iter);
            }
        }
    }

    for (int i = 1; i <= num_of_nodes; i++)
    {
        if (i == 1)
        {
            maxind = i;
        }
        else if (length_table[maxind] < length_table[i])
        {
            maxind = i;
        }
    }

    cout << length_table[maxind] << endl;

    return 0;
}