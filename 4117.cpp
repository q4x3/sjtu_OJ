/**
 * 树状数组..
 * 再过不了就对lowbit打表了TATTTTTTTTTTT
 * 有空写个分块
 **/
#include <iostream>
#include <stdio.h>
 
using namespace std;
 
long long a[100010], b[100010], c[100010];
int N, M, tmp1, tmp2, tmp3;
char tmp;
 
void read(int &x){
	x = 0;
	char ch;
	bool f = 0; 
	while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-');
	if (ch == '-') f = 1;
	else x = ch - '0';
	while(ch = getchar(), ch >= '0' && ch <= '9') x = 10 * x + ch - '0';
	x = f ? -x : x;
}

int lowbit(int x) {
    return x & (-x);
}
 
void add(long long *a, int pos, long long val) {
    for(;pos <= N;pos += lowbit(pos)) {
        a[pos] += val;
    }
}
 
long long addd(long long *a, int pos) {
    long long sum = 0;
    for(;pos != 0;pos -= lowbit(pos)) {
        sum += a[pos];
    }
    return sum;
}
 
int main() {
    read(N);
    read(M);
    int x;
    for(int i = 1;i <= N;++ i) {
        read(x);
        a[i] = x;
        add(b, i, a[i] - a[i - 1]);
        add(c, i, (i - 1) * (a[i] - a[i - 1]));
    }
    for(int i  = 0;i < M;++ i) {
        while (tmp = getchar(), tmp == '\n' || tmp == '\r' || tmp == ' ');
        read(tmp1);
        read(tmp2);
        if(tmp == 'Q') {
            long long s1, s2;
            s1 = (tmp1 - 1) * addd(b, tmp1 - 1) - addd(c, tmp1 - 1);
            s2 = tmp2 * addd(b, tmp2) - addd(c, tmp2);
            printf("%lld\n", s2 - s1);
        } else {
            read(tmp3);
            add(b, tmp1, tmp3);
            add(b, tmp2 + 1, - tmp3);
            add(c, tmp1, 1LL * tmp3 * (tmp1 - 1));
            add(c, tmp2 + 1, -1LL * tmp3 * tmp2);
        }
    }
    return 0;
}