/**
 * 状态压缩dp
 * 预处理很多
 * 看起来没有互相包含的情况？？？
 **/
#include <iostream>
#include <cstring>
#include <cmath>
 
using namespace std;
 
int match[15][15], con[15][15], n; // con[i][j]表示i是否包含j, match[i][j]表示i左j右重叠最大长度
char dt[15][60], dp[8200][15][700];
 
void cal_match() {
    for(int i = 0;i <= n;++ i) {
        for(int j = 0;j <= n;++ j) {
            int len1 = strlen(dt[i]), len2 = strlen(dt[j]);
            int len = len1 < len2 ? len1 : len2;
            for(int k = len;k > 0;-- k) {
                bool flag = 1;
                for(int m = 0;m < k;++ m) {
                    if(dt[j][m] != dt[i][m + len1 - k]) {
                        flag = 0;
                        break;
                    }
                }
                if(flag) {
                    match[i][j] = k;
                    break;
                }
            }
        }
    }
}
 
bool is_contain(int i, int j) {
    int len1 = strlen(dt[i]), len2 = strlen(dt[j]);
    if(len1 < len2) return 0;
    bool flag = 1;
    for(int m = 1;m <= len1 - len2;++ m) {
        for(int n = 1;n < len2;++ n) {
            if(dt[j][n] != dt[i][m + n]) {
                flag = 0;
                break;
            }
        }
        if(flag) return 1;
    }
    return 0;
}
 
void cal_contain() {
    for(int i = 1;i <= n;++ i) {
        for(int j = 1;j <= n;++ j) {
            if(is_contain(i, j)) con[i][j] = 1;
            else con[i][j] = 0;
        }
    }
}
 
//a比b大则真
bool cmp(char* a, char* b) {
    if(strlen(a) != strlen(b)) return strlen(a) > strlen(b);
    else if(strcmp(a, b) > 0) return 1;
    else return 0;
}
 
void cal_dp() {
    int maxx = pow(2, n) - 1;
    for(int i = 1;i <= n;++ i) {
        int tmp = pow(2, i - 1);
        strcpy(dp[tmp][i], dt[i]);
    }
    for(int i = 1;i <= maxx;++ i) {
        for(int j = 1;j <= n;++ j) {
            int tmp = i, cnt = 1;
            int tmpp = pow(2, j - 1);
            if(! (i & tmpp)) continue;
            /*while(cnt <= n) {
                if(tmp & 1) {
                    for(int k = 1;k <= n;++ k) {
                        int p = pow(2, k - 1);
                        if(con[cnt][k] && ! (i & p)) {
                            strcpy(dp[i + p][j], dp[i][j]);
                        }
                    }
                    tmp >>= 1;
                }
                ++ cnt;
            }*/
            cnt = 1;
            tmp = i;
            while(cnt <= n) {
                if(tmp & 1) {
                    tmp >>= 1;
                } else {
                    char tmpstr[700];
                    strcpy(tmpstr, dp[i][j]);
                    strcat(tmpstr, dt[cnt] + match[j][cnt]);
                    int ii = i + pow(2, cnt - 1);
                    if(strlen(dp[ii][cnt]) != 0) {
                        int flag = cmp(dp[ii][cnt], tmpstr);
                        if(flag) strcpy(dp[ii][cnt], tmpstr);
                    } else {
                        strcpy(dp[ii][cnt], tmpstr);
                    }
                    tmp >>= 1;
                }
                ++ cnt;
            }
        }
    }
}
 
void solve() {
    int tmp = pow(2, n) - 1;
    char ans[700];
    strcpy(ans, dp[tmp][1]);
    for(int i = 2;i <= n;++ i) {
        if(cmp(ans, dp[tmp][i])) strcpy(ans, dp[tmp][i]);
    }
    cout << ans << endl;
}
 
int main() {
    scanf("%d", &n);
    for(int i = 1;i <= n;++ i) {
        cin >> dt[i];
    }
    cal_match();
    //cal_contain();
    cal_dp();
    solve();
    return 0;
}