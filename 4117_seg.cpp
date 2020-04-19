/**
 * segment tree with lazy
 * song gege nb!!!
 **/
#include <iostream>
#include <stdio.h>

using namespace std;

const int N = 1e5 + 10;
long long tree[N * 4], lazy[N * 4];
int a[N];

inline void read(int &x){
	x = 0;
	char ch;
	bool f = 0; 
	while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-');
	if (ch == '-') f = 1;
	else x = ch - '0';
	while(ch = getchar(), ch >= '0' && ch <= '9') x = 10 * x + ch - '0';
	x = f ? -x : x;
}

inline void build(int rt, int l, int r) {
    if(l == r) {
        // 叶子节点，递归返回
        tree[rt] = (long long)a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid); // 递归建立左子树
    build(rt << 1 | 1, mid + 1, r); // 递归建立右子树
    tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}

// 修改节点的权值和懒惰标记
inline void update(int rt, int l, int r, int w) {
    tree[rt] += (r - l + 1) * w; // 更新节点的权值
    lazy[rt] += w; // 更新节点的懒惰标记
}

// 将节点的懒惰标记下传给两个儿子
inline void pushdown(int rt, int l, int r) {
    int mid = (l + r) >> 1;
    update(rt << 1, l, mid, lazy[rt]); // 将懒惰标记下传给左儿子
    update(rt << 1 | 1, mid + 1, r, lazy[rt]); // 将懒惰标记下传给右儿子
    lazy[rt] = 0; // 懒惰标记清零
}



// 给区间[s, t]中每个数字都加上w
inline void modify(int rt, int l, int r, int s, int t, int w) {
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

long long query(int rt, int l, int r, int s, int t) {
    if(s <= l && t >= r) return tree[rt];
    // 区间[s, t]完全覆盖线段树节点的区间[l, r]
    int mid = (l + r) >> 1;
    pushdown(rt, l, r);
    if(t <= mid) return query(rt << 1, l, mid, s, t);
    // 区间[s, t]与左儿子[l, mid]有交
    else if(s > mid) return query(rt << 1 | 1, mid + 1, r, s, t);
    // 区间[s, t]与右儿子[mid + 1, r]有交
    else return query(rt << 1, l, mid, s, t)
              + query(rt << 1 | 1, mid + 1, r, s, t);
    // 区间[s, t]同时与左儿子和右儿子有交
}

int n, Q, tmp1, tmp2, tmp3;
char tmp;

int main() {
    read(n);
    read(Q);
    for(register int i = 1;i <= n;++ i) {
        read(a[i]);
    }
    build(1, 1, n);
    for(register int i = 0;i < Q;++ i) {
        while (tmp = getchar(), tmp == '\n' || tmp == '\r' || tmp == ' ');
        read(tmp1);
        read(tmp2);
        if(tmp == 'Q') {
            printf("%lld\n", query(1, 1, n, tmp1, tmp2));
        } else {
            read(tmp3);
            modify(1, 1, n, tmp1, tmp2, tmp3);
        }
    }
}