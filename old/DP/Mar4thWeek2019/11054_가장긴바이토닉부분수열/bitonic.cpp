#include<iostream>

using namespace std;

int main()
{
    int length; //수열 길이
    int *sequence; //주어진 수열
    int *incSeqLen; //0~i까지 가장 긴 증가하는 부분 수열의 원소 개수
    int *decSeqLen; //length - 1 ~ i 까지 가장 긴 증가하는 부분 수열의 원소 개수

    /*배열 크기 입력 받고 크기에 따라 메모리 동적 할당*/
    cin >> length;
    sequence = new int[length];
    incSeqLen = new int[length];
    decSeqLen = new int[length];

    /*맨 끝 index를 저장하는 상수*/
    const int maxInd = length - 1;

    /*수열 내용 입력받기*/
    for(int i = 0; i < length; i++) cin >> sequence[i];

    /*0~i index까지 가장 긴 증가하는 부분 수열의 원소 개수 탐색*/
    incSeqLen[0] = 1;
    for (int i = 1; i < length; i++)
    {
        int max = 0;
        for (int j = 0; j < i; j++)
        {
            if (sequence[i] > sequence[j])
            {
                if (incSeqLen[j] + 1 >= max)
                    max = incSeqLen[j] + 1;
            }
        }
        if (max == 0)
            incSeqLen[i] = 1;
        else
            incSeqLen[i] = max;
    }

    /*maxInd~i index까지 가장 긴 증가하는 부분 수열의 원소 개수 탐색*/
    decSeqLen[maxInd] = 1;
    for (int i = maxInd - 1; i >= 0; i--)
    {
        int max = 0;
        for (int j = maxInd; j > i; j--)
        {
            if(sequence[i] > sequence[j])
            {
                if (decSeqLen[j] + 1 >= max)
                    max = decSeqLen[j] + 1;
            }
        }
        if (max == 0)
            decSeqLen[i] = 1;
        else
            decSeqLen[i] = max;
    }

    /*가장 긴 바이토닉 부분수열 찾기*/
    int maxAns = 0;
    for(int i = 0; i < length; i++)
    {
        if(incSeqLen[i] + decSeqLen[i] - 1 >= maxAns) maxAns = incSeqLen[i] + decSeqLen[i] - 1; //중복제거를 위해 1을 빼준다
    }

    /*결과 출력*/
    cout << maxAns << endl;


    delete[] sequence;
    delete[] incSeqLen;
    delete[] decSeqLen;
    return 0;
}