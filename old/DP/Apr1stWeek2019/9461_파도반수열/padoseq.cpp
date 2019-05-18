#include<iostream>

using namespace std;

int main()
{
/*변수 선언*/
    int T; //T : 테스트 케이스 갯수
    int *ans; //각 테스트 케이스의 N을 저장하는 배열
    long long P[101]; //수열 P를 저장하는 배열

/*조건 입력*/
    cin >> T;

    ans = new int[T];

/*가장 큰 N을 찾는다*/
    int maxN;
    for(int i = 0; i < T; i++)
    {
        cin >> ans[i];
        if(i == 0) maxN = ans[i];
        else if(maxN <= ans[i]) maxN = ans[i];
    }

/*알고리즘*/
    P[1] = 1; P[2] = 1; P[3] = 1; P[4] = 2; P[5] = 2;

    if(maxN > 5)
    {
        for(int i = 6; i <=maxN; i++)
            P[i] = P[i-1] + P[i-5];
    }

/*결과출력 및 프로그램 종료*/
    for(int i = 0; i < T; i++)
        cout << P[ans[i]] << endl;
    
    delete[] ans;
    return 0;
}