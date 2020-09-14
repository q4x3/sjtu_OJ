/**
 * segment tree with lazy
 * song gege nb!!!
 **/
#include <iostream>
#include <stdio.h>

using namespace std;

const int N = 1e2 + 10;
int tree[N * 4], lazy[N * 4], a[N];

void build(int rt, int l, int r) {
    if(l == r) {
        // 叶子节点，递归返回
        tree[rt] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid); // 递归建立左子树
    build(rt << 1 | 1, mid + 1, r); // 递归建立右子树
    tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}

// 修改节点的权值和懒惰标记
void update(int rt, int l, int r, int w) {
    tree[rt] += (r - l + 1) * w; // 更新节点的权值
    lazy[rt] += w; // 更新节点的懒惰标记
}

// 将节点的懒惰标记下传给两个儿子
void pushdown(int rt, int l, int r) {
    int mid = (l + r) >> 1;
    update(rt << 1, l, mid, lazy[rt]); // 将懒惰标记下传给左儿子
    update(rt << 1 | 1, mid + 1, r, lazy[rt]); // 将懒惰标记下传给右儿子
    lazy[rt] = 0; // 懒惰标记清零
}



// 给区间[s, t]中每个数字都加上w
void modify(int rt, int l, int r, int s, int t, int w) {
    if(s <= l && t >= r) { // 线段树节点区间[l, r]被区间[s, t]完全覆盖
        update(rt, l, r, w);
        return;
    }
    pushdown(rt, l, r); // 下传懒惰标记(先把钱还给儿子)
    int mid = (l + r) >> 1;
    if(s <= mid) modify(rt << 1, l, mid, s, t, w);
    // s <= mid 说明区间[s, t]与左儿子[l, mid]区间有交
    if(t > mid) modify(rt << 1 | 1, mid + 1, r, s, t, w);
    // t > mid 说明区间[s, t]与右儿子[mid + 1, r]区间有交
    tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}

int query(int rt, int l, int r, int s, int t) {
    if(s <= l && t >= r) return tree[rt];
    // 区间[s, t]完全覆盖线段树节点的区间[l, r]
    int mid = (l + r) >> 1;
    pushdown(rt, l, r);
    if(t <= mid) return query(rt << 1, l, mid, s, t);
    // 区间[s, t]只与左儿子[l, mid]有交
    else if(s > mid) return query(rt << 1 | 1, mid + 1, r, s, t);
    // 区间[s, t]只与右儿子[mid + 1, r]有交
    else return query(rt << 1, l, mid, s, t)
              + query(rt << 1 | 1, mid + 1, r, s, t);
    // 区间[s, t]同时与左儿子和右儿子有交
}

// 给第x个数加上y
void naive_modify(int rt, int l, int r, int x, int y) {
    if(l == r) {
        // 叶子节点，递归返回
        tree[rt] += y;
        return;
    }
    int mid = (l + r) >> 1;
    if(x <= mid) naive_modify(rt << 1, l, mid, x, y);
    // x <= mid 说明要修改的数字在左子树中
    else naive_modify(rt << 1 | 1, mid + 1, r, x, y);
    // x > mid 说明要修改的数字在右子树中
    tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}

int n;
int main() {
    cin >> n;
    for(int i = 1;i <= n;++ i) {
        cin >> a[i];
    }
    build(1, 1, n);
    modify(1, 1, n, 1, n, 1);
    modify(1, 1, 8, 2, 4, 2);
    return 0;
}