#include<stdio.h>
#include<iostream>
#include<stack>

using namespace std;

class stick
{
  //계산을 수행할 스택
  stack<char> st;
  //왼쪽에 철판이 얼마나 있는지 세주는 변수
  int numOfLeft;
  //동적 할당용 포인터
  char *c;
public:
  int calculate()
  {
    //초기화
    numOfLeft = 0;
    while(!st.empty()) st.pop();
    int result = 0;
    c = new char[100005];

    //문자열 입력받기
    fgets(c, 100004, stdin);

    int i = 0;
    while(c[i] != '\0')
    {
      //(가 나오면 스택에 넣고 왼쪽에 있는 (의 숫자를 카운팅
      if(c[i] == '(')
      {
        st.push(c[i]);
        numOfLeft++;
      }
      else if(c[i] == ')')
      {
        //레이저 검출
        if(c[i-1] == '(')
        {
          st.pop();
          numOfLeft--;
          result += numOfLeft;
        }
        //철판이 끝났을때
        else if(c[i-1] == ')')
        {
          st.pop();
          numOfLeft--;
          result++;
        }
      }
      i++;
    }
    return result;
  }
};

int main()
{
  stick a;
  cout << a.calculate() << endl;
  return 0;
}
