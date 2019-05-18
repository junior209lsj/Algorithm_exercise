#include<stdio.h>
#include<iostream>
#include<stack>

#define BUFSIZE 700000

using namespace std;

class Editor
{
  stack<char> L; //커서 왼쪽 스택
  stack<char> R; //커서 오른쪽 스택
  char *str; //입력 문자열을 받을 배열을 동적 할당할 포인터
  char inst[10]; //명령어를 받을 포인터
  int numOfInst; //명령어 수

public:
  void editing()
  {
    while(!L.empty()) L.pop();
    while(!R.empty()) R.pop();
    //스택 초기화 과정
    
    str = new char[BUFSIZE];
    //동적 할당
    
    fgets(str, BUFSIZE-1, stdin);
    //문자열 읽어들이기

    for(int i = 0; str[i] != '\n'; ++i)
    {
      L.push(str[i]);
    }
    //첫번째 줄 전부 왼쪽 스택에 적재
    
    scanf("%d", &numOfInst);
    //명령어 개수 읽어들이기

    getchar();
    //개행문자 버리기
    
    for(int i=0; i < numOfInst; ++i)
    {
      fgets(inst, 10, stdin);
      //명령 읽기

      switch(inst[0])
      {
        case 'L':
          if(!L.empty())
            {R.push(L.top()); L.pop();}
          break;
        case 'D':
          if(!R.empty())
            {L.push(R.top()); R.pop();}
          break;
        case 'B':
          if(!L.empty())
            L.pop();
          break;
        case 'P':
          L.push(inst[2]);
          break;
        default:
          break;
      }
    }
    //명령 수행

    while(!R.empty())
    {
      L.push(R.top());
      R.pop();
    }
    //R스택의 내용을 전부 L스택으로 가져옴

    int i = 0;
    while(!L.empty())
    {
      str[i] = L.top();
      L.pop();
      i++;
    }
    //스택의 내용을 동적 할당된 배열에 복사

    for(int j=i-1; j >= 0; --j)
    {
      printf("%c", str[j]);
    }
    printf("\n");
    //반대순서로 출력

    delete[] str;
    //메모리 반환
  }
};

int main()
{
  Editor a;
  a.editing();
  return 0;
}
