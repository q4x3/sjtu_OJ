/**
 * 最小堆
 * 加多少个零需要思考
 **/
#include <iostream>
#define ll long long

using namespace std;

ll M, N;
ll F[101000], ans;

void down(ll rt, ll size) {
    ll tmp = F[rt];
    if((rt << 1) > size) return;
    else if((rt << 1 | 1) > size) {
        if(tmp > F[rt << 1]) {
            F[rt] = F[rt << 1];
            F[rt << 1] = tmp;
        }
        return;
    } else {
        ll chi1 = F[rt << 1], chi2 = F[rt << 1 | 1];
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
    for(ll i = N / 2;i > 0;-- i) {
        down(i, N);
    }
}

void op(ll size) {
    ll tmp = 0;
    for(ll i = 1;i < M;++ i) {
        tmp += F[1];
        F[1] = F[size];
        down(1, -- size);
    }
    tmp += F[1];
    ans += tmp;
    F[1] = tmp;
    down(1, size);
}

int main() {
    scanf("%lld%lld", &N, &M);
    for(ll i = 1;i <= N;++ i) scanf("%lld", &F[i]);
    ll tmp = M;
    while(tmp <= N) tmp *= M;
    tmp /= M;
    if((N - tmp) * M % (M - 1)) tmp = (N - tmp) * M / (M - 1) + 1;
    else tmp = (N - tmp) * M / (M - 1);
    tmp = M - tmp % M;
    if(tmp != M) N += tmp;
    build();
    for(ll i = 0;i < N - 1;i += (M - 1)) {
        op(N - i);
    }
    cout << ans << endl;
}