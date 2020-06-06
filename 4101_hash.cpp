/**
 * 原来这题能hash + 二分啊
 * hash大法好
 * 呜呜呜我还想着用邻接表存个trie树再lca
 * 我是憨憨
 **/
#include <cstdio>
#include <cstring>
#include <iostream>

const int base = 233;
const int mod = 1 << 30;
int *hash[100233];
int length[100233], A[12], n, m, op, len, k, minlen;
char s[10233];

void preProcess() {
    for(int i = 1;i <= n;++ i) {
        scanf("%s", s);
        len = strlen(s);
        hash[i] = new int[len + 233];
        length[i] = len;
        hash[i][0] = 0;
        for(int j = 1;j <= len;++ j)
            hash[i][j] = (hash[i][j - 1] * base + s[len - j] - 'a' + 1) % mod;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    preProcess();
    for(int i = 0;i < m;++ i) {
        scanf("%d", &op);
        if(op == 1) {
            scanf("%s", s);
            len = strlen(s);
            hash[++ n] = new int[len + 233];
            length[n] = len;
            hash[n][0] = 0;
            for(int j = 1;j <= len;++ j)
                hash[n][j] = (hash[n][j - 1] * base + s[len - j] - 'a' + 1) % mod;
        } else {
            scanf("%d", &k);
            minlen = 10233;
            for(int j = 0;j < k;++ j) {
                scanf("%d", &A[j]);
                minlen = length[A[j]] < minlen ? length[A[j]] : minlen;
            }
            int l = 0, r = minlen;
            while(l <= r) {
                int mid = (l + r) >> 1, cmp = hash[A[0]][mid];
                bool flag = 1;
                for(int j = 1;j < k;++ j) {
                    if(hash[A[j]][mid] != cmp) {
                        flag = 0;
                        break;
                    }
                }
                if(flag) l = mid + 1;
                else r = mid - 1;
            }
            printf("%d\n", l - 1);
        }
    }
}