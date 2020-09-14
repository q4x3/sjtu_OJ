/**
 * 40分
 **/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

const int MAXN = 1233;

bool vis[MAXN];
int n, ord[MAXN], tmp1, tmp2;

int main() {
    scanf("%d", &n);
    if(n > 1233) return 0;
    for(int i = 0;i < n;++ i) {
        scanf("%d%d", &tmp1, &tmp2);
        tmp1 %= n;
        if(vis[tmp1] == 0) {
            vis[tmp1] = 1;
            ord[tmp1] = tmp2;
        } else {
            bool flag = 0;
            for(int j = tmp1 + 1;j < n;++ j) {
                if(vis[j] == 0) {
                    vis[j] = 1;
                    ord[j] = tmp2;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) {
                for(int j = 0;j < tmp1;++ j) {
                    if(vis[j] == 0) {
                        vis[j] = 1;
                        ord[j] = tmp2;
                        break;
                    }
                }
            }
        }
    }
    for(int i = 0;i < n;++ i) {
        printf("%d ", ord[i]);
    }
    printf("\n");
}