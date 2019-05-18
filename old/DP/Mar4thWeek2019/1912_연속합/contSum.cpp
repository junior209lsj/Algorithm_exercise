#include<iostream>

using namespace std;


int main()
{
    /*변수 선언*/
    int length; // 수열 길이
    int *seq;  // 수열 포인터
    int max;  //연속합 최댓값
    int localSum;  //지역 연속합

    /*변수 입력*/
    cin >> length;

    seq = new int[length];

    for(int i = 0; i < length; i++) cin >> seq[i];

    /*
    * 알고리즘 *
    * if(i = 0인 경우)
    *   연속합 최댓값과 지역 연속합을 seq[i]로 초기화한다;
    * if(i가 0이 아닌 경우)
    *   지역 연속합에 i를 더한다;
    *   if(지역 연속합이 최댓값보다 크면)
    *       연속합 최댓값을 갱신한다.
    *   if(seq[i]가 지역 연속합보다 크면(연속적으로 더해가는걸 중단해야 함))
    *       지역 연속합을 i부터 다시 더하기 시작한다.
    *   if(seq[i]가 최댓값마저도 크면)
    *       연속합 최댓값을 갱신한다.
    */
    for(int i = 0; i < length; i++)
    {
        if(i == 0)
        {
            localSum = seq[i];
            max = seq[i];
        }
        else
        {
            localSum += seq[i];
            if(localSum >= max) max = localSum;
            if(seq[i] >= localSum)  localSum = seq[i];
            if(seq[i] >= max) max = seq[i];
        }
    }

    /*결과 출력*/
    cout << max << endl;

    delete[] seq;
    return 0;
}