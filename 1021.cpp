/**
 * 模拟
 **/
#include <iostream>
#include <iomanip>

using namespace std;

int n, a[151][151], tot = 1, x, y;
int main()
{
    cin >> n;
    a[0][0] = 1;
    while (tot < n * n) {
        while (y + 1 < n && !a[x][y + 1]) a[x][++ y] = ++ tot;
        while (x + 1 < n && !a[x + 1][y]) a[++ x][y] = ++ tot;
        while (y > 0 && !a[x][y - 1]) a[x][-- y] = ++ tot;
        while (x > 0 && !a[x - 1][y]) a[-- x][y] = ++ tot;
    }
    for (int i = 0;i < n;++ i) {
        for (int j = 0;j < n;++ j)
            cout << setw(6) << a[i][j];
        cout << endl;
    }
    return 0;
}