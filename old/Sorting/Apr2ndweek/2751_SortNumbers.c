#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b)
{
    int n1 = *(int *)a;
    int n2 = *(int *)b;

    if(n2 > n1) return -1;
    if(n1 > n2) return 1;
    
    return 0;
}


int main()
{
    int N;
    int *seq;

    scanf("%d", &N);
    seq = (int *)malloc(N*sizeof(int));
    for(int i = 0; i < N; i++)
        scanf("%d", (seq+i));
    
    qsort(seq, N, sizeof(int), cmp);

    for(int i = 0; i < N; i++)
        printf("%d\n", *(seq+i));

    free(seq);
    return 0;
}