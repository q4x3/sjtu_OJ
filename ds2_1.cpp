/**
 * 60分做法
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

void insert(node* &rt, int p, int l, int r) {
    if(rt == nullptr) {
        rt = new node(p);
        if(l) rt->left = new node(l);
        if(r) rt->right = new node(r);
    } else if(rt->data < p) {
        insert(rt->right, p, l, r);
    } else if(rt->data > p) {
        insert(rt->left, p, l, r);
    }
}

void insert2(node* &rt, int p) {
    if(rt == nullptr) {
        rt = new node(p);
    } else if(rt->data < p) {
        insert2(rt->right, p);
    } else if(rt->data > p) {
        insert2(rt->left, p);
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

int N, M;
int p, l, r, Q;
node *root;
node* q[200233];
int che[200233];

bool ceng() {
    int head = 0, rear = 0, cnt = 1;
    bool tmp = 0;
    q[head] = root;
    rear ++;
    while(head < rear) {
        node* top = q[head];
        if(che[cnt] != top->data) tmp = 1;
        che[cnt ++] = top->data;
        ++ head;
        if(top->left) {
            q[rear] = top->left;
            ++ rear;
        }
        if(top->right) {
            q[rear] = top->right;
            ++ rear;
        }
    }
    return tmp;
}


bool check(int key) {
    del(root, key);
    insert2(root, key);
    return ceng();
}

int main() {
    scanf("%d%d", &N, &M);
    for(int i = 1;i <= N;++ i) {
        scanf("%d%d%d", &p, &l, &r);
        insert(root, p, l, r);
    }
    ceng();
    for(int i = 1;i <= M;++ i) {
        scanf("%d", &Q);
        if(check(Q)) printf("1\n");
        else printf("0\n");
    }
    return 0;
}