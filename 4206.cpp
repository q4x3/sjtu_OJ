/**
 * 模拟 + 二维前缀和
 * 先暴力试试看
 **/
#include <iostream>
#include <stdio.h>

using namespace std;

int n, m, a[2233][2233], tmp, sum[2233][2233];
char c[1233][1233];

int main() {
    
    scanf("%d %d", &n, &m);
    getchar();
    for(int i = 1;i <= n;++ i) {
        cin >> c[i];
        for(int j = 0;j < m;++ j) {
            a[i][j + 1] = c[i][j] - '0';
        }
    }
    tmp = (m > n) ? m : n;
    for(int i = 1;i <= 2 * tmp;++ i) {
        for(int j = 1;j <= 2 * tmp;++ j) {
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + a[i][j];
        }
    }
    int tmpm, tmpn, ans = 1000000, tmpchn, tmpans, flag;
    for(int i = 2;i <= tmp;++ i) {
        if(m % i != 0) tmpm = (m / i + 1) * i;
        else tmpm = m;
        if(n % i != 0) tmpn = (n / i + 1) * i;
        else tmpn = n;
        tmpans = 0;
        flag = 1;
        for(int j = i;j <= tmpn;j += i) {
            for(int k = i;k <= tmpm;k += i) {
                tmpchn = sum[j][k] + sum[j - i][k - i] - sum[j - i][k] - sum[j][k - i];
                tmpans += ((tmpchn < i * i - tmpchn) ? tmpchn : (i * i - tmpchn));
                if(tmpans > ans) {
                    flag = 0;
                    break;
                }
            }
            if(flag == 0) break;
        }
        if(tmpans < ans) ans = tmpans;
    }
    cout << ans << endl;
}