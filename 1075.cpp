#include <iostream>

using namespace std;
/*dp
 *按第一个字符分类
 *a:f[n - 1]
 *'(':按对应')'位置，若为j，则f[j - 1] * f[n - j - 1]
 */
int f[3340];
int main() {
    int N;
    cin >> N;
    f[0] = 1;
    f[1] = 1;
    for(int i = 2;i <= N;++ i) {
        f[i] += f[i - 1];
        for(int j = 1;j < i;++ j) {
            f[i] += (f[j - 1] * f[i - j - 1] % 19301);
            f[i] %= 19301;
        }
    }
    cout << f[N] << endl;
}