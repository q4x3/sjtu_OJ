#include <iostream>

using namespace std;

template <typename T>
struct node {
    node *next;
    T data;
};

template <class T>
class list {
    private:
    node<T> *head, *rear;
    void init() {
        head = rear = new node<T>;
    }
    public:
    list() {init();}
    list(const list &obj) {
        node<T> *p = obj.head->next;
        while(p != NULL) {
            node<T> *q = new node<T>;
            q->data = p->data;
            rear->next = q;
            rear = q;
            p = p->next;
        }
    }
    ~list() {
        node<T> *p = head->next;
        while(p != NULL) {
            node<T> *q = p;
            p = p->next;
            delete q;
        }
        delete head;
    }
    void input(int n) {
        T tmp;
        for(int i = 0;i < n;++ i) {
            cin >> tmp;
            node<T> *p;
            p = new node<T>;
            p->data = tmp;
            rear->next = p;
            rear = p;
        }
        rear->next = NULL;
        return;
    }
    void output() {
        node<T> *p = head->next;
        while(p != NULL) {
            cout << p->data << " ";
            node<T> *q = p;
            p = p->next;
        }
        return;
    }
    void copy(const list &obj) {
        node<T> *p = obj.head->next;
        while(p != NULL) {
            node<T> *q = new node<T>;
            q->data = p->data;
            rear->next = q;
            rear = q;
            p = p->next;
        }
        rear->next = NULL;
    }
    list<T> operator+ (const list<T> &obj) {
        list<T> L;
        node<T> *p1 = head->next;
        while(p1 != NULL) {
            node<T> *q1 = new node<T>;
            q1->data = p1->data;
            L.rear->next = q1;
            L.rear = q1;
            p1 = p1->next;
        }
        node<T> *p2 = obj.head->next;
        while(p2 != NULL) {
            node<T> *q2 = new node<T>;
            q2->data = p2->data;
            L.rear->next = q2;
            L.rear = q2;
            p2 = p2->next;
        }
        L.rear->next = NULL;
        return L;
    }
};

int main() {
    char s[10];
    cin >> s;
    int n, m;
    if(s[0] == 'i') {
        list<int> L1, L2, L;
        cin >> n >> m;
        L1.input(n); L2.input(m);
        L.copy(L1 + L2);
        L.output();
    }
    if(s[0] == 'c') {
        list<char> L1, L2, L;
        cin >> n >> m;
        L1.input(n); L2.input(m);
        L.copy(L1 + L2);
        L.output();
    }
    if(s[0] == 'd') {
        list<double> L1, L2, L;
        cin >> n >> m;
        L1.input(n); L2.input(m);
        L.copy(L1 + L2);
        L.output();
    }
    cout << endl;
    return 0;
}