/**
 * 数学题
 * 求出差异数组
 * 无脑扫描: 分正负串
 * 一串正数中，如果当前扫到的数大于左侧相邻的数，则加上差，否则继续
 * 负数类似
 * 差分: [lo, hi)同时+1相当于其差分数组(右减左)lo加1，hi减1
 **/
#include <iostream>

using namespace std;

int N;
long long a[100233], b[100233], c[100233], tmp1, tmp2;

int main() {
    cin >> N;
    for(int i = 0;i < N;++ i)
        cin >> a[i];
    for(int i = 0;i < N;++ i)
        cin >> b[i];
    for(int i = 1;i <= N;++ i)
        c[i] = b[i - 1] - a[i - 1];
    /**
     * 差分法
    for(int i = 1;i <= N;++ i) {
        if(c[i] >= c[i - 1]) tmp1 += (c[i] - c[i - 1]);
        else tmp2 += (c[i - 1] - c[i]);
    }
    if(tmp1 >= tmp2) cout << tmp1 << endl;
    else cout << tmp2 << endl;
     * */

    /**
     * 无脑扫描法
     * */
    for(int i = 1;i <= N;++ i) {
        if(c[i] == 0) continue;
        if(c[i] > 0) {
            if(c[i - 1] >= 0) {
                if(c[i - 1] < c[i]) ans += (c[i] - c[i - 1]);
                continue;
            } else {
                ans += c[i];
                continue;
            }
        } else if (c[i] < 0) {
            if(c[i - 1] >= 0) {
                ans -= c[i];
                continue;
            } else {
                if(c[i - 1] > c[i]) ans += (c[i - 1] - c[i]);
                continue;
            }
        }
    }
    cout << ans << endl;
}