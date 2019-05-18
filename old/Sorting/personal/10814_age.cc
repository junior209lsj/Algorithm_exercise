#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

struct MemberInformation
{
  int age;
  string name;
  int join_order;
};

bool Compare(const MemberInformation &arg1, const MemberInformation &arg2)
{
  if(arg1.age != arg2.age)
    return arg1.age < arg2.age;
  else
    return arg1.join_order < arg2.join_order;
}

int main()
{
  int num_of_members;
  cin >> num_of_members;
  MemberInformation *member_information = new MemberInformation[num_of_members];

  for(int i = 0; i < num_of_members; i++) {
    cin >> member_information[i].age >> member_information[i].name;
    member_information[i].join_order = i+1;
  }

  sort(member_information, member_information + num_of_members, Compare);

  for(int i = 0; i < num_of_members; i++) 
    cout <<member_information[i].age << ' ' << member_information[i].name 
    << '\n';

  return 0;
}