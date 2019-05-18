#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

class Location
{
  string str; // 문자열을 받을 클래스
  int location; // 문자열의 위치를 저장할 클래스
public:
  //문자열을 받는다
  void getstr()
  {
    getline(cin, str);
  }
  //위치를 계산한다
  void calc()
  {
    //문자열 형으로 맞추기 위해 unsigned char 형을 사용함
    for(unsigned char i = 97; i < 123; i++)
    {
      //case 1: 문자가 존재하는 경우
      if((location = str.find(i)) != string::npos)
      {
        //문자의 위치 출력
        if(i == 122)
          cout << location << endl;
        else
          cout << location << " ";
      }
      //case 2: 문자가 존재하지 않는 경우
      else
      {
        //-1출력
        if(i == 122)
          cout << -1 << endl;
        else
          cout << -1 << " ";
      }
    }
  }
};

int main()
{
  Location a;
  a.getstr();
  a.calc();
  return 0;
}
