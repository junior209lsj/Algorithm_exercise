#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
/*변수 선언*/
    const long mod = 1000000000; //나누는 수
    int N, K; //문제에서 정의한 정수 N, K
    long long divSum[201][201]; //divsum[a][b] K = a, N = b일 때 합분해 경우의 수

    memset(divSum, 0, sizeof(divSum)); //덧셈의 항등원인 0으로 배열 초기화

/*조건 입력*/
    cin >> N >> K;

/*알고리즘*/

    /*
    * 초기조건 : 1) K = 1이면 경우의 수는 무조건 1(N 하나 pick)
    * 2) N = 0이면 경우의 수는 무조건 1(all 0)
    */
    for(int i = 1; i <= N; i++)
        divSum[1][i] = 1;
    for(int i = 1; i <= K; i++)
        divSum[i][0] = 1;
    
    /*
    * k-1개 뽑아서 합을 a를 만들고 마지막으로 N-a를 하나 뽑아서 뒤에 붙이는
    * 모든 경우의 수를 더한다.
    */
    for(int k = 2; k <= K; k++)
    {
        for(int n = 1; n <= N; n++)
        {
            for(int i = 0; i <= n; i++)
            {
                divSum[k][n] += divSum[k-1][i];
                divSum[k][n] %= mod;
            }
        }
    }

/*결과 출력 및 프로그램 종료*/
    cout << divSum[K][N] % mod << endl;
    return 0;
}    
