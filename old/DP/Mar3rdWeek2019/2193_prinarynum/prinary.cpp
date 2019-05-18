#include<iostream>

using namespace std;

int main()
{
  /**************************Variables**************************/
  int length;
  long prinaryNum[2][91] = { 0 };
  long result = 0;
  /**************************Enter variables**************************/
  cin >> length;
  /**************************Initializtion**************************/
  prinaryNum[0][1] = 0;
  prinaryNum[1][1] = 1;
  /**************************Implementation**************************/
  /*
   * prinaryNum[i][j] = i로 끝나는 j자리의 이친수
   * 동적 프로그래밍 이용
   * prinaryNum[0][j] = prinaryNum[0][j-1] + prinaryNum[1][j-1]
   * prinaryNum[1][j] = prinaryNum[0][j-1]   
   */ 
  for(int i = 2; i <= length; i++)
  {
    prinaryNum[0][i] = prinaryNum[0][i-1] + prinaryNum[1][i-1];
    prinaryNum[1][i] = prinaryNum[0][i-1];
  }
  result = prinaryNum[0][length] + prinaryNum[1][length];
  /**************************Print**************************/
  cout << result << endl;
  return 0;
}
