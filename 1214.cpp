/**
 * 树的前序后序遍历
 **/
#include <iostream>
#include <stdio.h>

using namespace std;

const int MAXN = 1e5 + 233;
int l[MAXN], r[MAXN], val[MAXN], vis[MAXN], q[MAXN << 1]; 
int N, rt;

void pre(int rt) {
    printf("%d ", val[rt]);
    int son = l[rt];
    if(!son) return;
    while(1) {
        pre(son);
        son = r[son];
        if(son == 0) break;
    }
    return;
}

void pos(int rt) {
    int son = l[rt];
    if(!son) {
        printf("%d ", val[rt]);
        return;
    }
    while(1) {
        pos(son);
        son = r[son];
        if(son == 0) break;
    }
    printf("%d ", val[rt]);
    return;
}

void seq() {
    int head = 0, rear = 0;
    q[rear ++] = rt;
    while(head != rear) {
        int top = q[head];
        printf("%d ", val[top]);
        ++ head;
        int son = l[top];
        while(1) {
            if(!son) break;
            q[rear ++] = son;
            son = r[son];
        }
    }
}

int main() {
    scanf("%d", &N);
    for(int i = 1;i <= N;++ i) {
        scanf("%d%d%d", &l[i], &r[i], &val[i]);
        vis[l[i]] = 1;
        vis[r[i]] = 1;
    }
    for(int i = 1;i <= N;++ i) {
        if(!vis[i]) {
            rt = i;
            break;
        }
    }
    pre(rt); putchar('\n');
    pos(rt); putchar('\n');
    seq(); putchar('\n');
}