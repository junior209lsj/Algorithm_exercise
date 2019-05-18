#include<iostream>

using namespace std;

int main()
{
  int length; //수열의 길이
  int *sequence; //sequence[i] = A[i] 
  int *maxPartSum; //sequence[i]를 마지막으로 하는 증가하는 부분 수열의 합 중 최대값

  /*수열 길이 입력받고 배열 동적 할당*/
  cin >> length;
  sequence = new int[length];
  maxPartSum = new int[length];

  /*수열 내용 입력 받음*/
  for(int i = 0; i < length; i++) cin >> sequence[i];

  /*sequence[0]의 부분합은 sequence[0]*/
  maxPartSum[0] = sequence[0];
  for(int i = 1; i < length; i++)
  {
    int max = 0;
    for(int j = 0; j < i; j++)
    {
      if(sequence[i] > sequence[j] && maxPartSum[j] + sequence[i] >= max)
        max = maxPartSum[j] + sequence[i];
    }
    if(max == 0) maxPartSum[i] = sequence[i];
    else maxPartSum[i] = max;
  }

  int maxSum = 0;
  for(int i = 0; i < length; i++)
  {
    if(maxPartSum[i] >= maxSum)
      maxSum = maxPartSum[i];
  }

  cout << maxSum << endl;

  delete[] sequence;
  delete[] maxPartSum;
  return 0;
}
