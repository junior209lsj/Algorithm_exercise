#include<iostream>
#include<stdio.h>
#include<stack>

using namespace std;

class VPSDecect
{
public:
  int numOfTest; // 테스트 케이스 갯수
  stack<char> Storage; // VPS를 판단할 스택

  //테스트 케이스 갯수를 입력받는 함수
  void inputTestCase()
  {
    scanf("%d", &numOfTest);
    getchar();
  }
  // VPS를 검사하는 함수
  int detectVPS()
  {
    //스택 초기화
    while(!Storage.empty()) Storage.pop();
    char c[100];
    //한줄 입력받기
    fgets(c, 99, stdin);
    int i = 0;
    while(c[i] != '\0')
    {
      //'('를 입력받으면 push
      if(c[i] == '(')
        Storage.push(c[i]);
      // ')'을 입력 받았을 때 스택이 차있으면 하나('(') pop
      // 아니면 VPS아님
      else if(c[i] == ')')
      {
        if(Storage.empty()) 
          return 0;
        else
          Storage.pop();
      }
      i++;
    }
    //루프가 끝난 후 스택이 비어있으면 VPS, 아니면 non-VPS
    if(Storage.empty())
      return 1;
    else
      return 0;
  }
};

int main(){
  VPSDecect a;
  a.inputTestCase();
  for(int i = 0; i < a.numOfTest; i++)
  {
    if(a.detectVPS())
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
