#include<iostream>
#include<math.h>
using namespace std;

int main()
{
/****************변수 선언****************/
    int num; //N
    int *minSquareTerm; //minSquareTerm[i] -> i를 제곱수의 합으로 나타낼 때 항의 최소수

/****************초기화****************/
    cin >> num;
    minSquareTerm = new int[num+1];

/****************알고리즘****************/
    /*i = 1인경우와 i = 2인경우 초기화*/
    minSquareTerm[0] = 0;
    minSquareTerm[1] = 1;
    minSquareTerm[2] = 2;

    /*제곱수 합의 최소 항 개수를 찾는 알고리즘*/
    int min;
    int m;
    for(int i = 3; i <= num; i++)
    {
        minSquareTerm[i] = i;
        for(int j = 1; j*j <= i; j++)
        {
            if(minSquareTerm[i] > minSquareTerm[i - j*j] + 1)
                minSquareTerm[i] = minSquareTerm[i - j*j] + 1;
        }
    }

/****************결과 출력 및 프로그램 종료****************/
    cout << minSquareTerm[num] << endl;

    delete[] minSquareTerm;
    return 0;
}