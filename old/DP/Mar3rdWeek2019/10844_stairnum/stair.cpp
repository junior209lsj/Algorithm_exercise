/******************************
*10844번 쉬운 계단 수         *
*******************************/
#include<iostream>

using namespace std;

int main()
{
    /*변수 선언부*/
    long numTable[10][101] = { 0 };
    int n;
    long result = 0;
    /*입력부*/
    cin >> n;
    /*계산부*/

      /*******************************************************************************************
       *numTable[i][n] : i로 끝나는 n자리의 계단 수                                              *
       *sum i = 0 to 9 numtable[i][n] : n자리의 계단 수를 만들 수 있는 경우의 수                 *
       *******************************************************************************************/

    /*초기화*/
    numTable[0][1] = 0;
    for(int i = 1; i < 10; i++)
        numTable[i][1] = 1;

    /*계산*/ 
    for(int i = 2; i <= n; i++)
    { 
        for(int j = 0; j < 10; j++)
        {
            if(j == 0)
                numTable[j][i] = numTable[j+1][i-1] % 1000000000;
            else if(j == 9)
                numTable[j][i] = numTable[j-1][i-1] % 1000000000;
            else
                numTable[j][i] = (numTable[j-1][i-1] + numTable[j+1][i-1]) % 1000000000;
        }
    }

    for(int i = 0; i < 10; i++)
        result += numTable[i][n];

    cout << result % 1000000000 << endl;
    
    return 0;
}
