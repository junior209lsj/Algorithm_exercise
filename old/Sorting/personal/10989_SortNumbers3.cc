#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
  int flag[10001];
  int N;
  int tmp;
  cin >> N;
  memset(flag+1, 0, 10000*sizeof(int));
  for(int i = 1; i <= N; i++)
  {
    scanf("%d", &tmp);
    flag[tmp]++;
  }
  for(int i=1; i<=10000; i++)
  {
    while(flag[i] > 0)
    {
      printf("%d\n", i);
      flag[i]--;
    }
  }
  return 0;
}
