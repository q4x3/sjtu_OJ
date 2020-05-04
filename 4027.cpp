/**
 * lcs->lis
 * nlogn
 * lis[i]表示长度为i的上升子序列最后一位最小是多少
 **/
#include <iostream>
#include <stdio.h>

using namespace std;

int inv[100233], lis[100233], seq[100233], n, len, tmp;

int lower_bound(int lo, int hi, int a) {
    if(lo >= hi) return lo;
    int mi = (lo + hi) >> 1;
    if(lis[mi] < a) return lower_bound(mi + 1, hi, a);
    else return lower_bound(lo, mi, a);
}

int main() {
    scanf("%d", &n);
    for(int i = 1;i <= n;++ i) {
        scanf("%d", &tmp);
        inv[tmp] = i;
    }
    for(int i = 1;i <= n;++ i) {
        scanf("%d", &tmp);
        seq[i] = inv[tmp];
    }
    for(int i = 1;i <= n;++ i) {
        if(seq[i] > lis[len]) {
            lis[++ len] = seq[i];
        } else {
            int tmp1 = lower_bound(1, len, seq[i]);
            lis[tmp1] = seq[i];
        }
    }
    printf("%d\n", len);
}