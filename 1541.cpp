/**
 * 区间最大问题
 * 拿线段树混的
 **/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define ll long long

const int MAXN = 2e5 + 233;
ll dt[MAXN], tree[MAXN << 2];
int k, n;

ll maxx(ll x, ll y) {
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

ll query(int rt, int l, int r, int s, int t) {
    if(s <= l && t >= r) return tree[rt];
    int mid = (l + r) >> 1;
    if(t <= mid) return query(rt << 1, l, mid, s, t);
    else if(s > mid) return query(rt << 1 | 1, mid + 1, r, s, t);
    else return maxx(query(rt << 1, l, mid, s, t),
                     query(rt << 1 | 1, mid + 1, r, s, t));
}

int main() {
    scanf("%d%d", &k, &n);
    for(int i = 1;i <= n;++ i)
        scanf("%lld", &dt[i]);
    build(1, n, 1);
    for(int i = 1;i <= n - k + 1;++ i)
        printf("%lld ", query(1, 1, n, i, i + k - 1));
    printf("\n");
}