#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    int *A, *B;
    int sum = 0;

    cin >> N;

    A = new int[N];
    B = new int[N];

    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];

    sort(A, A + N, greater<int>());
    sort(B, B + N, less<int>());

    for (int i = 0; i < N; i++)
        sum += A[i] * B[i];

    cout << sum << endl;

    delete[] A;
    delete[] B;
    return 0;
}
