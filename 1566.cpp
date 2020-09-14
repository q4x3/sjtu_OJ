#include <cstdio>

const int MAXN = 30, MAXROAD = 500;
int n, roadnum, val, tot, map[MAXROAD][MAXROAD], edgenum, fa[MAXN], ans;
char tmp[4];

template <typename T>
void merge(int lo, int mi, int hi, T* a) {
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
void mergeSort(int lo, int hi, T* A) {
    if(hi - lo < 2) return;
    int mi = (lo + hi) / 2;
    mergeSort(lo, mi, A); mergeSort(mi, hi, A);
    merge(lo, mi, hi, A);
}

struct edge {
    int u, v;
    int w;
    bool operator<(const edge &rhs) {
        return w < rhs.w;
    }
} E[MAXROAD];

void link(int u, int v, int w) {
    map[u][v] = map[v][u] = ++ tot;
    E[tot].u = u, E[tot].v = v, E[tot].w = w;
}

int init() {
    for(int i = 1;i <= n;++ i)
        fa[i] = i;
}

int find(int x) {
    int son = x;
    if(fa[x] == x) return x;
    else return fa[x] = find(fa[x]);
}

int bind(int x, int y) {
    fa[find(x)] = find(y);
}

int main() {
    scanf("%d", &n);
    for(int i = 1;i < n;++ i) {
        scanf("%s", tmp);
        scanf("%d", &roadnum);
        for(int j = 1;j <= roadnum;++ j) {
            scanf("%s", tmp);
            scanf("%d", &val);
            link(i, tmp[0] - 'A' + 1, val);
        }
    }
    mergeSort(1, tot + 1, E);
    init();
    for(int i = 1;i <= tot;++ i) {
        if(edgenum == n - 1) break;
        if(find(E[i].u) != find(E[i].v)) {
            ++ edgenum;
            ans += E[i].w;
            bind(E[i].u, E[i].v);
        }
    }
    printf("%d\n", ans);
}