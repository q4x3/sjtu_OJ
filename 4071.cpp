/**
 * 矩阵快速幂求斐波那契
 **/
#include <iostream>
#define ll long long

using namespace std;

const ll mo = 1e9 + 7;

struct mat {
    ll a11, a12, a21, a22;
    mat():a11(0), a12(1), a21(1), a22(1) {}
    mat operator*(const mat &other) const {
        mat tmp;
        tmp.a11 = (a11 * other.a11 % mo + a12 * other.a21 % mo) % mo;
        tmp.a12 = (a11 * other.a12 % mo + a12 * other.a22 % mo) % mo;
        tmp.a21 = (a21 * other.a11 % mo + a22 * other.a21 % mo) % mo;
        tmp.a22 = (a21 * other.a12 % mo + a22 * other.a22 % mo) % mo;
        return tmp;
    }
};

mat binary_pow(ll n) {
    mat tmp, cache;
    tmp.a11 = 1; tmp.a12 = 0; tmp.a21 = 0; tmp.a22 = 1;
    while(n > 0) {
        if(n & 1) {
            tmp = tmp * cache;
        }
        cache = cache * cache;
        n >>= 1;
    }
    return tmp;
}

ll n;

int main() {
    cin >> n;
    mat a = binary_pow(n);
    printf("%lld\n", a.a22);
}