#include<iostream>

using namespace std;

int main()
{
  //2xn타일을 만들 수 있는 방법의수를 저장하는 배열
  long tile[1001] = {0};
  int n;
  cin >> n;
  //처음 2개 상태
  tile[1] = 1; tile[2] = 3;
  //1이나 2일때 출력
  if(n <= 2)
    cout << tile[n] << endl;
  //n이 3이상인경우
  else
  {
    //Bottom up으로 구하기
    for(int i = 3; i <= n; i++)
      tile[i] = (tile[i-2]*2 + tile[i-1])%10007;
    //결과출력
    cout << tile[n] << endl;
  }
  return 0;
}
