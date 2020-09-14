/**
 * 区间最大问题
 * 拿线段树混的
 **/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

const int MAXN = 1e5 + 233;
int dt[MAXN], tree[MAXN << 2];
int m, n, l, r;

int maxx(int x, int y) {
    return x > y ? x : y;
}

void build(int l, int r, int rt) {
    if(l == r) {
        tree[rt] = dt[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
    tree[rt] = maxx(tree[rt << 1], tree[rt << 1 | 1]);
}

int query(int rt, int l, int r, int s, int t) {
    if(s <= l && t >= r) return tree[rt];
    int mid = (l + r) >> 1;
    if(t <= mid) return query(rt << 1, l, mid, s, t);
    else if(s > mid) return query(rt << 1 | 1, mid + 1, r, s, t);
    else return maxx(query(rt << 1, l, mid, s, t),
                     query(rt << 1 | 1, mid + 1, r, s, t));
}

int main() {
    scanf("%d", &n);
    for(int i = 1;i <= n;++ i)
        scanf("%d", &dt[i]);
    build(1, n, 1);
    scanf("%d", &m);
    for(int i = 1;i <= m;++ i) {
        scanf("%d%d", &l, &r);
        printf("%d\n", query(1, 1, n, l, r));
    }
}