#include<iostream>
#include<vector>
#include<stack>

using namespace std;

const int MAX = 100001;

bool flag[MAX];
bool Isteam[MAX];

void InitiailizeFlags(bool *flags, int nodes)
{
    for(int i = 0; i < nodes; i++) {
        flags[i] = false;
    }
}

bool DFS(int start, int point, vector<int> path, stack<int> check)
{
    if(flag[point] == false) {
        flag[point] = true;
        check.push(point);
        DFS(start, path[point], path, check);
    }
    else {
        if(point == start) {
            int tmp;
            while(!check.empty()) {
                tmp = check.top();
                check.pop();
                Isteam[tmp] = true;
            }
            return true;
        }
        else {
            return false;
        }
    }
}

int main()
{
    int T;
    cin >> T;
    for(int tcase = 0; tcase < T; tcase++) 
    {
        int cnt = 0;
        int nodes;
        cin >> nodes;
        vector<int> path(nodes);

        //초기화
        for(int i = 0; i < nodes; i++) {
            cin >> path[i];
        }
        InitiailizeFlags(flag, nodes);
        InitiailizeFlags(Isteam, nodes);

        for(int i = 0; i < nodes; i++) {
            InitiailizeFlags(flag, nodes);
            stack<int> check;
            if(Isteam[i] == false) {
                DFS(i, i, path, check);
            }
        }

        for(int i = 0; i < nodes; i++) {
            if(Isteam[i] == false) {
                cnt++;
            }
        }
        
        cout << cnt << endl;

        //메모리 해제
        path.clear();
        vector<int>().swap(path);
    }
}