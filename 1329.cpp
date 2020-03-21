#include <iostream>
#include <cstring>
using namespace std;

long long lik[70], dis[70];

bool interSec(long long a, long long b) {
    bool flag = 0;
    while(a != 0 && b != 0) {
        if((a & 1 & b) == 1) {
            flag = 1;
            break;
        } else {
            a >>= 1;
            b >>= 1;
        }
    }
    return flag;
}

int main() {
    int t, n, m;
    char tmp;
    cin >> t;
    for(int i = 0;i < t;++ i) {
        /**
         * input
         * */
        memset(lik, 0, 70 * sizeof(long long));
        memset(dis, 0, 70 * sizeof(long long));
        cin >> n >> m;
        tmp = getchar();
        for(int j = 0;j < m;++ j) {
            tmp = 0;
            while(tmp != '\n') {
                tmp = getchar();
                if(tmp == ' ') continue;
                if(tmp == '-') {
                    tmp = getchar();
                    dis[j] += (1 << (tmp - '0' - 1));
                    continue;
                }
                if(tmp - '0' > 0) lik[j] += (1 << (tmp - '0' - 1)); 
            }
        }
        /**
         * judge
         * */
        bool flag = 1, f1, f2;
        long long s = (1 << n) - 1;
        for(int k = 0;k <= s;++ k) {
            flag = 1;
            for(int kk = 0;kk < m;++ kk) {
                f1 = interSec(lik[kk], k);
                f2 = interSec(dis[kk], s - k);
                if(f1 == 0 && f2 == 0) {
                    flag = 0;
                    break;
                }
            }
            if(flag) break;
            else continue;
        }
        if(flag) cout << "Bingo!" << endl;
        else cout << "Sigh..." << endl;
    }
}