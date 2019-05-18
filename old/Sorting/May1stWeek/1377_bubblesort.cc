#include <iostream>
#include <algorithm>

#include<stdio.h>

using namespace std;

struct Data
{
  int original_index;
  int val;
};

bool Compare(const Data &arg1, const Data &arg2);

int main()
{
  int n;
  Data *seq;

  scanf("%d", &n);
  seq = new Data[n];

  for(int i = n; i != 0; i--) {
    scanf("%d", &((seq+n-i)->val));
    (seq+n-i)->original_index = n-i;
  }

  stable_sort(seq, seq+n, Compare);

  int max = 0;

  for(int i = n; i != 0; i--) {
    if(max < (seq+n-i)->original_index - (n-i)) {
      max = (seq+n-i)->original_index - (n-i);
    }
  }

  printf("%d\n", max+1);
  
  delete[] seq;
  return 0;
}

bool Compare(const Data &arg1, const Data &arg2)
{
  return arg1.val < arg2.val;
}