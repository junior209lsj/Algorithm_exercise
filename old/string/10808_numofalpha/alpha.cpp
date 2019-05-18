#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

class Alphabet
{
  string str; // 문자열을 입력받을 객체
  int stor[26] ; // 각 알파벳이 나온 횟수를 저장하는 int 배열

public:
  //문자열 입력받기
  void getStr()
  {
    getline(cin, str);
  }

  //각 알파벳이 나온 수 계산
  void calc()
  {
    //배열 초기화
    for(int i=0; i<26; i++) stor[i] = 0;

    //string을 순회하며 stor배열에 값 저장
    //stor[1] = a가 나온 숫자 ... stor[25] = z가 나온 숫자
    //ascii 코드를 바탕으로 계산해서 저장
    for(int i=0; i < str.size(); i++)
      stor[str.at(i) - 97]++;
  }

  //결과 출력
  void printResult()
  {
    for(int i = 0; i < 26; i++)
    {
      if(i != 25)
        cout << stor[i] << " ";
      else
        cout << stor[i] << endl;
    }
  }

};

int main()
{
  Alphabet a;
  a.getStr();
  a.calc();
  a.printResult();
  return 0;
}
