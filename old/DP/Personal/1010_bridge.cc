#include<iostream>
#include<stdio.h>

using namespace std;

long long perm(int N, int M)
{
    long long res = 1;
    int tmp = M;
    for(int i = 1; i <= N; i++)
    {
        res *= tmp--;
        res /= i;
    }
    return res;
}

int main()
{
    int T;
    int N, M;
    cin >> T;
    long long *ans = new long long[T];
    for(int i = 0; i < T; ++i)
    {
        cin >> N >> M;
        ans[i] = perm(N, M);
    }
    for(int i = 0; i < T; ++i)
        printf("%lld\n", ans[i]);
    
    delete[] ans;
    return 0;
}