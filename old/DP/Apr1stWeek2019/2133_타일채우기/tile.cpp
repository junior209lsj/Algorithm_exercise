#include<iostream>

using namespace std;

int main()
{
/*변수 선언*/
    int length; //입력의 크기
    int *tile; //tile[i] : 3xi개의 타일을 채울 수 있는 경우의 수

/*조건 입력 및 초기화*/
    cin >> length;

    tile = new int[length + 1];

    //tile[0]은 알고리즘상 가독성을 높이기 위해 특수히 설정
    tile[0] = 1;
    tile[1] = 0;
    tile[2] = 3;

/*
* 3x홀수개의 판은 채울 수 있는 조합이 없음 tile[홀수] = 0
* 짝수개일 경우 
* case 1 3x2개를 채울 수 있는 경우의 수를 3x(i-2)개의 타일을 채우는 경우의 오른쪽의 붙이는 경우
* case 2 case 1과 중복되지 않으면서 3x4 ...
* case 3 tile[0]*2 = 2 case 1 2와 중복되지 않으면서 3xi개를 채우는 마지막 2개의 경우의 수
*/
    for(int i = 3; i <= length; i++)
    {
        if(i%2 != 0) tile[i] = 0;
        else
        {
            tile[i] = tile[i-2]*3;
            for(int j = 0; j < i-2; j += 2)
                tile[i] += tile[j]*2;
        }
    }
    
/*결과 출력 및 프로그램 종료*/
    cout << tile[length] << endl;

    delete[] tile;
    return 0;
}