#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
    char a[101];

    fgets(a, 101, stdin);

    int len = strlen(a);

    printf("%d\n", len);

    for(int i = 0; i < len-1; i++)
        printf("%c", a[i]);

    return 0;
}