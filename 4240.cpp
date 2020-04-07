/**
 * 桶排序
 * 一个O(n)为什么要卡常
 * 枯了TAT
 * 又知道了一大堆优化方法，真好，就是头冷
 **/
#include <iostream>
#include <stdio.h>
#define re register
#define maxm 2000233
using namespace std;

inline void read(int &x){
	x = 0;
	char ch;
	bool f = 0; 
	while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-');
	if (ch == '-') f = 1;
	else x = ch - '0';
	while(ch = getchar(), ch >= '0' && ch <= '9') x = 10 * x + ch - '0';
	x = f ? -x : x;
}


bool num[4002333];

int main() {
    int s;
    int p;
    re int tmp1;
    re int tmp2;
    re int tmp;
    re int tmpp;
    re int maxi(-123456789);
    re int mini(123456789);
    read(s);
    for(re int i = 0;i < s;++ i) {
        read(tmp);
        tmpp = tmp + maxm;
        num[tmpp] = 1;
        if(tmpp > maxi) maxi = tmpp;
        if(tmpp < mini) mini = tmpp;
    }
    read(p);
    for(re int i = 0;i < p;++ i) {
        read(tmp1);
        read(tmp2);
        tmpp = tmp2 + maxm;
        if(tmp1 == 1) {
            num[tmpp] = 1;
            if(tmpp > maxi) maxi = tmpp;
            if(tmpp < mini) mini = tmpp;
        } else {
            num[tmpp] = 0;
        }
    }
    for(re int i = mini;i <= maxi;++ i) {
        if(num[i])
            printf("%d ", i - maxm);
    }
}