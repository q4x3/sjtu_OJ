/**
 * 二叉搜索树
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

void insert(node* &rt, int p) {
    if(rt == nullptr) {
        rt = new node(p);
    } else if(rt->data < p) {
        insert(rt->right, p);
    } else if(rt->data > p) {
        insert(rt->left, p);
    }
}

void del(node* &rt, int key) {
    if(rt->data < key) {
        del(rt->right, key);
        return;
    } else if(rt->data > key) {
        del(rt->left, key);
        return;
    }
    if(rt->left == nullptr && rt->right == nullptr) {
        delete rt;
        rt = nullptr;
    } else if(rt->left && rt->right == nullptr) {
        rt = rt->left;
    } else if(rt->left == nullptr && rt->right) {
        rt = rt->right;
    } else {
        node* tmp = rt->right;
        while(tmp->left) tmp = tmp->left;
        rt->data = tmp->data;
        del(rt->right, rt->data);
    }
}

int min(int x, int y) {
    return x < y ? x : y;
}

int query(node* rt, int x) {
    int ans = 2e9;
    while(rt != nullptr) {
        if(rt->data < x) {
            ans = min(ans, x - rt->data);
            rt = rt->right;
        } else if(rt->data > x) {
            ans = min(ans, rt->data - x);
            rt = rt->left;
        } else return 0;
    }
    return ans;
}

node *root;
int M, op, x;

int main() {
    scanf("%d", &M);
    for(int i = 0;i < M;++ i) {
        scanf("%d%d", &op, &x);
        if(op == 0) {
            printf("%d\n", query(root, x));
        } else if(op == 1) {
            insert(root, x);
        } else {
            del(root, x);
        }
    }
}