/**
 * dp
 * f[i]表示第i颗子弹对答案的贡献
 * 状态转移方程:
 * f[i] = ((1 - a[i - 1]) + a[i - 1] * (f[i - 1] / a[i - 1] + 2)) * a[i]
 * 化简
 * 注意输出格式
 **/
#include <iostream>
#include <iomanip>

using namespace std;

int N;
double a[100233], f[100233], ans;

int main() {
    cin >> N;
    for(int i = 1;i <= N;++ i)
        cin >> a[i];
    f[1] = a[1];
    ans = a[1];
    for(int i = 2;i <= N;++ i) {
        f[i] = (1 + f[i - 1] + a[i - 1]) * a[i];
        ans += f[i];
    }
    cout << fixed << setprecision(6) << ans << endl;
}