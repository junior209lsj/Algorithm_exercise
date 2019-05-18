#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

struct Student
{
  string name;
  size_t korean_score;
  size_t english_score;
  size_t math_score;
};

bool Compare(const Student &arg1, const Student &arg2);

int main()
{
  size_t student_number;
  cin >> student_number;

  Student *students;
  students = new Student[student_number];

  for(size_t i = 0; i < student_number; i++) {
    cin >> students[i].name >> students[i].korean_score >>
      students[i].english_score >> students[i].math_score;
  }

  sort(students, students+student_number, Compare);

  for(size_t i = 0; i < student_number; i++)
    cout << students[i].name << '\n';

  delete[] students;
  return 0;
}

bool Compare(const Student &arg1, const Student &arg2)
{
  if(arg1.korean_score != arg2.korean_score)
    return arg1.korean_score > arg2.korean_score;
  else if(arg1.english_score != arg2.english_score)
    return arg1.english_score < arg2.english_score;
  else if(arg1.math_score != arg2.math_score)
    return arg1.math_score > arg2.math_score;
  else 
    return arg1.name.compare(arg2.name) < 0;
}

