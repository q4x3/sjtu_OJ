/**
 * 赖学姐的版本
 * 其实可以不要label_rev数组
 * rev是reverse的abbr
 * 想表达的是label的逆操作
 **/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200;

int n;
int ls[MAXN], rs[MAXN];
int label_rev[MAXN];

void add_child(int f, int c) {
    if (!ls[f])
        ls[f] = c;
    else {
        if (ls[f] > c) {
            rs[f] = ls[f];
            ls[f] = c;
        } else
            rs[f] = c;
    }
}

void dfs(int o, int _label) {
    if (_label > n) {
        puts("false");
        exit(0);
    }
    label_rev[_label] = o;
    

    if (ls[o])
        dfs(ls[o], _label << 1);
    if (rs[o])
        dfs(rs[o], _label << 1 | 1);
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 2, f; i <= n; i++) {
        scanf("%d", &f);
        add_child(f + 1, i);
    }

    dfs(1, 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (label_rev[i])
            cnt++;
    puts(cnt == n ? "true" : "false");
    return 0;
}
