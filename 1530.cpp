/**
 * 完全二叉树
 * 前序/中序/后序和层序互相转化
 * 递归 + bfs
 **/
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
#define debug putchar('\n')

using namespace std;

const int MAXN = 1000233;
int t, num, cnt;
char code[MAXN];

int bpow(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1) ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}

void in_e(int self, int left, int right) {
    if(left >= num) {
        if(self < num)
            putchar(code[self]);
        //debug;
        return;
    }
    else {
        in_e(left, left << 1 | 1, (left << 1 | 1) + 1);
        putchar(code[self]);
        //debug;
        in_e(right, right << 1 | 1, (right << 1 | 1) + 1);
    }
}

void po_e(int self, int left, int right) {
    if(left >= num) {
        if(self < num)
            putchar(code[self]);
        //debug;
        return;
    }
    else {
        po_e(left, left << 1 | 1, (left << 1 | 1) + 1);
        po_e(right, right << 1 | 1, (right << 1 | 1) + 1);
        putchar(code[self]);
        //debug;
    }
}

void pr_e(int self, int left, int right) {
    if(left >= num) {
        if(self < num)
            putchar(code[self]);
        //debug;
        return;
    }
    else {
        putchar(code[self]);
        //debug;
        pr_e(left, left << 1 | 1, (left << 1 | 1) + 1);
        pr_e(right, right << 1 | 1, (right << 1 | 1) + 1);
    }
}

void in_d() {
    int ql[MAXN], qr[MAXN];
    int h, head = 0, rear = 0;
    ql[rear] = 0, qr[rear] = num - 1, ++ rear;
    while(head != rear) {
        int topl = ql[head], topr = qr[head];
        h = log2(double(topr - topl + 1)) + 1;
        ++ head;
        if(h == 1) {
            putchar(code[topl]);
            //debug;
            continue;
        } else {
            int tmp = bpow(2, h - 2);
            if(topr - topl + 2 - (tmp << 1) >= tmp) {
                ql[rear] = topl;
                qr[rear] = topl + (tmp << 1) - 2;
                ++ rear;
                putchar(code[topl + (tmp << 1) - 1]);
                //debug;
                ql[rear] = topl + (tmp << 1);
                qr[rear] = topr;
                if(ql[rear] <= qr[rear])
                    ++ rear;
            } else {
                ql[rear] = topl;
                qr[rear] = topr - tmp;
                ++ rear;
                putchar(code[topr - tmp + 1]);
                //debug;
                ql[rear] = topr - tmp + 2;
                qr[rear] = topr;
                ++ rear;
            }
        }
    }
}

void po_d() {
    int ql[MAXN], qr[MAXN];
    int h, head = 0, rear = 0;
    ql[rear] = 0, qr[rear] = num - 1, ++ rear;
    while(head != rear) {
        int topl = ql[head], topr = qr[head];
        putchar(code[topr]);
        //debug;
        h = log2(double(topr - topl + 1)) + 1;
        ++ head;
        if(h == 1) {
            continue;
        } else {
            int tmp = bpow(2, h - 2);
            if(topr - topl + 2 - (tmp << 1) >= tmp) {
                ql[rear] = topl;
                qr[rear] = topl + (tmp << 1) - 2;
                ++ rear;
                ql[rear] = topl + (tmp << 1) - 1;
                qr[rear] = topr - 1;
                if(ql[rear] <= qr[rear])
                    ++ rear;
            } else {
                ql[rear] = topl;
                qr[rear] = topr - tmp;
                ++ rear;
                ql[rear] = topr - tmp + 1;
                qr[rear] = topr - 1;
                ++ rear;
            }
        }
    }
}

void pr_d() {
    int ql[MAXN], qr[MAXN];
    int h, head = 0, rear = 0;
    ql[rear] = 0, qr[rear] = num - 1, ++ rear;
    while(head != rear) {
        int topl = ql[head], topr = qr[head];
        putchar(code[topl]);
        //debug;
        h = log2(double(topr - topl + 1)) + 1;
        ++ head;
        if(h == 1) {
            continue;
        } else {
            int tmp = bpow(2, h - 2);
            if(topr - topl + 2 - (tmp << 1) >= tmp) {
                ql[rear] = topl + 1;
                qr[rear] = topl + (tmp << 1) - 1;
                ++ rear;
                ql[rear] = topl + (tmp << 1);
                qr[rear] = topr;
                if(ql[rear] <= qr[rear])
                    ++ rear;
            } else {
                ql[rear] = topl + 1;
                qr[rear] = topr - tmp + 1;
                ++ rear;
                ql[rear] = topr - tmp + 2;
                qr[rear] = topr;
                ++ rear;
            }
        }
    }
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    char tmp1[15], tmp2[15];
    scanf("%d", &t);
    for(int i = 0;i < t;++ i) {
        scanf("%d", &num);
        scanf("%s", tmp1);
        scanf("%s", tmp2);
        scanf("%s", code);
        if(tmp2[0] == 'E') {
            if(tmp1[0] == 'I') {
                in_e(0, 1, 2);
                putchar('\n');
            }
            else if(tmp1[0] == 'P' && tmp1[1] == 'O') {
                po_e(0, 1, 2);
                putchar('\n');
            }
            else {
                pr_e(0, 1, 2);
                putchar('\n');
            }
        } else {
            if(tmp1[0] == 'I') {
                in_d();
                putchar('\n');
            }
            else if(tmp1[0] == 'P' && tmp1[1] == 'O') {
                po_d();
                putchar('\n');
            }
            else {
                pr_d();
                putchar('\n');
            }
        }
    }
    return 0;
}