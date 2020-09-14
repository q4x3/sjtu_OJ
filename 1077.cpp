/**
 * dp
 * rt[l][r] 表示区间[l, r]的根
 * f[l][r] 表示区间[l, r]的加分
 **/
#include <iostream>
#include <stdio.h>

using namespace std;

int n, val[40], rt[40][40], f[40][40];

void dfs(int l, int r) {
    if(l > r) return;
    printf("%d ", rt[l][r]);
    dfs(l, rt[l][r] - 1);
    dfs(rt[l][r] + 1, r);
    return;
}

int main() {
    scanf("%d", &n);
    for(int i = 1;i <= n;++ i) {
        scanf("%d", &val[i]);
    }
    for(int i = 1;i <= n;++ i) {
        rt[i][i] = i;
        f[i][i] = val[i];
        f[i][i - 1] = 1;
    }
    for(int i = 2;i <= n;++ i) {
        for(int l = 1;l + i - 1 <= n;++ l) {
            int r = l + i - 1;
            for(int j = l;j <= r;++ j) {
                if(f[l][j - 1] * f[j + 1][r] + val[j] > f[l][r]) f[l][r] = f[l][j - 1] * f[j + 1][r] + val[j], rt[l][r] = j;
            }
        }
    }
    printf("%d\n", f[1][n]);
    dfs(1, n);
    putchar('\n');
    return 0;
}