#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// 회원 정보를 나타내는 구조체.
struct Member
{
  int age;
  string name;
};

// 비교 함수
// 왜 다음 코드는 안되는가?
/*
if(m1.age > m2.age)
  return false;
else
  return true;
*/
bool cmp(const Member &m1, const Member &m2)
{
  if(m1.age > m2.age)
    return false;
  else
    return true;
}

void age_sort(int n)
{
  // 회원 정보를 저장하는 배열 선언.
  vector<Member> member;

  // 회원 정보 가입 순서대로 입력.
  for(int i=0; i<n; i++)
  {
    Member input;
    cin >> input.age >> input.name;
    member.push_back(input);
  }

  // 정렬 - stable_sort 함수로 같은 것이 있을 때 이전 순서를 유지.
  stable_sort(member.begin(), member.end(), cmp);

  // 출력.
  for(int i=0; i<n; i++) {
    cout << member[i].age << ' ' << member[i].name << '\n';
  }
}

int main()
{
  int n;
  cin >> n;
  age_sort(n);
  return 0;
}
