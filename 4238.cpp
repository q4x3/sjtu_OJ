/**
 * 并查集 + 路径压缩模板题
 **/
#include <iostream>
#include <cstdio>

const int MAXN = 2e5 + 233;
int fa[MAXN], n, m, op, x, y;
bool hide[MAXN];

void read(int &x){
	x = 0;
	char ch;
	while (ch = getchar(), (ch < '0' || ch > '9'));
	x = ch - '0';
	while(ch = getchar(), ch >= '0' && ch <= '9') x = 10 * x + ch - '0';
}

int init() {
    for(int i = 1;i <= n;++ i)
        fa[i] = i;
}

int find(int x) {
    int son = x;
    // 路径压缩迭代写法
    // if(fa[x] == x) return x;
    // else return fa[x] = find(fa[x]);
    // 路径压缩循环写法
    while(fa[x] != x) {
        x = fa[x];
    }
    while(son != x) {
        int tmp = fa[son];
        fa[son] = x;
        son = tmp;
    }
    return x;
}

int bind(int x, int y) {
    fa[find(x)] = find(y);
}

int main() {
    read(n); read(m);
    init();
    for(int i = 0;i < m;++ i) {
        read(op);
        if(op == 1) {
            read(x); read(y);
            bind(x, y);
        } else if(op == 2) {
            read(x); read(y);
            if(hide[x] | hide[y]) printf("NO\n");
            else if(find(x) != find(y)) printf("NO\n");
            else printf("YES\n");
        } else {
            read(x);
            hide[x] = 1;
        }
    }
}