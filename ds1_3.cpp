#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e5 + 233;

int N, M;
char dt[MAXN];
int tree[MAXN << 2], lz[MAXN << 2], lo[MAXN << 2], rz[MAXN << 2], ro[MAXN << 2];
int L0[MAXN << 2], L1[MAXN << 2], R0[MAXN << 2], R1[MAXN << 2];

/*void build(int rt, int l, int r) {
    if(l == r) {
        tree[rt] = 0;
        if(dt[l - 1] == '0') {
            lz[rt] = 1;
        } else if(dt[l - 1] == '1') {
            lo[rt] = 1;
        }
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    lo[rt] = lo[rt << 1] + ro[rt << 1];
    ro[rt] = lo[rt << 1 | 1] + ro[rt << 1 | 1];
    lz[rt] = lz[rt << 1] + rz[rt << 1];
    rz[rt] = lz[rt << 1 | 1] + rz[rt << 1 | 1];
    tree[rt] = tree[rt << 1] + tree[rt << 1 | 1] + (lo[rt << 1] + ro[rt << 1]) * (lz[rt << 1 | 1] + rz[rt << 1 | 1]);
}

void update(int rt, int l, int r, int l0, int l1, int r0, int r1) {
    lo[rt] += l1;
    lz[rt] += l0;
    ro[rt] += r1;
    rz[rt] += r0;
    L0[rt] += l0;
    L1[rt] += l1;
    R0[rt] += r0;
    R1[rt] += r1;
}

void pushdown(int rt, int l, int r) {
    int mid = (l + r) >> 1;
    update(rt << 1, l, mid, L0[rt], L1[rt], R0[rt], R1[rt]);
    update(rt << 1 | 1, mid + 1, r, L0[rt], L1[rt], R0[rt], R1[rt]);
}

void modify(int rt, int l, int r, int s, int t, int l0, int l1, int r0, int r1) {
    if(s <= l && r <= t) {
        return;
    }
    int mid = (l + r) >> 1;
    if(s <= mid) modify(rt << 1, l, mid, )

}

int query(int rt, int l, int r, int s, int t) {}*/

int cal() {
    int cnt = 0;
    for(int i = 0;i < N;++ i) {
        if(dt[i] == '1') {
            for(int j = i + 1;j < N;++ j) {
                if(dt[j] == '0') ++ cnt;
            }
        }
    }
    return cnt;
}

int main() {
    int tmp1, tmp2;
    scanf("%d%d", &N, &M);
    scanf("%s", dt);
    if(N > 10000) return 0;
    for(int i = 0;i < M;++ i) {
        scanf("%d%d", &tmp1, &tmp2);
        char tmp = dt[tmp1];
        dt[tmp1] = dt[tmp2];
        dt[tmp2] = tmp;
        printf("%d\n", cal());
    }
}