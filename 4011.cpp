/**
 * 一道简单的dp
 * 难就难在大整数。。。
 **/
#include <iostream>
#include <cstring>

using namespace std;

class bigint {
    public:
    char dt[100];
    
    bigint():dt("0") {}
    bigint &operator=(const bigint &obj) {
        strcpy(dt, obj.dt);
        return *this;
    }
    bigint &operator=(const int &obj) {
        dt[0] = obj + '0';
        dt[1] = 0;
        return *this;
    }
    friend ostream& operator<<(ostream &os, const bigint &obj);
    friend bigint operator+(const bigint &i1, const bigint &i2);
};

ostream& operator<<(ostream &os, const bigint &obj) {
    for(int i = strlen(obj.dt) - 1;i >= 0;-- i) cout << obj.dt[i];
}

bigint operator+(const bigint &i1, const bigint &i2) {
    int carry = 0;
    int len = max(strlen(i1.dt), strlen(i2.dt));
    bigint tmp;
    for(int i = 0;i < len;++ i) {
        int tmp1, tmp2;
        if(i >= strlen(i1.dt)) tmp1 = 0;
        else tmp1 = i1.dt[i] - '0';
        if(i >= strlen(i2.dt)) tmp2 = 0;
        else tmp2 = i2.dt[i] - '0';
        int sum = tmp1 + tmp2 + carry;
        tmp.dt[i] = sum % 10 + '0';
        carry = sum / 10;
    }
    if(carry) {
        tmp.dt[len] = '1';
        tmp.dt[len + 1] = 0;
    } else {
        tmp.dt[len] = 0;
    }
    return tmp;
}

bigint a[60][60];
int k, h;

int main() {
    scanf("%d%d", &k, &h);
    for(int j = 1;j <= k;++ j) a[1][j] = 1;
    for(int i = 2;i <= h;++ i) {
        for(int j = 1;j <= k;++ j) {
            a[i][j] = a[i][j - 1] + a[i - 1][k - j + 1];
        }
    }
    cout << a[h][k] << endl;
    return 0;
}