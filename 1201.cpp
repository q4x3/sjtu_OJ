#include <iostream>
 
using namespace std;
 
int T;
long long N, init;
int main() {
    cin >> T;
    for(int i = 0;i < T;++ i) {
        int ans[20] = {0};
        cin >> N;
        init = (N / 100) * 100;
        for(long long i = init;i <= N;++ i) {
            int j = 0;
            long long cur = i;
            while(cur) {
                ans[j] += (cur % 10);
                cur /= 10;
                ans[j] %= 10;
                ++ j;
            }
        }
        int del_0 = 19;
        while(del_0) {
            if(ans[del_0] != 0) break;
            -- del_0;
        }
        for(int i = del_0;i >= 0;-- i)
            cout << ans[i];
        cout << endl;
    }
}