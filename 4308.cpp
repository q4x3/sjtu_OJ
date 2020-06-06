/**
 * 我真的很讨厌二进制相关的东西
 * 所以讨厌倍增法
 * 请允许我
 * 转成rmq之后线段树
 * 谢谢
 **/
#include <iostream>
#include <cstdio>
const int MAXN = 1e5 + 233;
int to[MAXN], next[MAXN], head[MAXN], depth[MAXN], first[MAXN], dfscache[10 * MAXN];
int tree[40 * MAXN], treepos[40 * MAXN];
int n, m, tmp, dfscnt, k, mini, maxi;

void link(int u, int v, int num) {
    to[num] = v, next[num] = head[u], head[u] = num;
}

void dfs(int rt) {
    ++ dfscnt;
    dfscache[dfscnt] = rt;
    if(first[rt] == 0) first[rt] = dfscnt;
    for(int i = head[rt];i != 0;i = next[i]) {
        depth[to[i]] = depth[rt] + 1;
        dfs(to[i]);
        ++ dfscnt;
        dfscache[dfscnt] = rt;
    }
}

void build(int rt, int l, int r) {
    if(l == r) {
        tree[rt] = depth[dfscache[l]];
        treepos[rt] = dfscache[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    int tmp1 = tree[rt << 1], tmp2 = tree[rt << 1 | 1];
    tree[rt] = tmp1 < tmp2 ? tmp1 : tmp2;
    treepos[rt] = tmp1 < tmp2 ? treepos[rt << 1] : treepos[rt << 1 | 1];
}

int query(int rt, int l, int r, int s, int t) {
    if(s <= l && r <= t) {
        return treepos[rt];
    }
    int mid = (l + r) >> 1;
    if(t <= mid) return query(rt << 1, l, mid, s, t);
    else if(s > mid) return query(rt << 1 | 1, mid + 1, r, s, t);
    else {
        int tmp1 = query(rt << 1, l, mid, s, t), tmp2 = query(rt << 1 | 1, mid + 1, r, s, t);
        return (depth[tmp1] < depth[tmp2]) ? tmp1 : tmp2;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1;i < n;++ i) {
        scanf("%d", &tmp);
        link(tmp, i + 1, i);
    }
    depth[1] = 1;
    dfs(1);
    build(1, 1, dfscnt);
    for(int i = 0;i < m;++ i) {
        scanf("%d", &k);
        mini = 1e5 + 233;
        maxi = -1;
        for(int i = 0;i < k;++ i) {
            scanf("%d", &tmp);
            mini = (first[tmp] < mini) ? first[tmp] : mini;
            maxi = (first[tmp] > maxi) ? first[tmp] : maxi;
        }
        printf("%d\n", query(1, 1, dfscnt, mini, maxi));
    }
    return 0;
}