#include <iostream>
#define POW(c) (1 << (c))
#define MASK(c) (((unsigned long) -1) / (POW(POW(c)) + 1))
#define ROUND(n, c) (((n) & MASK(c)) + ((n) >> POW(c) & MASK(c)))

using namespace std;

int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1;i <= n;++ i) {
        int num;
        cin >> num;
        num = ROUND (num, 0);
        num = ROUND(num, 1);
        num = ROUND(num, 2);
        num = ROUND(num, 3);
        num = ROUND(num, 4);
        ans += num; // O(loglognum)
        /*while (0 < num) {
            ++ ans;
            num &= num - 1;
        }*/ // O(ones)
        /*while (0 < num) {
            ans += (1 & num);
            num >>= 1;
        }*/ // O(lognum)
    }
    cout << ans << endl;
}