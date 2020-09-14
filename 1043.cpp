/**
 * 完全二叉树判断
 * 凭直觉写
 * 草死了二叉树鲨我
 **/
#include <stdio.h>
#include <iostream>

using namespace std;

int N;

struct node{
    int self;
    int fa;
    node *left, *right;
    node():fa(-1), left(NULL), right(NULL) {}
};

node no[1000233];
int fa[1000233];

void build() {
    for(int i = 0;i <= N;++ i) {
        no[i].self = i;
        no[i].fa = fa[i];
    }
    for(int i = 0;i < N;++ i) {
        node *fano = &(no[fa[i]]);
        node *le = fano->left;
        if(le) {
            if(le->self > i) {
                fano->right = le;
                fano->left = &(no[i]);
            } else {
                fano->right = &(no[i]);
            }
        } else {
            if(i) fano->left = &(no[i]);
        }
    }
}

bool check(node *rt) {
    if(rt == NULL) {
        return 0;
    }
    node* che[1000233];
    int head = 0, rear = 0;
    che[rear ++] = rt;
    while(head != rear) {
        node *top = che[head];
        if(top->left && top->right) {
            ++ head;
            che[rear ++] = top->left;
            che[rear ++] = top->right;
        } else 
        if(top->left == NULL && top->right) {
            return 0;
        } else 
        if((top->left && top->right == NULL) ||
                  (top->left == NULL && top->right == NULL)) {
            ++ head;
            while(head != rear) {
                top = che[head];
                if(top->left == NULL && top->right == NULL) {
                    ++ head;
                } else {
                    return 0;
                }
            }
            return 1;
        }
    }
    return 1;
}

int main() {
    scanf("%d", &N);
    for(int i = 1;i < N;++ i) {
        scanf("%d", &fa[i]);
    }
    build();
    if(check(&(no[0]))) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}