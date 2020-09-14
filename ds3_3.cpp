/**
 * 40分
 **/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define ll long long

const int MAXN = 2e5 + 233;
ll n, a[MAXN], b[MAXN], ans;

int main() {
    scanf("%lld", &n);
    for(int i = 1;i <= n;++ i)
        scanf("%lld", &a[i]);
    for(int i = 1;i <= n;++ i)
        scanf("%lld", &b[i]);
    for(int i = 1;i <= n;++ i)
        for(int j = 1;j <= n;++ j) {
            ll tmp = a[i] + b[j];
            ans = ans ^ tmp;
        }
    printf("%lld\n", ans);
}