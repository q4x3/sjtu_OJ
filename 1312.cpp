/**
 * 数学题
 * 赌王划什么，Juda划对称的
 **/
#include <iostream>

using namespace std;

int T, n, k;

int main() {
    cin >> T;
    for(int i = 0;i < T;++ i) {
        cin >> n >> k;
        if(k == 1) {
            if(n % 2 == 0) cout << "Yeah!" << endl;
            else cout << "5555" << endl;
        } else {
            if(n <= k) cout << "5555" << endl;
            else cout << "Yeah!" << endl;
        }
    }
}