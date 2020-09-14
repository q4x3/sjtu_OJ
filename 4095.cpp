/**
 * 究极约瑟夫环
 * 线段树
 * 最难的不是树而是各种边界判断
 **/
#include <iostream>

using namespace std;

const int MAXN = 1e5 + 233;
// num表示编号，叶子为编号，非叶子为0， tree表示该段剩余人数
int num[MAXN << 2], tree[MAXN << 2];
int N, M, tmp1, tmp2;

void build(int rt, int l, int r) {
    if(l == r) {
        tree[rt] = 1;
        num[rt] = l;
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}

void del(int rt, int l, int r, int x) {
    if(l == r) {
        tree[rt] = 0;
        num[rt] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    if(tree[rt << 1] >= x) {
        del(rt << 1, l, mid, x);
    } else {
        del(rt << 1 | 1, mid + 1, r, x - tree[rt << 1]);
    }
    tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}

int query(int rt, int l, int r) {
    if(l == r) return num[rt];
    int mid = (l + r) >> 1;
    int tmp1 = query(rt << 1, l, mid), tmp2 = query(rt << 1 | 1, mid + 1, r);
    return tmp1 > tmp2 ? tmp1 : tmp2;
}

int main() {
    scanf("%d%d", &N, &M);
    if(M == 1) printf("%d\n", N);
    else if(N == 1) printf("1\n");
    else {
        build(1, 1, N);
        bool dir = 1; // 1 right, 0 left
        tmp1 = 1;
        for(int i = N;i > 1;-- i) {
            if(dir) {
                if(M < i + 1 - tmp1) {
                    tmp1 += (M - 1);
                    del(1, 1, N, tmp1);
                } else {
                    tmp1 = M - i + tmp1;
                    tmp2 = tmp1 / (i - 1);
                    tmp1 %= (i - 1);
                    if(tmp1 == 0) {
                        -- tmp2;
                        tmp1 = i - 1;
                    }
                    if(tmp2 % 2 == 0) {
                        tmp1 = i + 1 - tmp1;
                        dir = 0;
                        del(1, 1, N, tmp1);
                    } else {
                        dir = 1;
                        del(1, 1, N, tmp1);
                    }
                }
            } else {
                if(M < tmp1 - 1) {
                    tmp1 -= M;
                    del(1, 1, N, tmp1);
                } else {
                    tmp1 = M - tmp1 + 2;
                    tmp2 = tmp1 / (i - 1);
                    tmp1 %= (i - 1);
                    if(tmp1 == 0) {
                        -- tmp2;
                        tmp1 = i - 1;
                    }
                    if(tmp2 % 2 == 0) {
                        dir = 1;
                        del(1, 1, N, tmp1);
                    } else {
                        tmp1 = i + 1 - tmp1;
                        dir = 0;
                        del(1, 1, N, tmp1);
                    }
                }
            }
        }
        printf("%d\n", query(1, 1, N));
    }
    return 0;
}