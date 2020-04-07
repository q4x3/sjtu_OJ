/**
 * 大模拟好啊
 * 看清题目
 * 一群基佬跳什么舞呢nmsl
 **/
#include <iostream>
#include <stdio.h>
#include <iomanip>

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

long long N, len[100233], qm[2000233], qf[2000233], M, mal, fem, tmps, tmpt, curt;
long long mhead, fhead, malt, femt;
double ans1, ans2;

int main() {
    scanf("%lld", &N);
    for(int i = 0;i < N;++ i) {
        scanf("%lld", &len[i]);
    }
    scanf("%lld", &M);
    for(int i = 0;i < M;++ i) {
        scanf("%lld%lld", &tmps, &tmpt);
        if(tmps == 1) qm[mal ++] = tmpt;
        else qf[fem ++] = tmpt;
    }
    mergeSort(0, mal, qm);
    mergeSort(0, fem, qf);
    for(int i = 0;i < N - 1;++ i) {
        while(qm[mhead] <= curt && qf[fhead] <= curt && mhead < mal && fhead < fem) {
            malt += (curt - qm[mhead]);
            femt += (curt - qf[fhead]);
            ++ mhead;
            ++ fhead;
        }
        curt += len[i];
    }
    for(int i = mhead;i < mal;++ i) {
        malt += (curt - qm[i]);
    }
    for(int i = fhead;i < fem;++ i) {
        femt += (curt - qf[i]);
    }
    if(mal == 0) {
        ans1 = 0;
    } else {
        ans1 = malt / (double)mal;
    }
    if(fem == 0) {
        ans2 = 0;
    } else {
        ans2 = femt / (double)fem;
    }
    cout << fixed << setprecision(2) << ans1 << " " << ans2 << endl;
}