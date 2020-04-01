/**
 * 二分
 * 找到不大于tmp的最大a，a[lo - 1] (a[lo]为比tmp大的最小a)
 * 故lo个a可以
 **/
#include <iostream>

using namespace std;

int N, K, lo, hi, mi;
double a[100233];

int main() {
    cin >> N;
    for(int i = 0;i < N;++ i) {
        scanf("%lf", &a[i]);
    }
    cin >> K;
    for(int i = 0;i < K;++ i) {
        double b, c;
        scanf("%lf%lf", &b, &c);
        double tmp = b * b / (4 * c);
        lo = 0; hi = N;
        while(lo < hi) {
            mi = (lo + hi) >> 1;
            if (tmp < a[mi]) {
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        printf("%d\n", lo);
    }
    return 0;
}