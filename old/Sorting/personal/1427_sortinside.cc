#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

int main()
{
    int num;
    int cnt = 0;
    int table[20];
    while((num=getchar()) != '\n')
    {
        table[cnt] = num - '0';
        cnt++;
    }

    sort(table, table+cnt, greater<int>());

    for(int i = 0; i < cnt; i++)
        cout << table[i];
    cout << endl;
    
    return 0;
}