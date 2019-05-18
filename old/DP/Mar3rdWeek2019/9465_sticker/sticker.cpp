#include<iostream>

#define BUFSIZE 100001

using namespace std;

/**************************Functions declaration**************************/
int max(int a, int b, int c); //세 정수 중 최댓값을 구하는 함수

/**************************main function**************************/
int main()
{
/**************************Variables**************************/
  int T; //number of test case
  int n; //size of array
  int score[2][BUFSIZE]; //score of stickers
  int sumOfScore[3][BUFSIZE]; //memoization table
  int *maxScore; //array of maximum scores
/**************************Enter variables**************************/
  cin >> T;
/**************************Initializtion**************************/
  maxScore = new int[T];
/**************************Implementation**************************/
/*
 * score[0][j] = j번째 열의 위쪽 스티커 점수
 * score[1][j] = j번째 열의 아래쪽 스티커 점수
 * sumOfScore[0][j] = j번째 열의 스티커를 안 떼었을 때 1~j열의 최대 점수
 * sumOfScore[1][j] = j번째 열의 위쪽 스티커를 떼었을 때 1~j열의 최대 점수
 * sumOfScore[2][j] = j번째 열의 아래쪽 스티커를 안 떼었을 때 1~j열의 최대 점수
 */
  for(int test = 0; test < T; test++)
  {
    //배열 크기 입력
    cin >> n;
    //각 스티커의 점수를 입력 받음
    for(int i = 0; i < 2; i++)
    {
      for(int j = 1; j <= n; j++)
        cin >> score[i][j];
    }
    //메모이제이션 테이블 초기화
    for(int i = 0; i < 3; i++)
    {
      for(int j = 1; j <= n; j++)
        sumOfScore[i][j] = 0;
    }
    //sumOfScore[0][1] = 0;
    sumOfScore[1][1] = score[0][1];
    sumOfScore[2][1] = score[1][1];
    for(int i = 2; i <= n; i++)
    {
      sumOfScore[0][i] = max(sumOfScore[0][i-1], sumOfScore[1][i-1], sumOfScore[2][i-1]);
      sumOfScore[1][i] = score[0][i] + max(sumOfScore[0][i-1], sumOfScore[2][i-1], 0);
      sumOfScore[2][i] = score[1][i] + max(sumOfScore[0][i-1], sumOfScore[1][i-1], 0);
    }
    maxScore[test] = max(sumOfScore[0][n], sumOfScore[1][n], sumOfScore[2][n]);
  }
/**************************Print**************************/
  for(int i = 0; i < T; i++)
    cout << maxScore[i] << endl;
    return 0;
}

int max(int a, int b, int c)
{
  if(a > b)
  {
    if(a > c) return a;
    else return c;
  }
  else
  {
    if(b > c) return b;
    else return c;
  }
}
