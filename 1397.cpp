/**
 * 数学题
 * 排个序就清楚了
 * long long
 **/
#include <iostream>

using namespace std;

template <typename T>
void merge(int lo, int mi, int hi, T* a)
{
    T* A = a + lo;
    int lb = mi - lo;
    T* B = new T[lb];
    T* BB = B;
    for(int i = 0;i < lb;++ i)
        B[i] = A[i];
    int lc = hi - mi;
    T* C = a + mi;
    int cnt = 0;
    while(1) {
        if ((lb == 0) && (lc == 0)) break;
        if (lb == 0) {
            A[cnt] = C[0];
            ++ cnt; ++ C; -- lc;
        }
        else if (lc == 0) {
            A[cnt] = B[0];
            ++ cnt; ++ B; --lb;
        }
        else {
            if(B[0] < C[0]) {
                A[cnt] = B[0];
                ++ cnt; ++ B; -- lb;
            }
            else {
                A[cnt] = C[0];
                ++ cnt; ++ C; -- lc;
            }
        }
    }
    delete []BB;
}

template <typename T>
void mergeSort(int lo, int hi, T* A)
{
    if(hi - lo < 2) return;
    int mi = (lo + hi) / 2;
    mergeSort(lo, mi, A); mergeSort(mi, hi, A);
    merge(lo, mi, hi, A);
}

long long n, _n, a[100233], ans, cnt;

int main() {
    cin >> n;
    _n = n;
    for(int i = 0;i < n;++ i)
        cin >> a[i];
    mergeSort(0, n, a);
    -- _n;
    while(_n > 0) {
        ans += ((_n % 1000000007) * (a[n - 1 - cnt] - a[cnt]) % 1000000007);
        ans %= 1000000007;
        _n -= 2;
        ++ cnt;
    }
    cout << ans << endl;
}