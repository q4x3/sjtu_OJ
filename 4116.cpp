/**
 * 排序 + 二分
 **/
#include <iostream>
#include <stdio.h>

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

int N, C, pos[100233];

bool check(int dis) {
    int cnt = 1, cur = 0;
    for(int i = 1; i < N;++ i) {
        if(pos[i] - pos[cur] >= dis) {
            ++ cnt;
            cur = i;
            if(cnt >= C) return 1;
        }
    }
    return 0;
}

int main() {
    scanf("%d%d", &N, &C);
    for(int i = 0;i < N;++ i) {
        scanf("%d", &pos[i]);
    }
    mergeSort(0, N, pos);
    int lo = 0, hi = 1e9 + 10;
    while(lo <= hi) {
        int mi = (lo + hi) / 2;
        if(check(mi)) {
            lo = mi + 1;
        } else {
            hi = mi - 1;
        }
    }
    cout << lo << endl;
}