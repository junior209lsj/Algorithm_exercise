#include<iostream>
#include<vector>
#include<stack>

#include<cstdio>

using namespace std;

const int MAX = 100001;

int flag[MAX];
int cycle[MAX];
int path[MAX];

void InitiailizeFlags(int *flags, int nodes)
{
    for(int i = 1; i <= nodes; i++) {
        flags[i] = 0;
    }
}

int DFS(int start, int point, int count)
{
    flag[point] = count;
    cycle[point] = start;

    int next = path[point];

    if(flag[next] == 0) {
        DFS(start, next, count + 1);
    }
    else {
        if(cycle[next] == start) {
            return count - flag[next] + 1;
        }
        else {
            return 0;
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int tcase = 0; tcase < T; tcase++) 
    {
        int cnt = 0;
        int nodes;
        scanf("%d", &nodes);

        //초기화
        for(int i = 1; i <= nodes; i++) {
            scanf("%d", (path+i));
        }
        InitiailizeFlags(flag, nodes);
        //InitiailizeFlags(cycle, nodes);

        for(int i = 1; i <= nodes; i++) {
            if(flag[i] != 0) {
                continue;
            }
            if(flag[path[i]] == 0) {
                cnt += DFS(i, i, 1);
            }
        }
        
        printf("%d\n", nodes - cnt);
    }
    return 0;
}