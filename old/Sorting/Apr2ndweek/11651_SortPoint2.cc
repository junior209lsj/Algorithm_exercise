#include<iostream>
#include<algorithm>
#include<stdio.h>

using namespace std;

struct Point
{
    int x;
    int y;
};

bool CmpPtr(Point P1, Point P2)
{
    if(P1.y < P2.y)
        return true;
    else if(P1.y > P2.y)
        return false;
    else 
        return P1.x < P2.x;
}

int main()
{
    int N;
    Point *P;

    cin >> N;
    P = new Point[N];

    for(int i = 0; i < N; i++)
        scanf("%d %d", &P[i].x, &P[i].y);
    
    sort(P, P+N, CmpPtr);

    for(int i = 0; i < N; i++)
        printf("%d %d\n", P[i].x, P[i].y);

    delete[] P;
    return 0;
}