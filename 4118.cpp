/**
 * dfs
 * 一个个找子树
 **/
#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int m;
char s1[30], s2[30];
int C[30];

void init() {
    C[0] = 1;
    for(int i = 1;i <= m;++ i)
        C[i] = C[i - 1] * (m - i + 1) / i;
}

int dfs(int pre, int pos, int len) {
    int cnt = 0, sum = 1;
    for(int i = pre + 1, j = pos;i < pre + len;) {
        int tmp1 = i, tmp2 = j;
        while(j < pre + len - 1 && s1[tmp1] != s2[j])
            ++ i, ++ j;
        ++ cnt;
        sum *= dfs(tmp1, tmp2, j - tmp2 + 1);
        ++ i; ++ j;
    }
    sum *= C[cnt];
    return sum;
}

int main() {
    scanf("%d%s%s", &m, s1, s2);
    if(s1[0] != s2[strlen(s2) - 1]) {
        printf("0\n");
        return 0;
    }
    init();
    printf("%d\n", dfs(0, 0, strlen(s1)));
}