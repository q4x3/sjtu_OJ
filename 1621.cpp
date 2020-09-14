/**
 * 用一个矩阵存储每个格子左侧最长的连续白子序列(包括自己)
 * 对矩阵的每一列排序后，遍历，更新答案
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

int n, b[1010][1010], c[1010], ans;
char a[1010][1010];

int main() {
    cin >> n;
    for(int i = 0;i < n;++ i)
        cin >> a[i];
    for(int i = 0;i < n;++ i)
        for(int j = 0;j < n;++ j) {
            int tmp = j;
            while(a[i][tmp] == '1') {
                -- tmp;
                ++ b[i][j];
            }
        }
    for(int i = 0;i < n;++ i) {
        for(int j = 0;j < n;++ j)
            c[j] = b[j][i];
        mergeSort(0, n, c);
        for(int j = 0;j < n;++ j) {
            if(c[j] * (n - j) > ans) ans = c[j] * (n - j);
        }
    }
    cout << ans << endl;
}