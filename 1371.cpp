/**
 * 模...拟...?
 **/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

int n, m, tmp, l, r;
int dt[100233], a[100233], maxx;

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1;i <= n;++ i) {
        scanf("%d", &dt[i]);
        maxx = dt[i] > maxx ? dt[i] : maxx;
    }
    for(int i = 1;i <= n;++ i) {
        for(int j = dt[i];j <= maxx;++ j)
            ++ a[j];
    }
    for(int i = 1;i <= m;++ i) {
        scanf("%d%d", &l, &r);
        printf("%d\n", a[r] - a[l - 1]);
    }
}