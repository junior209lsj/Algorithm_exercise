#include<iostream>
#include<vector>

using namespace std;

const int MAX = 1001;

int path[MAX];
bool flag[MAX];

void DFS(int *cnt, int start)
{
    if(flag[start] == false) {
        flag[start] = true;
        DFS(cnt, path[start]);
    }
    else {
        *cnt = *cnt + 1;
    }
}

int main()
{
    int T;
    int cnt;
    cin >> T;

    for(int i = 0; i < T; i++) {
        cnt = 0;
        int nodes;
        cin >> nodes;
        
        for(int j = 1; j <= nodes; j++) {
            cin >> path[j];
            flag[j] = false;
        }

        for(int j = 1; j <= nodes; j++) {
            if(flag[j] == false) {
                DFS(&cnt, j);
            }
        }

        cout << cnt << endl;
    }

    return 0;
}