#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int mon, b, c, y1, y2;
    int t[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cin >> mon >> b >> c >> y1 >> y2;
    int tmp = y1 - 1 - 1849;
    int one = 1 + tmp + tmp / 4;
    if (y1 - 1 >= 1901) -- one;
    one = one % 7;//y1 - 1年1.1的星期
    for (int i = y1;i <= y2;++ i) {
        bool flag = 0;
        if (i % 4 == 0 && i != 1900) t[1] = 29;
        one += 1;
        if ((i - 1) % 4 == 0 && i - 1 != 1900) ++ one;
        one %= 7;//i年1.1
        int monone = one;
        for (int j = 0;j < mon - 1;++ j) monone += t[j];
        monone %= 7;
        if (monone == 0) monone = 7;
        int b_c;
        if (c >= monone) {
            b_c = (b - 1) * 7 + 1 + c - monone;
        }
        if (c < monone) {
            int c1 = c + 7 - monone + 1;
            b_c = (b - 1) * 7 + c1;
        }
        if (b_c < 1 || b_c > t[mon - 1]) cout << "none" << endl;
        else {
            cout << i << '/';
            cout << setw(2) << setfill('0') << mon;
            cout << '/' << setw(2) << setfill('0') << b_c << endl;
        }
        t[1] = 28;
    }
}