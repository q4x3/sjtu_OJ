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

class node {
    public:
    int t1, t2;
    node():t1(0), t2(0) {}
    node(const node &obj):t1(obj.t1), t2(obj.t2) {}
    bool operator<(const node &obj) {
        return t2 < obj.t2;
    }
    bool operator>(const node &obj) {
        return t2 > obj.t2;
    }
    bool operator==(const node &obj) {
        return t2 == obj.t2;
    }
    friend istream& operator>>(istream &in, node &obj);
};

istream& operator>>(istream &in, node &obj) {
    in >> obj.t1 >> obj.t2;
    return in;
}

int n, ans = 1;
node a[100233];

int main() {
    cin >> n;
    for(int i = 0;i < n;++ i)
        cin >> a[i];
    mergeSort(0, n, a);
    int curt2 = a[0].t2;
    for(int i = 0;i < n - 1;++ i) {
        if(a[i + 1].t1 >= curt2) {
            ++ ans;
            curt2 = a[i + 1].t2;
        }
    }
    cout << ans << endl;
    return 0;
}