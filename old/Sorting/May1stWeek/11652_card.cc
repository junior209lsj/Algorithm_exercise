#include<iostream>
#include<algorithm>

#include<stdio.h>

using namespace std;

int main()
{
  size_t n;
  scanf("%lu", &n);
  long long *card = new long long[n];
  //C optimization technique
  for(size_t i = n; i != 0; i--) {
    scanf("%lld", (card+n-i));
  }

  sort(card, card+n);

  int max, tmp;
  long long maxind;
  max = 0; tmp = 0;

  for(size_t i = n-1; i != 0; i--) {
    tmp++;
    if(*(card+n-1-i) != *(card+n-1-i+1)) {
      if(max < tmp) {
        max = tmp;
        maxind = *(card+n-1-i);
      } 
      tmp = 0;
    }
  }
  //last element card[n-1]
  tmp++;
  if(max < tmp) {
    max = tmp;
    maxind = *(card+n-1);
  } 

  printf("%lld\n", maxind);

  delete[] card;
  return 0;
}