#include<stdio.h>
#include<iostream>

using namespace std;

class ROT13
{
  //문자열을 받을 버퍼
  char str[150];
public:
  //암호화 함수 
  void Encode()
  {
    //문자열 읽어들이기 
    fgets(str, 149, stdin);
    //개행 문자를 만날 때까지 암호화 
    for(int i = 0; str[i] != '\n'; i++)
    {
      //대문자일때, A = 65, Z = 90
      if(str[i] >=  65 && str[i] <= 90)
      {
        //대문자일때는 char자료형의 오버플로우가 일어나지 않음
        str[i] += 13;
        if(str[i] > 90)
          str[i] = 65 + (-90 + str[i] -1);
      }
      //소문자일때, a = 97, z = 122
      if(str[i] >=  97 && str[i] <= 122)
      {
        //char 자료형의 오버플로우 고려
        if(str[i] <= 109)
          str[i] += 13;
        else
          str[i] = 97 + 13 - (122 - str[i] + 1);
      }
    }
  }
  //결과 출력
  void Print()
  {
    printf("%s\n", str);
  }
};

int main()
{
  ROT13 a;
  a.Encode();
  a.Print();
  return 0;
}
