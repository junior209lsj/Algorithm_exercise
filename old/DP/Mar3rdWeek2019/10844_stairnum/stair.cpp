/******************************
*10844�� ���� ��� ��         *
*******************************/
#include<iostream>

using namespace std;

int main()
{
    /*���� �����*/
    long numTable[10][101] = { 0 };
    int n;
    long result = 0;
    /*�Էº�*/
    cin >> n;
    /*����*/

      /*******************************************************************************************
       *numTable[i][n] : i�� ������ n�ڸ��� ��� ��                                              *
       *sum i = 0 to 9 numtable[i][n] : n�ڸ��� ��� ���� ���� �� �ִ� ����� ��                 *
       *******************************************************************************************/

    /*�ʱ�ȭ*/
    numTable[0][1] = 0;
    for(int i = 1; i < 10; i++)
        numTable[i][1] = 1;

    /*���*/ 
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
