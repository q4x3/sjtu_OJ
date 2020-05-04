/**
 * 儿子兄弟表示法下的前后层序遍历
 **/
#include <iostream>
#include <stdio.h>
using namespace std;

int N, ls[13000], rb[13000];
bool vis[13000];

void pre(int rt) {
    printf("%d ", rt);
    int son = ls[rt];
    while(son) {
        pre(son);
        son = rb[son];
    }
}

void pos(int rt) {
    int son = ls[rt];
    while(son) {
        pos(son);
        son = rb[son];
    }
    printf("%d ", rt);
}

void hie(int rt) {
    int q[13000];
    int head = 0, rear = 0;
    q[rear] = rt; ++ rear;
    while(head < rear) {
        int tmp = q[head];
        ++ head;
        printf("%d ", tmp);
        tmp = ls[tmp];
        while(1) {
            if(tmp) {
                q[rear] = tmp;
                ++ rear;
                tmp = rb[tmp];
            } else {
                break;
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    int rt;
    for(int i = 0;i < N;++ i) {
        int tmp1, tmp2, tmp3;
        scanf("%d%d%d", &tmp1, &tmp2, &tmp3);
        ls[tmp1] = tmp2;
        rb[tmp1] = tmp3;
        vis[tmp2] = 1;
        vis[tmp3] = 1;
    }
    for(int i = 1;i <= N;++ i) {
        if(! vis[i]) {
            rt = i;
            break;
        }
    }
    pre(rt);
    printf("\n");
    pos(rt);
    printf("\n");
    hie(rt);
    printf("\n");
}