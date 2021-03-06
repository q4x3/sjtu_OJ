/**
 * 模拟
 * 将矩形较短的边作为正方形边长
 * 注意long long
 **/
#include <iostream>

using namespace std;

long long m, n, ans;
int main() {
    cin >> m >> n;
    while(m != 0 || n != 0) {
        if(m == n) {
            ans += 4 * m;
            break;
        }
        if(m > n) {
            ans += 4 * n;
            m = m - n;
        }
        if(m < n) {
            ans += 4 * m;
            n = n - m;
        }
    }
    cout << ans << endl;
}