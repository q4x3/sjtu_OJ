/**
 * 我真的很讨厌二进制相关的东西
 * 所以讨厌倍增法
 * 请允许我
 * 转成rmq之后线段树
 * 谢谢
 **/
#include <iostream>
#include <cstdio>
const int MAXN = 2e5 + 233;
bool vis[MAXN];
int to[MAXN], next[MAXN], head[MAXN], depth[MAXN], vdepth[MAXN], first[MAXN], val[MAXN], dfscache[10 * MAXN];
int tree[40 * MAXN], treepos[40 * MAXN];
int fa[MAXN];
int n, m, dfscnt, k, cnt, a, b, c;

inline void read(int &x) {
	x = 0;
	char ch;
	bool f = 0; 
	while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-');
	if (ch == '-') f = 1;
	else x = ch - '0';
	while(ch = getchar(), ch >= '0' && ch <= '9') x = 10 * x + ch - '0';
	x = f ? -x : x;
}

void link(int u, int v, int num, int w) {
    to[num] = v, next[num] = head[u], head[u] = num, val[num] = w;
}

void dfs(int rt) {
    vis[rt] = 1;
    ++ dfscnt;
    dfscache[dfscnt] = rt;
    if(first[rt] == 0) first[rt] = dfscnt;
    for(int i = head[rt];i != 0;i = next[i]) {
        if(vis[to[i]]) {
            fa[rt] = to[i];
            continue;
        }
        depth[to[i]] = depth[rt] + 1;
        vdepth[to[i]] = vdepth[rt] + val[i];
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
    if(s > t) std::swap(s, t);
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
    read(n);
    read(m);
    for(int i = 1;i < n;++ i) {
        read(a); read(b); read(c);
        link(a, b, ++ cnt, c);
        link(b, a, ++ cnt, c);
    }
    depth[1] = 1;
    dfs(1);
    build(1, 1, dfscnt);
    char op[5];
    for(int i = 0;i < m;++ i) {
        scanf("%s", op);
        if(op[0] == 'D') {
            read(a); read(b);
            int anc = query(1, 1, dfscnt, first[a], first[b]);
            printf("%d\n", vdepth[a] + vdepth[b] - vdepth[anc] * 2);
        } else {
            read(a); read(b); read(c);
            int anc = query(1, 1, dfscnt, first[a], first[b]);
            int da = depth[a], db = depth[b], danc = depth[anc];
            if(da - danc + 1 == c) {
                printf("%d\n", anc);
            } else if(da - danc + 1 > c) {
                for(int j = 1;j < c;++ j)
                    a = fa[a];
                printf("%d\n", a);
            } else {
                for(int j = 1;j <= da + db - 2 * danc + 1 - c;++ j)
                    b = fa[b];
                printf("%d\n", b);
            }
        }
    }
    return 0;
}