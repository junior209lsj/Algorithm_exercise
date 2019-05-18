#include<iostream>

using namespace std;

/*a와 b중 최댓값 return*/
int max(int a, int b);

/*
* first: 이 계단을 1연속으로 밟을 때의 최대 점수합
* cont: 이 계단을 2연속으로 밟을 때의 최대 점수합
*/
struct locMax
{
    int first;
    int cont;
};

int main()
{
    /*변수 선언*/
    locMax *localMaximum; //localMaximum[i] i+1번째 계단을 밟을 때의 최대 점수합 구조체 배열
    int length; //계단 개수
    int *score; //score[i] i+1번째 계단의 점수

    /*변수 입력*/
    cin >> length;

    score = new int[length];
    localMaximum = new locMax[length];

    for(int i = 0; i < length; i++) cin >> score[i];

    /*base case*/
    localMaximum[0].first = score[0];
    localMaximum[0].cont = 0;
    localMaximum[1].first = score[1];
    localMaximum[1].cont = score[0]+score[1];

    /*algorithm(Dynamic programming)*/
    for(int i = 2; i < length; i++)
    {
        localMaximum[i].first = score[i] + max(localMaximum[i-2].first, localMaximum[i-2].cont);
        localMaximum[i].cont = score[i] + localMaximum[i-1].first;
    }

    /*결과 출력*/
    cout << max(localMaximum[length-1].first, localMaximum[length-1].cont) << endl;

    delete[] score;
    delete[] localMaximum;
    return 0;
}

int max(int a, int b)
{
    if(a > b) return a;
    else return b;
}