#include<stdio.h>
#include<iostream>
#include<queue>

using namespace std;

class Josepus
{
  queue<int> q;
  int *Q;
  int n;
  int m;
public:
  void solve()
  {
    scanf("%d", &n);
    scanf("%d", &m);
    //N과 M 입력받기

    Q = new int[n];
    //결과를 저장할 배열을 동적 할당
    
    for(int i = 1; i <= n; ++i)
      q.push(i);
    //큐 초기화
    
    int index = 0;
    while(!q.empty())
    {
      for(int i = 0; i < m - 1; ++i)
      {
        q.push(q.front());
        q.pop();
      }
      Q[index++] = q.front();
      q.pop();
    }
    //조세퍼스 순열 알고리즘 사용하여 배열에 값 저장

    printf("<");
    for(int i = 0; i < n; i++)
    {
      if(i != n - 1)
        printf("%d, ", Q[i]);
      else
        printf("%d>\n", Q[i]);
    }
    //값 출력
    
    delete[] Q;
    //동적 할당 배열 반환
  }

};

int main()
{
  Josepus a;
  a.solve();

  return 0;
}
