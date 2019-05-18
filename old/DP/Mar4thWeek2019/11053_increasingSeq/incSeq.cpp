#include<iostream>

using namespace std;

int main()
{
  int length; //수열 길이
  int *sequence; //sequence[i] = A[i]
  int *partSeqLen; //partSeqLen[i] = A[i]를 마지막으로 하는 가장 긴 증가하는 부분 수열

  /*수열의 길이 입력 받고 배열 동적 할당*/
  cin >> length;
  sequence = new int[length];
  partSeqLen = new int[length];

  /*수열의 내용 채우기*/
  for(int i = 0; i < length; i++)
    cin >> sequence[i];

  /*A[0]으로 끝나는 가장 큰 증가하는 부분 수열은 1개*/
  partSeqLen[0] = 1;

  for(int i = 1; i < length; i++)
  {
    int max = 0;
    for(int j = 0; j < i; j++)
    {
      //A[i] > A[j]인 경우에 partSeqLen[j] + 1의 최댓값을 찾음
      if(sequence[i] > sequence[j])
      {
        if(partSeqLen[j] + 1 >= max)
          max = partSeqLen[j] + 1;
      }
    }
    //A[i] > A[j] 인 j가 없는 경우 가장 큰 증가하는 부분 수열의 길이는 1
    if(max == 0) partSeqLen[i] = 1;
    //j가 있는경우
    else partSeqLen[i] = max;
  }

  int maxPartSeqLen = 0;
  for(int i = 0; i < length; i++)
  {
    if(partSeqLen[i] >= maxPartSeqLen) maxPartSeqLen = partSeqLen[i];
  }

  cout << maxPartSeqLen << endl;

  delete[] sequence;
  delete[] partSeqLen;

  return 0;
}
