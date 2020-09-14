#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

int dt[2000233], tmp1, tmp2, n;

template <typename T>
void merge(int lo, int mi, int hi, T* a) {
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
void mergeSort(int lo, int hi, T* A) {
    if(hi - lo < 2) return;
    int mi = (lo + hi) / 2;
    mergeSort(lo, mi, A); mergeSort(mi, hi, A);
    merge(lo, mi, hi, A);
}

int main() {
    scanf("%d%d", &tmp1, &tmp2);
    n = tmp1 * tmp2;
    for(int i = 1;i <= n;++ i)
        scanf("%d", &dt[i]);
    mergeSort(1, n + 1, dt);
    for(int i = 1;i <= n;++ i)
        printf("%d ", dt[i]);
    printf("\n");
}