#include <iostream>
using namespace std;
int main()
{
    string s;
    int ans = 0;
    getline(cin, s);
    for (int i = 0;i < s.length();++ i) {
        int tmp = s[i] - 'A' + 1;
        if (tmp > 26) tmp = tmp - 6;
        if (tmp < 0) tmp = 0;
        ans += tmp * (i + 1);
    }
    cout << ans << endl;
}