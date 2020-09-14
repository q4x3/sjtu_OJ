/**
 * 模拟
 * 排序后判断水淹到了哪里(扫描)
 * 注意处理全淹了的情况
 **/
#include <iostream>
#include <iomanip>

using namespace std;
double h[250233], H, per, earth, V;
int m, n;

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
    cin >> m >> n;
    for(int i = 0;i < m * n;++ i) cin >> h[i];
    cin >> V;
    mergeSort(0, m * n, h);
    per = m * n;
    for(int i = 0;i < m * n;++ i) {
        earth += h[i];
        H = h[i + 1] * (i + 1) - earth;
        if(H >= V) {per = i + 1; break;}
    }
    H = (V + earth) / per;
    per = 100 * per / (m * n);
    cout << fixed << setprecision(2) << H << endl << per << endl;
    return 0;
}