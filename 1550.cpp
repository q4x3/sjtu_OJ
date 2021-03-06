/**
 * 模拟
 * 记录最左边的高度，向右扫描
 * 扫到更高的更新水量和最高高度
 * 右往左也要扫一遍
 * 扫到之前最高点停止
 * 注意同高度处理
 **/
#include <iostream>
 
using namespace std;
 
int n, a[1233], ans, cur, curind;
char tmp;
int main() {
    cin >> n;
    for(int i = 0;i < n;++ i) {
        cin >> tmp;
        cin >> a[i];
    }
    cin >> tmp;
    cur = a[0];
    for(int i = 1;i < n;++ i) {
        if(a[i] >= cur) {
            ans += cur * (i - curind - 1);
            for(int j = curind + 1;j < i;++ j) {
                ans -= a[j];
            }
            cur = a[i];
            curind = i;
        }
    }
    int maxi = curind;
    cur = a[n - 1]; curind = n - 1;
    for(int i = n - 2;i >= maxi;-- i) {
        if(a[i] >= cur) {
            ans += cur * (curind - i - 1);
            for(int j = curind - 1;j > i;-- j) {
                ans -= a[j];
            }
            cur = a[i];
            curind = i;
        }
    }
    cout << ans << endl;
}