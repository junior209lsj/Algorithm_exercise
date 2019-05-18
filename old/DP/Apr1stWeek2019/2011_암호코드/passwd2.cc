#include<iostream>
#include<string>

using namespace std;

int main()
{
    const int mod = 1000000;
    string str;
    cin >> str;
    int length = str.length();
    
    int numArray[5010];
    int caseNum[5010] = {0};

    for(int i = 1; i <= length; i++)
        numArray[i] = str[i-1] - '0';
    

    if(length == 1 && str[0] == '0')
    {
        cout << 0 << endl;
        return 0;
    }

    caseNum[0] = 1;

    for(int i = 1; i <= length; i++)
    {
        if(numArray[i] >= 1 && numArray[i] <= 9)
            caseNum[i] = (caseNum[i-1] + caseNum[i]) % mod;
        if(i == 1) continue;
        int tmp = numArray[i] + numArray[i-1]*10;
        if(10 <= tmp && 26 >= tmp)
            caseNum[i] = (caseNum[i-2] + caseNum[i]) % mod;
    }

    cout << caseNum[length] << endl;
    return 0;
}