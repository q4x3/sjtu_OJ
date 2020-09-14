/**
 * 全wa了
 * 不写了
 * 题意理解错了属实拉跨
 **/
#include <iostream>
#include <stdio.h>
#define re register

using namespace std;

inline void read(int &x) {
	x = 0;
	char ch;
	bool f = 0; 
	while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-');
	if (ch == '-') f = 1;
	else x = ch - '0';
	while(ch = getchar(), ch >= '0' && ch <= '9') x = 10 * x + ch - '0';
	x = f ? -x : x;
}

int p[2000233], n, query, op, idq[2000233], numq[2000233], rear, pnum, head, qcur;
// int p[200], n, query, op, idq[200], numq[200], idnum, pnum, head, qcur;
inline int find(const int &x) {
    for(re int i = head;i < rear;++ i) {
        if(idq[i] == x) return i;
    }
    return -1;
}

int main() {
    read(n);
    for(re int i = 0;i < n;++ i) {
        read(p[i]);
    }
    read(query);
    for(int i = 0;i < query;++ i) {
        read(op);
        if(!op) {
            if(pnum == n) continue;
            else {
                int tmp = find(p[pnum]);
                ++ qcur;
                if(tmp == -1) {
                    ++ numq[rear];
                    idq[rear ++] = p[pnum ++];
                } else {
                    ++ pnum;
                    ++ numq[tmp];
                }
            }
        } else {
            if(qcur) {
                printf("%d\n", idq[head]);
                -- qcur;
                -- numq[head];
                if(!numq[head]) {
                    ++ head;
                }
            } else {
                printf("%d\n", -1);
            }
        }
    }
    return 0;
}