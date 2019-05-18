#include<iostream>

#define BUFSIZE 10001 

using namespace std;

/**************************Functions declaration**************************/
int Max(int a, int b, int c); //세 정수 중 최댓값을 구하는 함수

/**************************main() function**************************/
int main()
{
/**************************Variables**************************/
  int n;
  int score[BUFSIZE];
  int maxScore[3][BUFSIZE] = { 0 };
  long result;
/**************************Enter variables**************************/
  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> score[i];
/**************************Implementation**************************/
/*
 * maxScore[0][k] = k번째 잔을 마시지 않았을 때 1~k번째 잔까지의 최대 점수합
 * maxScore[1][k] = k번째 잔을 마셨을 때, k-1번째 잔을 안마셨을 때 최대 점수합
 * maxScore[2][k] = k번째 잔을 마셨을 때, k-1번째 잔을 마셨을 때(2연속) 최대 점수합
 */
  maxScore[0][1] = 0;
  maxScore[1][1] = score[1];
  maxScore[2][1] = 0;

  for(int i = 2; i <= n; i++)
  {
    maxScore[0][i] = Max(maxScore[0][i-1], maxScore[1][i-1], maxScore[2][i-1]);
    maxScore[1][i] = score[i] + maxScore[0][i-1];
    maxScore[2][i] = score[i] + maxScore[1][i-1];
  }

  result = Max(maxScore[0][n], maxScore[1][n], maxScore[2][n]);
/**************************Print**************************/
  cout << result << endl;
  return 0;
}

/**************************Functions implementation**************************/
int Max(int a, int b, int c)
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
