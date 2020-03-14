#include <iostream>

using namespace std;
long long n, a[100233], b[100233], inf, sup;

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

int main()
{
    cin >> n;
    for (int i = 0;i < n;++ i) cin >> a[i];
    for (int i = 0;i < n;++ i) cin >> b[i];
    mergeSort(0, n, a); mergeSort(0, n, b);
    for (int i = 0;i < n;++ i)
        sup += a[i] * b[i];
    for (int i = 0;i < n;++ i)
        inf += a[i] * b[n - i - 1];
    cout << sup << " " << inf << endl;
    return 0;
}