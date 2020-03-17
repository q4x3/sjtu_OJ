#include <iostream>
#include <cstring>
using namespace std;

class bint {
    public:
    char data[600];
    int len;
    friend istream& operator>>(istream &in, const bint &obj);
    friend ostream& operator<<(ostream &os, const bint &obj);
    bint() {
        len = 0;
        for(int i = 0;i < 600;++ i)
            data[i] = 0;
    }
    bint(const bint &obj) {
        len = obj.len;
        for(int i = 0;i < 600;++ i) {
            data[i] = obj.data[i];
        }
    }
    void add_zeros(int n) {
        for(int i = len;i < len + n;++ i)
            data[i] = '0';
    }
    void del_zeros() {
        for(int i = len;i < 600;++ i)
            data[i] = 0;
    }
    void init() {
        for(int i = 0;i < 600;++ i) data[i] = 0;
    }
    bint operator=(const bint &obj) {
        len = obj.len;
        for(int i = 0;i < 600;++ i) {
            data[i] = obj.data[i];
        }
        return *this;
    }
    bint operator-(bint &obj) {
        int L1 = len, L2 = obj.len;
        obj.add_zeros(L1 - L2);
        bint tmp;
        tmp.init();
        for(int i = 0;i < len;++ i) tmp.data[i] = '0';
        for(int i = 0;i < len;++ i) {
            if(data[i] > obj.data[i]) tmp.data[i] += data[i] - obj.data[i];
            if(data[i] == obj.data[i]) {
                if(tmp.data[i] - '0' == -1) {
                    tmp.data[i] = '9';
                    --tmp.data[i + 1];
                }
                else tmp.data[i] = '0';
            }
            if(data[i] < obj.data[i]) {
                tmp.data[i] += data[i] - obj.data[i] + 10;
                tmp.data[i + 1] = -1 + '0';
            }
        }
        obj.del_zeros();
        int cnt = 0;
        for(int i = len - 1;i >= 0;-- i) {
            if(tmp.data[i] == 0) continue;
            if(tmp.data[i] == '0') {
                tmp.data[i] = 0;
                continue;
            }
            if(tmp.data[i] != '0') {
                cnt = i;
                break;
            }
        }
        tmp.len = cnt + 1;
        tmp.del_zeros();
        return tmp;
    }
    bool operator>(const bint &obj) {
        if(len > obj.len) return 1;
        if(len < obj.len) return 0;
        for(int i = len - 1;i >= 0;-- i) {
            if(data[i] > obj.data[i]) return 1;
            if(data[i] == obj.data[i]) continue;
            if(data[i] < obj.data[i]) break;
        }
        return 0;
    }
    bool operator==(const bint &obj) {
        return (strcmp(data, obj.data) == 0);
    }
    int div_2() {
        int carry = 0;
        for(int i = len - 1;i >= 0;-- i) {
            int tmp = data[i] - '0';
            data[i] = (tmp + carry * 10) / 2 + '0';
            carry = tmp % 2;
        }
        return carry;
    }
};

istream& operator>>(istream &in, bint &obj) {
    obj.init();
    char t[600];
    in >> t;
    obj.len = strlen(t);
    for(int i = 0;i < obj.len;++ i)
        obj.data[i] = t[obj.len - i - 1];
    return in;
}

ostream& operator<<(ostream &os, const bint &obj) {
    for(int i = obj.len - 1;i >= 0;-- i)
        os << obj.data[i];
}

int main() {
    bint t1, t2;
    cin >> t1 >> t2;
    int ans[2000] = {0};
    while(1) {
        if(t1 > t2) {
            t1 = t1 - t2;
            continue;
        } else if(t1 == t2) break;
        else {
            t2 = t2 - t1;
            continue;
        }
    }
    int cnt = 0;
    while(strcmp(t1.data, "0")) {
        ans[cnt] = t1.div_2();
        ++ cnt;
    }
    bool flag = 0;
    for(int i = 1999;i >= 0;-- i) {
        if(ans[i] != 0) flag = 1;
        if(flag) cout << ans[i];
    }
    cout << endl;
}