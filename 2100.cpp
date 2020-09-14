/**
 * 最小堆 + 哈夫曼
 * 每次把最小的两个取出来加到一起
 * 加入ans
 * 并放回堆中
 **/
#include <iostream>
#include <stdio.h>

using namespace std;

long long int N, F[50233], ans;

void down(long long int rt, long long int size) {
    long long int tmp = F[rt];
    if((rt << 1) > size) return;
    else if((rt << 1 | 1) > size) {
        if(tmp > F[rt << 1]) {
            F[rt] = F[rt << 1];
            F[rt << 1] = tmp;
        }
        return;
    } else {
        long long int chi1 = F[rt << 1], chi2 = F[rt << 1 | 1];
        if(chi1 < tmp && chi1 <= chi2) {
            F[rt] = chi1;
            F[rt << 1] = tmp;
            down(rt << 1, size);
        } else if(chi2 < tmp && chi2 <= chi1) {
            F[rt] = chi2;
            F[rt << 1 | 1] = tmp;
            down(rt << 1 | 1, size);
        }
    }
}

void build() {
    for(long long int i = N / 2;i > 0;-- i) {
        down(i, N);
    }
}

void op(long long int size) {
    long long int head = F[1];
    F[1] = F[size];
    down(1, size - 1);
    F[1] += head; ans += F[1];
    down(1, size - 1);
}

int main() {
    scanf("%lld", &N);
    for(long long int i = 1;i <= N;++ i)
        scanf("%lld", &F[i]);
    build();
    for(long long int i = 0;i < N - 1;++ i) {
        op(N - i);
    }
    cout << ans << endl;
    return 0;
}