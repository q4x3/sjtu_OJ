#include <iostream>

using namespace std;

int main()
{
    int a, n, ans = 1;
    cin >> a >> n;
    while(n > 0) {
        if (n & 1) ans = (a * ans) % 2019;
        a = (a * a) % 2019;
        n >>= 1;
    }
    cout << ans << endl;
}