#include <iostream>
#include <algorithm>

#include <stdio.h>

using namespace std;

int main()
{
  size_t n, k;
  scanf("%lu %lu", &n, &k);
  long *A = new long[n];
  for(int i = n; i != 0; i--) {
    scanf("%ld", (A+n-i));
  }
  sort(A, A+n);
  printf("%ld\n", *(A+k-1));

  delete[] A;
  return 0;
}
