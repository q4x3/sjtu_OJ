/**
 * 我真的很讨厌二进制相关的东西
 * 所以讨厌倍增法
 * 请允许我
 * 转成rmq之后线段树
 * 谢谢
 * 一开始忘了双向建边要开两倍空间了，憨憨QAQ
 **/
#include <iostream>
#include <cstdio>
const int MAXN = 8e4 + 233;
bool vis[MAXN];
int to[MAXN], next[MAXN], head[MAXN], depth[MAXN], first[MAXN], dfscache[10 * MAXN];
int tree[40 * MAXN], treepos[40 * MAXN];
int n, m, tmp, tmpp, dfscnt, k, mini, maxi, root, cnt;

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

void link(int u, int v, int num) {
    to[num] = v, next[num] = head[u], head[u] = num;
}

void dfs(int rt) {
    vis[rt] = 1;
    ++ dfscnt;
    dfscache[dfscnt] = rt;
    if(first[rt] == 0) first[rt] = dfscnt;
    for(int i = head[rt];i != 0;i = next[i]) {
        if(vis[to[i]]) continue;
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
    if(tmp1 < tmp2) {
        tree[rt] = tmp1;
        treepos[rt] = treepos[rt << 1];
    } else {
        tree[rt] = tmp2;
        treepos[rt] = treepos[rt << 1 | 1];
    }
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
    read(n);
    for(int i = 1;i <= n;++ i) {
        read(tmp); read(tmpp);
        if(tmpp == -1) {
            root = tmp;
            continue;
        }
        link(tmp, tmpp, ++ cnt);
        link(tmpp, tmp, ++ cnt);
    }
    depth[root] = 1;
    dfs(root);
    build(1, 1, dfscnt);
    read(m);
    for(int i = 0;i < m;++ i) {
        read(tmp); read(tmpp);
        mini = first[tmp];
        maxi = first[tmpp];
        if(mini < maxi) {
            int tmp0 = query(1, 1, dfscnt, mini, maxi);
            if(tmp0 == tmp) printf("1\n");
            else if(tmp0 == tmpp) printf("2\n");
            else printf("0\n");
        } else {
            int tmp0 = query(1, 1, dfscnt, maxi, mini);
            if(tmp0 == tmp) printf("1\n");
            else if(tmp0 == tmpp) printf("2\n");
            else printf("0\n");
        }
    }
    return 0;
}