#include<iostream>
#include<vector>

using namespace std;

int power(int x, int p)
{
    int ret = 1;
    for(int i = 0; i < p; i++) ret = ret * x;
    return ret;
}

int main()
{
    int A, P;
    string a;
    cin >> A >> P;
    vector<int> seq;
    seq.push_back(A);
    int i = 0;
    int tmp = 0;
    int prev, r;
    bool escape;
    while(1) {
        escape = false;
        tmp = 0;
        prev = seq[i];
        while(prev > 0) {
            r = prev % 10;
            tmp += power(r, P);
            prev = prev / 10;
        }
        
        seq.push_back(tmp);
        i++;
         
        for(int j = 0; j < i; j++) {
            if(seq[j] == seq[i]) {
                cout << j << endl;
                escape = true;
            }
        }
        if(escape) break;
    }

    return 0;
}