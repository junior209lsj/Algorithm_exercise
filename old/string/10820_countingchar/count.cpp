#include<stdio.h>
#include<iostream>

using namespace std;

//공백 소문자 대문자의 숫자를 세서 저장하는 구조체
struct counter
{
  int uppercase; //대문자를 세는 변수
  int lowercase; //소문자를 세는 변수
  int number; //숫자를 세는 변수
  int space; //공백을 세는 변수
};

class Count
{
  counter ctr;
  char ch; //한글자씩 읽어들일 char변수
  char str[150];
public:
  //구조체를 초기화하는 변수
  void initStruct()
  {
    ctr.uppercase = 0;
    ctr.lowercase = 0;
    ctr.number = 0;
    ctr.space = 0;
  }
  void Counting()
  {
    //입력만큼 문자열 한줄씩 받기
    while(fgets(str, 149, stdin) != nullptr)
    {
      //구조체 초기화
      initStruct();
      //문자 숫자 세기
      for(int i = 0; str[i] != '\n'; i++)
      {
        if(str[i] == 32)
         ctr.space++;
        else if(str[i] >= 65 && str[i] <= 90)
         ctr.uppercase++;
        else if(str[i] >= 97 && str[i] <= 122)
         ctr.lowercase++;
        else if(str[i] >= 48 && str[i] <= 57)
         ctr.number++;
      }
      //출력
      cout << ctr.lowercase << " " << ctr.uppercase << " " << ctr.number << " " << ctr.space << endl;
    }
  }
};

int main()
{
  Count a;
  a.Counting();
  return 0;
}
