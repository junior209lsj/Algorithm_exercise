#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
    const int mod = 1000000;
    char passwd[5010];

    //암호를 문자 배열에 입력받음
    scanf("%s", passwd);

    int length = strlen(passwd);

    int *caseNum;
    caseNum = new int[length];

    //Base case 1: i = 0일때
    if(passwd[0] == '0')
    {
        printf("%d\n", 0);
        return 0;
    }
    else if(passwd[0] - '0' >= 1 && passwd[0] - '0' <= 9)
        caseNum[0] = 1;
    else
    {
        printf("%d\n", 0);
        return 0;
    }

    //Base case 1: i = 1일때
    if(passwd[1] == '0')
    {
        if(passwd[0] == '1' || passwd[0] == '2') caseNum[1] = 1;
        else
        {
            printf("%d\n", 0);
            return 0;
        }
    } 
    else if(passwd[1] - '0' >= 1 && passwd[1] - '0' <= 9)
    {
        if(10 <= (passwd[0]-'0')*10 + (passwd[1]-'0') && 26 >= (passwd[0]-'0')*10 + (passwd[1]-'0'))
            caseNum[1] = 2;
        else
            caseNum[1] = 1;
    }
    else
    {
        printf("%d\n", 0);
        return 0;
    }

    for (int i = 2; i < length; i++)
    {
        if (passwd[i] == '0')
        {
            if (passwd[i-1] == '1' || passwd[i-1] == '2')
                caseNum[i] = caseNum[i-2] % mod;
            else
            {
                printf("%d\n", 0);
                return 0;
            }
        }
        else if(passwd[i] - '0' >= 1 && passwd[i] - '0' <= 9)
        {
            if (10 <= (passwd[i-1]-'0') * 10 + (passwd[i]-'0') && 26 >= (passwd[i-1]-'0') * 10 + (passwd[i]-'0'))
                caseNum[i] = (caseNum[i-2] + caseNum[i-1])%mod;
            else
                caseNum[i] = caseNum[i-1] % mod;
        }
        else
        {
            printf("%d\n", 0);
            return 0;
        }
    }

    cout << caseNum[length-1] % mod << endl;

    delete[] caseNum;   
    return 0;
}