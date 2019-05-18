#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
  /****************변수 선언****************/
  int n; //사고싶은 카드 개수
  int P[1001];  //x묶음의 카드팩 가격을 저장하는 배열
  int optimal[1001];  //x개의 카드를 살 때 최대 가격을 저장하는 배열
  /****************입력****************/
  cin >> n;
  for(int i=1; i<=n; i++)
    scanf("%d", &P[i]);
  /****************계산****************/
  for(int i=1; i<=n; i++)
  {
    //i = 1일때는 1개를 담은 카드팩을 사는 가격이 최대값
    if(i == 1)
      optimal[i] = P[i];
    //아닌경우 i개를 담은 카드팩 vs i-1개를 살수있는 가격의 최대가격 + P[i] vs ...
    else
    {
      int max = P[i];
      for(int j=1; j<=i-1; j++)
      {
        if(optimal[j]+P[i-j] >= max)
          max = optimal[j]+P[i-j];
      }
      optimal[i] = max;
    }
  }
  /****************출력****************/
  cout << optimal[n] << endl;
  return 0;
}
