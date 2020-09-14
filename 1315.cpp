/**
 * 直接模拟
 * 有序分数序列
 **/
#include <iostream>

using namespace std;

int a[200][200];
double b[20000], c[200][200];

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
    int j, N, p = 0;
    double tmp;
    bool flag;
    cin >> N;
    for (int i = 1; i <= N; ++ i) {
        for (int j = 0; j <= i; ++ j) {
            a[i][j] = j;
            for (int k = 1; k <= j; ++ k) {
                if ((j % k == 0) && (i % k == 0))
                    ++p;
            }
            if (p != 1)
                a[i][j] = 0;
            p = 0;
            b[(i + 2) * (i - 1) / 2 + j] = double(a[i][j]) / i;
            c[i][j] = b[(i + 2) * (i - 1) / 2 + j];
        }
    }
    mergeSort(1, (N + 3) * N / 2 + 1, b);
    cout << "0/1" << endl;
    for (int k = 0; k < (N + 3) * N / 2; ++ k)
        for (int i = 1; i <= N; ++ i)
            for (int j = 0; j <= i; ++ j)
                if ((b[k] == c[i][j]) && (b[k] != 0))
                    cout << a[i][j] << '/' << i << endl;
    cout << "1/1" << endl;
    return 0;
}