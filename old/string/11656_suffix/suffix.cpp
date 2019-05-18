#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Suffix
{
  string str; //입력을 받을 클래스
  int size; //입력의 문자열 크기를 저장할 변수
  string *suffix; //접미사를 각각 저장할 스트링 포인터
public:
  //문자열 입력 받고 접미사 저장 배열을 동적 할당
  void getStr()
  {
    cin >> str;
    size = str.length();
    suffix = new string[size];
  }
  void solve()
  {
    //접미사 저장
    for(int i = 0; i < size; ++i)
      suffix[i] = str.substr(i);
    //정렬
    sort(suffix, suffix + size);
    //출력
    for(int i = 0; i < size; ++i)
      cout << suffix[i] << endl;
    //메모리 반환
    delete[] suffix;
  }
};

int main()
{
  Suffix a;
  a.getStr();
  a.solve();
}
