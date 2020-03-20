#include <iostream>

using namespace std;

int T, n, k;

int main() {
    cin >> T;
    for(int i = 0;i < T;++ i) {
        cin >> n >> k;
        if(n % (k + 1) == 0) cout << "Yeah!" << endl;
        else cout << "5555" << endl;
    }
}