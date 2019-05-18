#include<iostream>
#include<string>

using namespace std;

int main()
{
  //네 수를 문자열로 저장할 클래스
  string a, b, c, d;
  //문자열로 네 수를 읽어들임
  cin >> a >> b >> c >> d;
  //문자열 합치기
  a += b;
  c += d;
  //문자열을 long 형으로 변환
  long ix, iy;
  ix = stol(a);
  iy = stol(c);
  //결과 출력
  cout << ix + iy << endl;
  return 0;
}
