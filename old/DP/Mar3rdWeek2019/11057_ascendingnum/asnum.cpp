#include<iostream>

using namespace std;

int main()
{
  /**************************Variables**************************/
  int length;
  long asNumTable[10][1001] = { 0 };
  long result = 0;
  /**************************Enter variables**************************/
  cin >> length;
  /**************************Initializtion**************************/
  for(int i = 0; i < 10; i++)
    asNumTable[i][1] = 1;
  /**************************Implementation**************************/
  /* asNumTable[i][j] = i로 끝나는 j자리의 오르막 수의 수
   * asNumTable[i][j] = sum(k = 0 to i) {asNumTable[k][j-i]} */
  for(int i = 2; i <= length; i++)
  {
    for(int j = 0; j < 10; j++)
    {
      for(int k = 0; k <= j; k++)
        asNumTable[j][i] += asNumTable[k][i-1];
        asNumTable[j][i] %= 10007;
    }
  }

  for(int i = 0; i < 10; i++)
    result += asNumTable[i][length] % 10007;
  result %= 10007;
  /**************************Print**************************/
  cout << result << endl;
  return 0;
}
