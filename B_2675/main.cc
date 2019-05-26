#include<iostream>

#include<stdio.h>

using namespace std;

struct Data
{
    int mul;
    char str[22];
};

int main()
{
    int n;
    cin >> n;
    Data *datas = new Data[n];

    for(int i = 0; i < n; i++) {
        scanf("%d %s", &(datas[i].mul), datas[i].str);
    }

    for(int i = 0; i < n; i++) {

        int cnt = 0;
        while(datas[i].str[cnt] != '\0') {
            for(int j = 0; j < datas[i].mul; j++) {
                printf("%c", datas[i].str[cnt]);
            }
            cnt++;
        }
        printf("\n");
    }

    return 0;
}