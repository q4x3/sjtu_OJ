/**
 * 线段树
 * 最难写的是query
 * TAT
 * 下 次 一 定
 **/
#include <iostream>
#include <stdio.h>

using namespace std;

const int MAXN = 5e4 + 233;
int lmax[MAXN * 4], rmax[MAXN * 4], totmax[MAXN * 4], lazy[MAXN * 4]; // 退房lazy为-1，入住为1
int N, M;

void build(int rt, int l, int r) {
    if(l == r) {
        lmax[rt] = 1;
        rmax[rt] = 1;
        totmax[rt] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    lmax[rt] = lmax[rt << 1] + lmax[rt << 1 | 1];
    rmax[rt] = rmax[rt << 1] + rmax[rt << 1 | 1];
    totmax[rt] = totmax[rt << 1] + totmax[rt << 1 | 1];
}

void update(int rt, int l, int r, int w) {
    if(w == -1) {
        lmax[rt] = rmax[rt] = totmax[rt] = r - l + 1;
        lazy[rt] = -1;
    } else if(w == 1) {
        lmax[rt] = rmax[rt] = totmax[rt] = 0;
        lazy[rt] = 1;
    }
}

void pushdown(int rt, int l, int r) {
    int mid = (l + r) >> 1;
    update(rt << 1, l, mid, lazy[rt]);
    update(rt << 1 | 1, mid + 1, r, lazy[rt]);
    lazy[rt] = 0;
}

void modify(int rt, int l, int r, int s, int t, int w) {
    if(s <= l && t >= r) {
        update(rt, l, r, w);
        return;
    }
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    if(s <= mid) modify(rt << 1, l, mid, s, t, w);
    if(t > mid) modify(rt << 1 | 1, mid + 1, r, s, t, w);
    if(lmax[rt << 1] < mid - l + 1) lmax[rt] = lmax[rt << 1];
    else lmax[rt] = mid - l + 1 + lmax[rt << 1 | 1];
    if(rmax[rt << 1 | 1] < r - mid) rmax[rt] = rmax[rt << 1 | 1];
    else rmax[rt] = r - mid + rmax[rt << 1];
    totmax[rt] = rmax[rt << 1] + lmax[rt << 1 | 1];
    totmax[rt] = (totmax[rt] > totmax[rt << 1]) ? totmax[rt] : totmax[rt << 1];
    totmax[rt] = (totmax[rt] > totmax[rt << 1 | 1]) ? totmax[rt] : totmax[rt << 1 | 1];
}

int query(int rt, int l, int r, int len) {
    if(l == r) return l;
    int mid = (l + r) >> 1;
    pushdown(rt, l, r);
    if(totmax[rt << 1] >= len) return query(rt << 1, l, mid, len);
    else if(rmax[rt << 1] + lmax[rt << 1 | 1] >= len) return mid - rmax[rt << 1] + 1;
    else return query(rt << 1 | 1, mid + 1, r, len);
}

int main() {
    scanf("%d%d", &N, &M);
    build(1, 1, N);
    for(int i = 0;i < M;++ i) {
        int tmp1, tmp2, tmp3;
        scanf("%d%d", &tmp1, &tmp2);
        if(tmp1 == 1) {
            if(tmp2 > totmax[1]) {
                printf("0\n");
                continue;
            }
            tmp3 = query(1, 1, N, tmp2);
            printf("%d\n", tmp3);
            modify(1, 1, N, tmp3, tmp3 + tmp2 - 1, 1);
        } else {
            scanf("%d", &tmp3);
            modify(1, 1, N, tmp2, tmp2 + tmp3 - 1, -1);
        }
    }
    return 0;
}