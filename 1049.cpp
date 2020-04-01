/**
 * 栈模拟
 **/
#include <iostream>

using namespace std;
int tmp, nex, flag = 1;

struct sstack
{
    int a[1233];
    int top;
};


int main() {
    int T;
    cin >> T;
    for(int i = 0;i < T;++ i) {
        int N, M;
        nex = 0; flag = 1;
        cin >> N >> M;
        sstack s;
        s.top = 0; s.a[0] = nex;
        for(int i = 0;i < N;++ i) {
            cin >> tmp;
            while(flag) {
                if(s.a[s.top] == tmp) {
                    -- s.top;
                    break;
                }
                ++ s.top;
                ++ nex;
                if(nex + 1 > N) flag = 0;
                s.a[s.top] = nex;
                if(s.top > M) flag = 0;
            }
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}