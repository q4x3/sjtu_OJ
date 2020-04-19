/**
 * 单点修改 + 区间最值
 * 标准线段树板子
 * 作为老师请务必严厉，不要让学生的成绩太好看
 **/
#include <iostream>
#include <stdio.h>

using namespace std;

const int N = 2e5 + 10;
int a[N], tree[N << 2];

void build(int rt, int l, int r) {
    if(l == r) {
        tree[rt] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    tree[rt] = (tree[rt << 1] > tree[rt << 1 | 1]) ? tree[rt << 1] : tree[rt << 1 | 1];
}

void modify(int rt, int l, int r, int x, int y) {
    if(l == r) {
        tree[rt] = y;
        return;
    }
    int mid = (l + r) >> 1;
    if(x <= mid) modify(rt << 1, l, mid, x, y);
    else modify(rt << 1 | 1, mid + 1, r, x, y);
    tree[rt] = (tree[rt << 1] > tree[rt << 1 | 1]) ? tree[rt << 1] : tree[rt << 1 | 1];
}

int query(int rt, int l, int r, int s, int t) {
    if(s <= l && t >= r) return tree[rt];
    int mid = (l + r) >> 1;
    if(t <= mid) return query(rt << 1, l, mid, s, t);
    else if(s > mid) return query(rt << 1 | 1, mid + 1, r, s, t);
    else {
        int tmp3 = query(rt << 1, l, mid, s, t);
        int tmp4 = query(rt << 1 | 1, mid + 1, r, s, t);
        return (tmp3 > tmp4) ? tmp3 : tmp4;
    }
}

int n, m;

int main() {
    scanf("%d", &n);
    scanf("%d", &m);
    for(register int i = 1;i <= n;++ i) {
        scanf("%d", &a[i]);
    }
    build(1, 1, n);
    for(register int i = 0;i < m;++ i) {
        char tmp[3];
        int tmp1, tmp2;
        scanf("%s", tmp);
        scanf("%d%d", &tmp1, &tmp2);
        if(tmp[0] == 'Q') {
            printf("%d\n", query(1, 1, n, tmp1, tmp2));
        } else {
            modify(1, 1, n, tmp1, tmp2);
        }
    }
}