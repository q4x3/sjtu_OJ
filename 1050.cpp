/**
 * 左堆
 * aaaaaaaaaawsl
 * 根节点较大的堆与另一个堆的右子树归并
 * 若产生的堆违反左堆定义，交换左右子树
 * 某个堆为空时，另一个堆就是归并结果
 **/
#include <iostream>

using namespace std;

struct node {
    int dt, npl;
    node *l, *r;
    node():dt(0), npl(-1), l(nullptr), r(nullptr) {}
};

int siz[300233];
node* n[300233];
int M, N, tmp;

node* merge(node *a, node *b) {
    if(! a) return b;
    if(! b) return a;
    if(a->dt > b->dt) swap(a, b);
    a->r = merge(a->r, b);
    if((! a->l) || (a->l->npl < a->r->npl)) swap(a->l, a->r);
    if(! a->r) a->npl = 0;
    else a->npl = a->npl = a->r->npl + 1;
    return a;
}

int main() {
    scanf("%d%d", &N, &M);
    for(int i = 1;i <= N;++ i) {
        scanf("%d", &tmp);
        n[i] = new node;
        n[i]->dt = tmp; n[i]->npl = 0;
        siz[i] = 1;
    }
    for(int i = 1;i <= M;++ i) {
        scanf("%d", &tmp);
        if(tmp == 0) {
            int a, b;
            scanf("%d%d", &a, &b);
            ++ a; ++ b;
            siz[a] += siz[b];
            siz[b] = 0;
            n[a] = merge(n[a], n[b]);
            n[b] = nullptr;
        } else if(tmp == 1) {
            int a;
            scanf("%d", &a);
            ++ a;
            if(siz[a] == 0 || ! n[a]) {
                printf("-1\n");
                continue;
            }
            else printf("%d\n", n[a]->dt);
            n[a] = merge(n[a]->l, n[a]->r);
            -- siz[a];
        } else {
            int a, b;
            scanf("%d%d", &a, &b);
            ++ a;
            node *newnode = new node;
            newnode->dt = b; newnode->npl = 0;
            n[a] = merge(n[a], newnode);
            ++ siz[a];
        }
    }
}