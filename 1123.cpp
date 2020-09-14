/**
 * 线段树优化dp
 * dp[i][j][0or1]表示以点i结尾的j段划分方案数(0表示最后一段上升，1表示最后一段下降)
 * 线段树按y值划分，注意应先将y值按大小映射到1-n上，方便建树
 * 这题可太nm难了
 * 虽然说可以用树状数组优化
 * 但我不会树状数组啊喂
 * 中间注释掉的部分是暴力dp
 **/
#include <iostream>

using namespace std;

struct node {
    int x, y;
};

void mergex(int lo, int mi, int hi, node* a)
{
    node* A = a + lo;
    int lb = mi - lo;
    node* B = new node[lb];
    node* BB = B;
    for(int i = 0;i < lb;++ i)
        B[i] = A[i];
    int lc = hi - mi;
    node* C = a + mi;
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
            if(B[0].x < C[0].x) {
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

void mergey(int lo, int mi, int hi, node* a)
{
    node* A = a + lo;
    int lb = mi - lo;
    node* B = new node[lb];
    node* BB = B;
    for(int i = 0;i < lb;++ i)
        B[i] = A[i];
    int lc = hi - mi;
    node* C = a + mi;
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
            if(B[0].y < C[0].y) {
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

void mergeSort(int lo, int hi, node* A, int sign)
{
    if(sign == 1) {
        if(hi - lo < 2) return;
        int mi = (lo + hi) / 2;
        mergeSort(lo, mi, A, sign); mergeSort(mi, hi, A, sign);
        mergex(lo, mi, hi, A);
    } else {
        if(hi - lo < 2) return;
        int mi = (lo + hi) / 2;
        mergeSort(lo, mi, A, sign); mergeSort(mi, hi, A, sign);
        mergey(lo, mi, hi, A);
    }
}

const int MAXN = 5e4 + 233, mo = 1e5 + 7;
node dt[MAXN];
int dp[MAXN][11][2], up[11][MAXN << 2], down[11][MAXN << 2];

int n, k;

void modify(int rt, int l, int r, int dir, int k, int pos, int v) {
    if(l == r) {
        if(dir == 0) up[k][rt] = v;
        else down[k][rt] = v;
        return;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid) modify(rt << 1, l, mid, dir, k, pos, v);
    else modify(rt << 1 | 1, mid + 1, r, dir, k, pos, v);
    if(dir == 0) up[k][rt] = (up[k][rt << 1] + up[k][rt << 1 | 1]) % mo;
    else down[k][rt] = (down[k][rt << 1] + down[k][rt << 1 | 1]) % mo;
}

int query(int rt, int l, int r, int s, int t, int dir, int k) {
    if(s > t) return 0;
    if(s <= l && r <= t) {
        if(dir == 0) return up[k][rt];
        else return down[k][rt];
    }
    int mid = (l + r) >> 1;
    if(t <= mid) return query(rt << 1, l, mid, s, t, dir, k) % mo;
    else if(s > mid) return query(rt << 1 | 1, mid + 1, r, s, t, dir, k) % mo;
    else return (query(rt << 1, l, mid, s, t, dir, k) + query(rt << 1 | 1, mid + 1, r, s, t, dir, k)) % mo;
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1;i <= n;++ i) {
        scanf("%d%d", &(dt[i].x), &(dt[i].y));
    }
    mergeSort(1, n + 1, dt, 2);
    for(int i = 1;i <= n;++ i) 
        dt[i].y = i;
    mergeSort(1, n + 1, dt, 1);
    for(int i = 1;i <= n;++ i) {
        modify(1, 1, n, 0, 0, dt[i].y, 1);
        modify(1, 1, n, 1, 0, dt[i].y, 1);
        for(int j = 1;j <= k;++ j) {
            /*for(int m = 1;m < i;++ m) {
                if(dt[m].y < dt[i].y) {
                    dp[i][j][0] += dp[m][j][0];
                    dp[i][j][0] %= mo;
                    dp[i][j][0] += dp[m][j - 1][1];
                    dp[i][j][0] %= mo;
                } else {
                    dp[i][j][1] += dp[m][j][1];
                    dp[i][j][1] %= mo;
                    dp[i][j][1] += dp[m][j - 1][0];
                    dp[i][j][1] %= mo;
                }
            }*/
            dp[i][j][0] = (query(1, 1, n, dt[i].y + 1, n, 0, j) + query(1, 1, n, dt[i].y + 1, n, 1, j - 1)) % mo;
            dp[i][j][1] = (query(1, 1, n, 1, dt[i].y - 1, 1, j) + query(1, 1, n, 1, dt[i].y - 1, 0, j - 1)) % mo;
            modify(1, 1, n, 0, j, dt[i].y, dp[i][j][0]);
            modify(1, 1, n, 1, j, dt[i].y, dp[i][j][1]);
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;++ i) {
        ans += dp[i][k][0];
        ans %= mo;
        ans += dp[i][k][1];
        ans %= mo;
    }
    printf("%d\n", ans);
}