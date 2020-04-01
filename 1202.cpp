/**
 * 链表实现大整数类
 **/
#include <iostream>
#include <cstdio>
using namespace std;
 
class LIST {
public: 
    struct NODE {
        int data;
        NODE *last;
        NODE *next;
    };
 
    NODE *head = NULL, *tail = NULL;
    int len = 0;
 
    void Pre() {
        head = new NODE;
        tail = new NODE;
        head->next = tail;
        head->last = NULL;
        tail->next = NULL;
        tail->last = head;
    }

    NODE* move(int i) {
        NODE *ith = head;
        int k = 0;
        while (k < i) {
            ++ k;
            ith = ith->next;
        }
        return ith;
    }

    void insert(int i, int x) {
        ++ len;
        NODE *ptr = new NODE;
        NODE *tmp = move(i);
        ptr->data = x;
        ptr->last = tmp;
        ptr->next = tmp->next;
        tmp->next = ptr;
        ptr->next->last = ptr;
        return;
    }

    void remove(int i) {
        --len;
        NODE *tmp = move(i);
        NODE *delptr = tmp->next;
        tmp->next = delptr->next;
        delptr->next->last = tmp;
        delete delptr;
    }

    int Get_length() {
        return len;
    }

    int Query(int i) {
        if (i >= len) return -1;
        else return move(i)->next->data;
    }
    
    void Print() {
        NODE *ptr;
        if (len == 0) cout << -1 << endl;
        else {
            ptr = head->next;
            while (ptr != NULL && ptr->next != NULL) {
                printf("%d", ptr->data);
                ptr = ptr->next;
            }
            cout << endl;
        }
        return;
    }
    
    void Clear() {
        NODE *ptr = head;
        while (ptr->next != NULL) {
            NODE *tmp = ptr;
            delete ptr;
            ptr = tmp->next;
        }
    }
 
};
int main() {
    LIST L1, L2, L;
    L1.Pre(); L2.Pre(); L.Pre();
    char tmp;
    while(1) {
        tmp = getchar();
        if(tmp == '\n') break;
        L1.insert(0, tmp - '0');
    }
    while(1) {
        tmp = getchar();
        if(tmp == '\n') break;
        L2.insert(0, tmp - '0');
    }
    int carry = 0;
    LIST::NODE *p1 = L1.head->next, *p2 = L2.head->next;
    for(int i = 0;i < L1.len || i < L2.len;++ i) {
        int tmp1, tmp2;
        if(p1->next == NULL) tmp1 = 0;
        else {
            tmp1 = p1->data;
            p1 = p1->next;
        }
        if(p2->next == NULL) tmp2 = 0;
        else {
            tmp2 = p2->data;
            p2 = p2->next;
        }
        int sum = tmp1 + tmp2 + carry;
        L.insert(0, sum % 10);
        carry = sum / 10;
    }
    if(carry) {
        L.insert(0, 1);
    }
    L.Print();
    L1.Clear();
    L2.Clear();
    L.Clear();
    return 0;
}