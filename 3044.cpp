/**
 * dp
 * f[n] = f[1] + f[2] + ... + f[n / 2]
 * 注意long long
 **/
#include <iostream>

using namespace std;

long long N, f[1010];

int main() {
    cin >> N;
    f[0] = 1;
    f[1] = 1;
    for(int i = 2;i <= N;++ i) {
        for(int j = 0;j <= i >> 1;++ j) {
            f[i] += f[j];
            f[i] %= 1000000007;
        }
    }
    cout << f[N] << endl;
}