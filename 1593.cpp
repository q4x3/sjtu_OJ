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
 
class mouse {
    public:
    int ind, p, s;
    mouse():ind(0), p(0), s(0) {}
    mouse(int _ind, int _p, int _s):ind(_ind), p(_p), s(_s) {}
    mouse(const mouse &obj):ind(obj.ind), p(obj.p), s(obj.s) {}
    bool operator<(const mouse &obj) {
        if(p < obj.p) return 1;
        if(p > obj.p) return 0;
        if(p == obj.p) return (ind > obj.ind);
        return 0;
    }
};
 
int N, R;
mouse m[200233];
 
int main() {
    cin >> N >> R;
    for(int i = 0;i < 2 * N;++ i) {
        cin >> m[i].p;
        m[i].ind = i;
    }
    for(int i = 0;i < 2 * N;++ i)
        cin >> m[i].s;
    mergeSort(0, 2 * N, m);
    for(int i = 0;i < R;++ i) {
        for(int i = 0;i < 3;++ i)
            for(int i = 0;i < 2 * N - 1;++ i) {
                if(m[i] < m[i + 1]) continue;
                mouse tmp = m[i + 1];
                m[i + 1] = m[i];
                m[i] = tmp;
            }
        for(int i = 0;i < 2 * N - 1;i += 2) {
            if(m[i].s < m[i + 1].s) {
                m[i + 1].p += 2;
                continue;
            }
            if(m[i].s > m[i + 1].s) {
                m[i].p += 2;
                continue;
            }
            if(m[i].s == m[i + 1].s) {
                m[i].p += 1;
                m[i + 1].p += 1;
                continue;
            }
        }
    }
    mergeSort(0, 2 * N, m);
    for(int i = 2 * N - 1;i >= 0;-- i)
        cout << m[i].ind + 1 << " ";
    cout << endl;
}