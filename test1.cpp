#include <iostream>

using namespace std;

int binSearch(int* A, int const& e, int n)
{
    int lo = 0, hi = n;
    while(lo < hi) {
        int mi = (lo + hi) >> 1;
        (e < A[mi]) ? hi = mi : lo = mi + 1;
    }
    return -- lo;
}


void saddleback(int **A, int x, int n) 
{
    int i = 0;
    int j = binSearch(A[0], x, n);
    while (i < n && -1 < j) {
        if (A[i][j] < x) ++ i;
        else if (x < A[i][j]) --j;
        else {cout << i << " " << j << endl; ++i; --j;}
    }
}

int main()
{
    int n, **A;
    cin >> n;
    A = new int *[n];
    for(int i = 0;i < n;++ i)
        A[i] = new int[n];
    for(int i = 0;i < n;++ i)
        for(int j = 0;j < n;++ j)
            cin >> A[i][j];
    saddleback(A, 3, n);
}