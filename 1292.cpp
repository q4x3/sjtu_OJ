/**
 * 模拟(数学题?)
 * 先找环
 * 交换次数: 所有环交换次数相加
 * 交换时间: 长度为一的环0，长度
 * 为二的环1，长度大于等于三的环2
 **/
#include <iostream>

using namespace std;

int n, d[1000233], flag[1000233];
int ans1, ans2;

int main() {
    while(cin >> n) {
        ans1 = 0; ans2 = 0;
        for(int i = 1;i <= n;++ i) {
            cin >> d[i];
            if(d[i] == i) flag[i] = 1;
            if(d[i] != i) flag[i] = 0;
        }
        for(int i = 1;i <= n;++ i) {
            if(flag[i]) continue;
            int j = d[i], cnt = 0;
            while(j != i) {
                flag[j] = 1;
                j = d[j];
                ++ cnt;
            }
            ans1 += cnt;
            if(cnt > 1) ans2 = 2;
            if(cnt == 1 && ans2 != 2) ans2 = 1;
        }
        cout << ans1 << endl << ans2 << endl;
    }
}