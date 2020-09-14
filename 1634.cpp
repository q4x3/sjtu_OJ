/**
 * 堆排+归并+快排计数
 * 快排计数方法很神奇
 **/
#include <iostream>

using namespace std;

long long int ans;
int dt[100233], pre[100233], nxt[100233];
int N, k;

void merge(int lo, int mi, int hi, int* a) {
    int* A = a + lo;
    int lb = mi - lo;
    int* B = new int[lb];
    int* BB = B;
    for(int i = 0;i < lb;++ i)
        B[i] = A[i];
    int lc = hi - mi;
    int* C = a + mi;
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
            ++ ans;
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

void mergeSort(int lo, int hi, int* a) {
    if(hi - lo < 2) return;
    int mi = (lo + hi) >> 1;
    mergeSort(lo, mi, a);
    mergeSort(mi, hi, a);
    merge(lo, mi, hi, a);
}

void up(int node) {
    if(node == 1) return;
    ++ ans;
    if(dt[node] < dt[node >> 1]) {
        swap(dt[node], dt[node >> 1]);
        up(node >> 1);
    }
}

void down(int node, int size) {
    if(node == size || (node << 1) > size) return;
    if((node << 1 | 1) > size) {
        ++ ans;
        if(dt[node << 1] < dt[node]) swap(dt[node << 1], dt[node]);
    } else {
        ans += 2;
        if(dt[node << 1] <= dt[node << 1 | 1]) {
            if(dt[node] > dt[node << 1]) {
                swap(dt[node], dt[node << 1]);
                down(node << 1, size);
            }
        } else {
            if(dt[node] > dt[node << 1 | 1]) {
                swap(dt[node], dt[node << 1 | 1]);
                down(node << 1 | 1, size);
            }
        }
    }
}

void build() {
    for(int i = 1;i <= N;++ i)
        up(i);
}

void quick() {
    for (int i = 1; i <= N; i++)
    {
        pre[i] = i - 1;
        nxt[i] = i + 1;
    }
    nxt[0] = 1;
    pre[N + 1] = N;
    for (int i = N; i >= 1; i--)
    {
        int k = dt[i];
        ans += (long long int)(nxt[k] - pre[k] - 2);
        nxt[pre[k]] = nxt[k];
        pre[nxt[k]] = pre[k];
    }
}

int main() {
    scanf("%d%d", &N, &k);
    for(int i = 1;i <= N;++ i)
        scanf("%d", &dt[i]);
    if(k == 1) {
        build();
        for(int i = N;i > 1;-- i) {
            swap(dt[i], dt[1]);
            down(1, i - 1);
        }
        printf("%lld\n", ans);
    }
    if(k == 2) {
        mergeSort(1, N + 1, dt);
        printf("%lld\n", ans);
    }
    if(k == 3) {
        quick();
        printf("%lld\n", ans);
    }
}