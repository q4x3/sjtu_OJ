/**
 * 分块
 * 线段树也可但是我不会写
 * 分块nb！快读nb！inline nb！register nb！
 **/
#include <iostream>
#include <stdio.h>
#include <cmath>
#define re register
using namespace std;

inline void read(int &x) {
    x = 0;
	char ch;
	while (ch = getchar(), ch < '0' || ch > '9');
	x = ch - '0';
	while(ch = getchar(), ch >= '0' && ch <= '9') x = 10 * x + ch - '0';
}

int n, q, a[200233], maxi[200233], blocknum;
// int n, q, a[200], maxi[200], blocknum;
int tmp1, tmp2, tmp3, tmp4;
inline void init() {
    blocknum = sqrt(n);
    for(re int i = 0;i < blocknum;++ i) {
        int tmp = i * blocknum;
        for(re int j = 0;j < blocknum;++ j) {
            if(a[tmp + j] > maxi[i])
                maxi[i] = a[tmp + j];
        }
    }
    int tmp = blocknum * blocknum;
    for(re int i = 0;i < n - tmp;++ i) {
        if(a[tmp + i] > maxi[blocknum])
            maxi[blocknum] = a[tmp + i];
    }
}

int main() {
    read(n);
    read(q);
    for(re int i = 0;i < n;++ i) 
        read(a[i]);
    init();
    for(re int i = 0;i < q;++ i) {
        re int ans = 0;
        read(tmp1);
        read(tmp2);
        -- tmp1; -- tmp2;
        tmp3 = tmp1 / blocknum + 1;
        tmp4 = tmp2 / blocknum - 1;
        for(re int j = tmp3;j <= tmp4;++ j)
            if(maxi[j] > ans) ans = maxi[j];
        int tmp5 = tmp1;
        while(tmp1 < tmp3 * blocknum && tmp1 < tmp2) {
            if(a[tmp1] > ans) ans = a[tmp1];
            ++ tmp1;
        }
        while(tmp2 >= tmp4 * blocknum && tmp2 >= tmp5) {
            if(a[tmp2] > ans) ans = a[tmp2];
            -- tmp2;
        }
        printf("%d\n", ans);
    }
    return 0;
}