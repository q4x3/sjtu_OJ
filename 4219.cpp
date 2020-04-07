#include <iostream>
#include <stdio.h>
#define modd 1000000007
using namespace std;

template <typename T>
void merge(int lo, int mi, int hi, T* a)
{
    T* A = a + lo;
    int lb = mi - lo;
    T* B = new T[lb];
    T* BB = B;
    for(int i = 0;i < lb;++ i)
        B[i] = A[i];
    int lc = hi - mi;
    T* C = a + mi;
    int cnt = 0;
    while(1) {
        if ((lb == 0) && (lc == 0)) break;
        if (lb == 0) {
            A[cnt] = C[0];
            ++ cnt; ++ C; -- lc;
        }
        else if (lc == 0) {
            A[cnt] = B[0];
            ++ cnt; ++ B; --lb;
        }
        else {
            if(B[0] < C[0]) {
                A[cnt] = B[0];
                ++ cnt; ++ B; -- lb;
            }
            else {
                A[cnt] = C[0];
                ++ cnt; ++ C; -- lc;
            }
        }
    }
    delete []BB;
}

template <typename T>
void mergeSort(int lo, int hi, T* A)
{
    if(hi - lo < 2) return;
    int mi = (lo + hi) / 2;
    mergeSort(lo, mi, A); mergeSort(mi, hi, A);
    merge(lo, mi, hi, A);
}

int T, n, tmp, a[200233];
long long b[200233];

int main() {
    scanf("%d%d", &T, &n);
    for(register int i = 0;i < n;++ i) {
        scanf("%d", &a[i]);
    }
    mergeSort(0, n, a);
    for(register int i = 1;i <= n;++ i) {
        b[i] = (b[i - 1] + (long long)a[n - i]) % modd;
    }
    for(register int i = 0;i < T;++ i) {
        scanf("%d", &tmp);
        printf("%lld\n", b[tmp]);
    }
}