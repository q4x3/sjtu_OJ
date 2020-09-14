/**
 * 模拟
 * 上坡下坡效果相同（因为有返程）
 **/
#include <iostream>
using namespace std;
 
int main() {
    int M, T, U, F, D;
    int cnt = 0, tot = 0;
    cin >> M >> T >> U >> F >> D;
    char tmp;
    for(int i = 0;i < T;++ i) {
        cin >> tmp;
        if(tmp == 'f') {
            tot += F * 2;
        } else {
            tot += (U + D);
        }
        if(tot > M) break;
        else ++ cnt;
    }
    cout << cnt <<endl;
    return 0;
}