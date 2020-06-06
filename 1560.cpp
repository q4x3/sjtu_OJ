/**
 * 我恨二叉搜索树
 * 会恨一辈子的
 **/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

struct node {
    int data;
    node *left, *right;
    node(int dt):data(dt), left(nullptr), right(nullptr) {}
};

void find(node* rt, int key, char* ans) {
    if(rt == nullptr) {
        strcpy(ans, "Nothing.");
        return;
    }
    if(rt->data == key) {
        return;
    } else if(rt->data < key) {
        strcat(ans, "r");
        find(rt->right, key, ans);
    } else {
        strcat(ans, "l");
        find(rt->left, key, ans);
    }
}

void insert(node* &rt, int p) {
    if(rt == nullptr) {
        rt = new node(p);
    } else if(rt->data < p) {
        insert(rt->right, p);
    } else if(rt->data > p) {
        insert(rt->left, p);
    }
}

void dele(node* &rt) {
    rt->left = rt->left->right;
}

void del(node* &rt, int key) {
    if(rt == nullptr) return;
    if(rt->data < key) {
        del(rt->right, key);
        return;
    } else if(rt->data > key) {
        del(rt->left, key);
        return;
    }
    if(rt->right == nullptr) {
        rt = rt->left;
    } else {
        node* tmp = rt->right;
        if(tmp->left == nullptr) {
            rt->right->left = rt->left;
            rt = rt->right;
            return;
        }
        while(tmp->left->left) tmp = tmp->left;
        rt->data = tmp->left->data;
        dele(tmp);
    }
}

node *root;
char op[3], ans[100233];
int x, Q;

int main() {
    freopen("a.in", "r", stdin);
    freopen("b.out", "w", stdout);
    scanf("%d", &Q);
    for(int i = 1;i <= Q;++ i) {
        scanf("%s", op);
        scanf("%d", &x);
        if(op[0] == '+') {
            insert(root, x);
        } else if(op[0] == '-') {
            del(root, x);
        } else {
            strcpy(ans, "*");
            find(root, x, ans);
            printf("%s\n", ans);
        }
    }
}