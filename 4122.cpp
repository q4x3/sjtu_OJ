/**
 * 字符串hash + 尺取法
 **/
#include <iostream>
#include <cstring>
#define ull unsigned long long

using namespace std;

int n, m, ans1, ans2, cur[100233];
char wor[1233][15], txt[100233][15];
bool wor_bool[100233];
ull wor_hash[100233], txt_hash[100233];
const ull base = 131;

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

ull myhash(char *s) {
    int len = strlen(s);
    ull tmp = 0;
    for(int i = 0;i < len;++ i) {
        tmp = tmp * base + (ull)s[i];
    }
    return tmp;
}

int binary_search(ull a) {
    int l = 1, r = n + 1;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(wor_hash[mid] >= a) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    if(wor_hash[l] == a) return l;
    else if(wor_hash[r] == a) return r;
    else return 0;
}

bool check() {
    for(int i = 1;i <= n;++ i) {
        if(wor_bool[i]) {
            if(cur[i] == 0) return 0;
        }
    }
    return 1;
}

int main() {
    scanf("%d", &n);
    for(int i = 1;i <= n;++ i) 
        scanf("%s", wor[i]);
    scanf("%d", &m);
    for(int i = 1;i <= m;++ i) 
        scanf("%s", txt[i]);
    for(int i = 1;i <= n;++ i)
        wor_hash[i] = myhash(wor[i]);
    for(int i = 1;i <= m;++ i)
        txt_hash[i] = myhash(txt[i]);
    mergeSort(1, n + 1, wor_hash);
    for(int i = 1;i <= m;++ i) {
        int tmp = binary_search(txt_hash[i]);
        if(tmp && (! wor_bool[tmp])) {
            wor_bool[tmp] = 1;
            ++ ans1;
        }
    }
    int p = 1, q = ans1;
    ans2 = m;
    for(int i = p;i <= q;++ i) {
        int tmp = binary_search(txt_hash[i]);
        if(tmp) ++ cur[tmp];
    }
    if(ans1 == 0) ans2 = 0;
    else {
        while(q <= m) {
            if(check()) {
                ans2 = (q - p + 1 < ans2) ? q - p + 1 : ans2;
                int tmp = binary_search(txt_hash[p]);
                if(tmp) -- cur[tmp];
                ++ p;
            }
            else {
                ++ q;
                int tmp = binary_search(txt_hash[q]);
                if(tmp) ++ cur[tmp];
            }
        }
    }
    cout << ans1 << endl << ans2 << endl;
}