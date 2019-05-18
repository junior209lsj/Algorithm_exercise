#include<stdio.h>

struct Ans
{
    long long zero;
    long long one;
};

int main(void)
{
    long long sum[2][41];

    sum[0][0] = 1;
    sum[1][0] = 0;
    sum[0][1] = 0;
    sum[1][1] = 1;

    int T, N;

    scanf("%d", &T);

    Ans *ans = new Ans[T];
    
    for (int i = 2; i <= 40; i++)
    {
        sum[0][i] = sum[0][i - 1] + sum[0][i - 2];
        sum[1][i] = sum[1][i - 1] + sum[1][i - 2];
    }

    for (int Case = 0; Case < T; Case++)
    {
        scanf("%d", &N);
            ans[Case].zero = sum[0][N];
            ans[Case].one = sum[1][N];
    }

    for(int i = 0; i < T; i++)
        printf("%lld %lld\n", ans[i].zero, ans[i].one);

    delete[] ans;
    return 0;
}