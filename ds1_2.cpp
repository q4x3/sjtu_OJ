#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int k, tmp = 0;
    cin >> k;
    if(k % 2 == 0) {
        cout << k / 2 + 1 << endl;
        for(int i = 0;i <= k / 2;++ i) {
            cout << tmp << endl;
            tmp += (pow(2, 2 * i) + pow(2, 2 * i + 1));
        }
    } else {
        cout << k / 2 + k << endl;
        for(int i = 0;i < k / 2;++ i) {
            cout << tmp << endl;
            tmp += (pow(2, 2 * i) + pow(2, 2 * i + 1));
        }
        tmp = pow(2, k) - 1;
        for(int i = 0;i < k;++ i) {
            cout << tmp - pow(2, i) << endl;
        }
    }
    return 0;
}