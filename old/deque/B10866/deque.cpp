#include<stdio.h>
#include<iostream>
#include<deque>
#include<string>

using namespace std;

class Deque
{
  int n;
  string *inst;
  deque<int> dq;
public:
  void solve()
  {
    scanf("%d", &n);
    getchar(); // '\n' 비우기
    //명령어 갯수 입력 받음
    
    inst = new string[n];
    //명령어를 저장할 string 배열 동적 할당

    int *sto;
    sto = new int[n];

    int spc; //공백 위치 저장
    string Head; //인자가 있는 명령의 명령어
    string Tail; //인자가 있는 명령의 인자
    int arg;  //인자의 숫자형 변환
    int j = 0;
    for(int i = 0; i < n; i++)
    {
      getline(cin, inst[i]);
      
      //인자가 없는 명령
      if((spc = inst[i].find(" ")) == string::npos)
      {
        if(!(inst[i].compare("pop_front")))
        {
          if(dq.empty())
            sto[j++] = -1;
          else
          {
            sto[j++] = dq.front();
            dq.pop_front();
          }
        }
        if(!(inst[i].compare("pop_back")))
        {
          if(dq.empty())
            sto[j++] = -1;
          else
          {
            sto[j++] = dq.back();
            dq.pop_back();
          }
        }
        if(!(inst[i].compare("size")))
        {
          sto[j++] = dq.size();
        }
        if(!(inst[i].compare("empty")))
        {
          if(dq.empty())
            sto[j++] = 1;
          else
            sto[j++] = 0;
        }
        if(!(inst[i].compare("front")))
        {
          if(dq.empty())
            sto[j++] = -1;
          else
            sto[j++] = dq.front();
        }
        if(!(inst[i].compare("back")))
        {
          if(dq.empty())
            sto[j++] = -1;
          else
            sto[j++] = dq.back();
        }
      }
      //인자가 있는 명령
      else
      {
        Head = inst[i].substr(0, spc);
        Tail = inst[i].substr(spc+1);
        if(!(Head.compare("push_front")))
        {
          arg = stoi(Tail);
          dq.push_front(arg);
        }
        if(!(Head.compare("push_back")))
        {
          arg = stoi(Tail);
          dq.push_back(arg);
        }
      }
    }
    for(int i=0; i<j; ++i)
      printf("%d\n", sto[i]);
    delete[] inst;
    delete[] sto;
  }
};

int main()
{
  Deque a;
  a.solve();
  return 0;
}
