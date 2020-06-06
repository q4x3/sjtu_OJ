/**
 * 80分
 **/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

const int MAXN = 1e0 + 233;

bool vis[MAXN], tree[MAXN << 2];
int n, ord[MAXN], tmp1, tmp2, lmax[MAXN << 2];


void build(int rt, int l, int r) {
    if(l == r) {
        lmax[rt] = l;
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    lmax[rt] = lmax[rt << 1];
}

void modify(int rt, int l, int r, int p) {
    if(l == r) {
        tree[rt] = 1;
        lmax[rt] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    if(p <= mid) modify(rt << 1, l, mid, p);
    else modify(rt << 1 | 1, mid + 1, r, p);
    tree[rt] = tree[rt << 1] & tree[rt << 1 | 1];
    if(lmax[rt << 1] == 0) lmax[rt] = lmax[rt << 1 | 1];
    else lmax[rt] = lmax[rt << 1];
}

int query(int rt, int l, int r, int s, int t) {
    if(s <= l && t >= r) {
        return lmax[rt];
    }
    int mid = (l + r) >> 1;
    if(t <= mid) return query(rt << 1, l, mid, s, t);
    else if(s > mid) return query(rt << 1 | 1, mid + 1, r, s, t);
    else {
        int q1 = query(rt << 1, l, mid, s, t), q2 = query(rt << 1 | 1, mid + 1, r, s, t);
        if(q1 == 0) return q2;
        else return q1;
    }
}

int main() {
    scanf("%d", &n);
    build(1, 1, n);
    for(int i = 1;i <= n;++ i) {
        scanf("%d%d", &tmp1, &tmp2);
        tmp1 %= n;
        ++ tmp1;
        if(vis[tmp1] == 0) {
            vis[tmp1] = 1;
            ord[tmp1] = tmp2;
            modify(1, 1, n, tmp1);
        } else {
            int tmp = query(1, 1, n, tmp1 + 1, n);
            if(tmp == 0)
                tmp = query(1, 1, n, 1, tmp1);
            vis[tmp] = 1;
            ord[tmp] = tmp2;
            modify(1, 1, n, tmp);
        }
    }
    for(int i = 1;i <= n;++ i) {
        printf("%d ", ord[i]);
    }
    printf("\n");
}