/**
 * 模拟
 **/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

int dt[100233], N, M, op;

void insert(int x, int y) {
    ++ N;
    for(int i = N;i > x + 1;-- i)
        dt[i] = dt[i - 1];
    dt[x + 1] = y;
}

void del(int x) {
    -- N;
    for(int i = x;i <= N;++ i)
        dt[i] = dt[i + 1];
}

int main() {
    scanf("%d%d", &N, &M);
    for(int i = 1;i <= N;++ i)
        scanf("%d", &dt[i]);
    for(int i = 0;i < M;++ i) {
        scanf("%d", &op);
        if(op == 1) {
            int x, y;
            scanf("%d%d", &x, &y);
            insert(x, y);
        } else {
            int x;
            scanf("%d", &x);
            del(x);
        }
    }
    for(int i = 1;i <= N;++ i)
        printf("%d ", dt[i]);
    printf("\n");
}