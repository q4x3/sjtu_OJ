#include <iostream>
#include <cstdio>

// 红黑树模板源自于luogu
template<typename T>
class redblacktree {
 protected:
  struct Node;

  Node* _root;
  Node* _hot;

  void init(T);
  void connect34(Node*, Node*, Node*, Node*, Node*, Node*, Node*);
  void SolveDoubleRed(Node*);
  void SolveDoubleBlack(Node*);
  Node* find(T, const int);
  Node* rfind(T, const int);
  Node* findkth(int, Node*);
  int find_rank(T, Node*);

 public:

  struct iterator;

  redblacktree() : _root(NULL), _hot(NULL) {}

  int get_rank(T);
  iterator insert(T);
  bool remove(T);
  int size();
        bool empty();
  iterator kth(int);
  iterator lower_bound(T);
  iterator upper_bound(T);
};

template <typename T>
struct redblacktree<T>::Node {
 T val;
 bool RBc;
 Node* ftr;
 Node* lc;
 Node* rc;
 int s;

 Node( T v = T(), bool RB = true,
         Node* f = NULL, Node* l = NULL, Node* r = NULL ,int ss = 1 )
  : val(v), RBc(RB), ftr(f), lc(l), rc(r), s(ss) {}

 Node* succ() {
  Node* ptn = rc;
  while(ptn->lc != NULL) {
   --(ptn->s);
   ptn = ptn->lc;
  }
  return ptn;
 }

 Node* left_node() {
  Node* ptn = this;
  if(!lc) {
   while(ptn->ftr && ptn->ftr->lc == ptn)
    ptn = ptn->ftr;
   ptn = ptn->ftr;
  } else {
   ptn = ptn->lc;
   while(ptn->rc) {
    ptn = ptn->rc;
   }
  }
  return ptn;
 }

 Node* right_node() {
  Node* ptn = this;
  if(!rc) {
   while(ptn->ftr && ptn->ftr->rc == ptn)
    ptn = ptn->ftr;
   ptn = ptn->ftr;
  } else {
   ptn = ptn->rc;
   while(ptn->lc) {
    ptn = ptn->lc;
   }
  }
  return ptn;
 }

 void maintain() {
  s = 1;
  if(lc) s += lc->s;
  if(rc) s += rc->s;
 }
};
template <typename T>
struct redblacktree<T>::iterator {
 private:

  Node* _real__node;

 public:

  iterator& operator++() {
   _real__node = _real__node->right_node();
   return *this;
  }

  iterator& operator--() {
   _real__node = _real__node->left_node();
   return *this;
  }

  T operator*() {
   return _real__node->val;
  }

  iterator(Node* node_nn = NULL) : _real__node(node_nn) {}
  iterator(T const& val_vv) : _real__node(rfind(val_vv, 0)) {}
  iterator(iterator const& iter) : _real__node(iter._real__node) {}

};

template <typename T>
typename
redblacktree<T>::iterator redblacktree<T>::insert(T v) {
 Node* ptn = find(v, 1);
 if(_hot == NULL) {
  init(v);
  return iterator(_root);
 }
 ptn = new Node(v, true, _hot, NULL, NULL, 1);
 if( _hot->val <= v )
  _hot->rc = ptn;
 else
  _hot->lc = ptn;
 SolveDoubleRed(ptn);
 return iterator(ptn);
}

template <typename T>
void redblacktree<T>::init(T v) {
 _root = new Node(v, false, NULL, NULL, NULL, 1);



}

template <typename T>
typename
redblacktree<T>::Node* redblacktree<T>::find(T v, const int op) {
 Node* ptn = _root;
 _hot = NULL;
 while(ptn != NULL) {
  _hot = ptn;
  ptn->s += op;
  if(ptn->val > v)
   ptn = ptn->lc;
  else
   ptn = ptn->rc;
 }
 return ptn;
}

template <typename T>
typename
redblacktree<T>::Node* redblacktree<T>::rfind(T v, const int op) {
 Node* ptn = _root;
 _hot = NULL;
 while(ptn != NULL && ptn->val != v) {
  _hot = ptn;
  ptn->s += op;
  if(ptn->val > v)
   ptn = ptn->lc;
  else
   ptn = ptn->rc;
 }
 return ptn;
}

template <typename T>
void redblacktree<T>::SolveDoubleRed(Node* nn) {
 while((!(nn->ftr)) || nn->ftr->RBc) {
  if(nn == _root) {
   _root->RBc = false;



   return;
  }
  Node* pftr = nn->ftr;
  if(!(pftr->RBc)) return;
  Node* uncle = (((nn->ftr)->ftr->lc == (nn->ftr)) ? ((nn->ftr)->ftr->rc) : ((nn->ftr)->ftr->lc));
  Node* grdftr = nn->ftr->ftr;
  if(uncle != NULL && uncle->RBc) {
   grdftr->RBc = true;
   uncle->RBc = false;
   pftr->RBc = false;
   nn = grdftr;
  } else {
   if(((pftr) != NULL && (pftr)->ftr->lc == (pftr))) {
    if(((nn) != NULL && (nn)->ftr->lc == (nn))) {
     pftr->ftr = grdftr->ftr;
     if(grdftr == _root) _root = pftr;
     else if(grdftr->ftr->lc == grdftr) grdftr->ftr->lc = pftr;
     else grdftr->ftr->rc = pftr;
     connect34(pftr, nn, grdftr, nn->lc, nn->rc, pftr->rc, uncle);
     pftr->RBc = false;
     grdftr->RBc = true;
    } else {
     nn->ftr = grdftr->ftr;
     if(grdftr == _root) _root = nn;
     else if(grdftr->ftr->lc == grdftr) grdftr->ftr->lc = nn;
     else grdftr->ftr->rc = nn;
     connect34(nn, pftr, grdftr, pftr->lc, nn->lc, nn->rc, uncle);
     nn->RBc = false;
     grdftr->RBc = true;
    }
   } else {
    if(((nn) != NULL && (nn)->ftr->lc == (nn))) {
     nn->ftr = grdftr->ftr;
     if(grdftr == _root) _root = nn;
     else if(grdftr->ftr->lc == grdftr) grdftr->ftr->lc = nn;
     else grdftr->ftr->rc = nn;
     connect34(nn, grdftr, pftr, uncle, nn->lc, nn->rc, pftr->rc);
     nn->RBc = false;
     grdftr->RBc = true;
    } else {
     pftr->ftr = grdftr->ftr;
     if(grdftr == _root) _root = pftr;
     else if(grdftr->ftr->lc == grdftr) grdftr->ftr->lc = pftr;
     else grdftr->ftr->rc = pftr;
     connect34(pftr, grdftr, nn, uncle, pftr->lc, nn->lc, nn->rc);
     pftr->RBc = false;
     grdftr->RBc = true;
    }
   }
   return;
  }
 }
}

template <typename T>
void redblacktree<T>::connect34( Node* nroot, Node* nlc, Node* nrc,
                                    Node* ntree1, Node* ntree2, Node* ntree3, Node* ntree4) {
 nlc->lc = ntree1;
 if(ntree1 != NULL) ntree1->ftr = nlc;
 nlc->rc = ntree2;
 if(ntree2 != NULL) ntree2->ftr = nlc;
 nrc->lc = ntree3;
 if(ntree3 != NULL) ntree3->ftr = nrc;
 nrc->rc = ntree4;
 if(ntree4 != NULL) ntree4->ftr = nrc;
 nroot->lc = nlc;
 nlc->ftr = nroot;
 nroot->rc = nrc;
 nrc->ftr = nroot;
 nlc->maintain();
 nrc->maintain();
 nroot->maintain();
}

template <typename T>
typename
redblacktree<T>::iterator redblacktree<T>::lower_bound(T v) {
 Node* ptn = _root;
 while(ptn) {
  _hot = ptn;
  if(ptn->val < v) {
   ptn = ptn->rc;
  } else {
   ptn = ptn->lc;
  }
 }
 if(_hot->val < v) {
  ptn = _hot;
 } else {
  ptn = _hot->left_node();
 }
 return iterator(ptn);
}

template <typename T>
typename
redblacktree<T>::iterator redblacktree<T>::upper_bound(T v) {
 Node* ptn = _root;
 while(ptn) {
  _hot = ptn;
  if(ptn->val > v) {
   ptn = ptn->lc;
  } else {
   ptn = ptn->rc;
  }
 }
 if(_hot->val > v) {
  ptn = _hot;
 } else {
  ptn = _hot->right_node();
 }
 return iterator(ptn);
}

template <typename T>
typename
redblacktree<T>::iterator redblacktree<T>::kth(int rank) {
 return iterator(findkth(rank, _root));
}

template <typename T>
typename
redblacktree<T>::Node* redblacktree<T>::findkth(int rank, Node* ptn) {
 if(!(ptn->lc)) {
  if(rank == 1) {
   return ptn;
  } else {
   return findkth(rank - 1, ptn->rc);
  }
 } else {
  if(ptn->lc->s == rank - 1) return ptn;
  else if(ptn->lc->s >= rank) return findkth(rank, ptn->lc);
  else return findkth(rank - (ptn->lc->s) - 1, ptn->rc);
 }
}

template <typename T>
int redblacktree<T>::get_rank(T v) {
 return find_rank(v, _root);
}

template <typename T>
int redblacktree<T>::find_rank(T v, Node* ptn) {
 if(!ptn) return 1;
 else if(ptn->val >= v) return find_rank(v, ptn->lc);
 else return (1 + ((ptn->lc) ? (ptn->lc->s) : 0) + find_rank(v, ptn->rc));
}

template <typename T>
int redblacktree<T>::size() {
 return _root->s;
}

template <typename T>
bool redblacktree<T>::empty() {
 return !_root;
}
template <typename T>
bool redblacktree<T>::remove(T v) {
 Node* ptn = rfind(v, -1);
 if(!ptn) return false;
 Node* node_suc;
 while(ptn->lc || ptn->rc) {
  if(!(ptn->lc)) {
   node_suc = ptn->rc;
  } else if(!(ptn->rc)) {
   node_suc = ptn->lc;
  } else {
   node_suc = ptn->succ();
  }
  --(ptn->s);
  ptn->val = node_suc->val;
  ptn = node_suc;
 }
 if(!(ptn->RBc)) {
  --(ptn->s);
  SolveDoubleBlack(ptn);
 }
 if(ptn == _root) {
  _root = NULL;
  delete ptn;
  return true;
 }
 if(ptn->ftr->lc == ptn)
  ptn->ftr->lc = NULL;
 else
  ptn->ftr->rc = NULL;
 delete ptn;
 return true;
}

template <typename T>
void redblacktree<T>::SolveDoubleBlack(Node* nn) {
 while(nn != _root) {
  Node* pftr = nn->ftr;
  Node* bthr = (((nn)->ftr->lc == (nn)) ? ((nn)->ftr->rc) : ((nn)->ftr->lc));
  if(bthr->RBc) {
   bthr->RBc = false;
   pftr->RBc = true;
   if(_root == pftr) _root = bthr;
   if(pftr->ftr) {
    if(pftr->ftr->lc == pftr)
     pftr->ftr->lc = bthr;
    else
     pftr->ftr->rc = bthr;
   }
   bthr->ftr = pftr->ftr;
   if(((nn) != NULL && (nn)->ftr->lc == (nn))) {
    connect34(bthr, pftr, bthr->rc, nn, bthr->lc, bthr->rc->lc, bthr->rc->rc);
   } else {
    connect34(bthr, bthr->lc, pftr, bthr->lc->lc, bthr->lc->rc, bthr->rc, nn);
   }
   bthr = (((nn)->ftr->lc == (nn)) ? ((nn)->ftr->rc) : ((nn)->ftr->lc));
   pftr = nn->ftr;
  }
  if(bthr->lc && bthr->lc->RBc) {
   bool oldRBc = pftr->RBc;
   pftr->RBc = false;
   if(pftr->lc == nn) {
    if(pftr->ftr) {
     if(pftr->ftr->lc == pftr)
      pftr->ftr->lc = bthr->lc;
     else
      pftr->ftr->rc = bthr->lc;
    }
    bthr->lc->ftr = pftr->ftr;
    if(_root == pftr) _root = bthr->lc;
    connect34(bthr->lc, pftr, bthr, pftr->lc, bthr->lc->lc, bthr->lc->rc, bthr->rc);
   } else {
    bthr->lc->RBc = false;
    if(pftr->ftr) {
     if(pftr->ftr->lc == pftr)
      pftr->ftr->lc = bthr;
     else
      pftr->ftr->rc = bthr;
    }
    bthr->ftr = pftr->ftr;
    if(_root == pftr) _root = bthr;
    connect34(bthr, bthr->lc, pftr, bthr->lc->lc, bthr->lc->rc, bthr->rc, pftr->rc);
   }
   pftr->ftr->RBc = oldRBc;
   return;
  } else if(bthr->rc && bthr->rc->RBc) {
   bool oldRBc = pftr->RBc;
   pftr->RBc = false;
   if(pftr->lc == nn) {
    bthr->rc->RBc = false;
    if(pftr->ftr) {
     if(pftr->ftr->lc == pftr)
      pftr->ftr->lc = bthr;
     else
      pftr->ftr->rc = bthr;
    }
    bthr->ftr = pftr->ftr;
    if(_root == pftr) _root = bthr;
    connect34(bthr, pftr, bthr->rc, pftr->lc, bthr->lc, bthr->rc->lc, bthr->rc->rc);
   } else {
    if(pftr->ftr) {
     if(pftr->ftr->lc == pftr)
      pftr->ftr->lc = bthr->rc;
     else
      pftr->ftr->rc = bthr->rc;
    }
    bthr->rc->ftr = pftr->ftr;
    if(_root == pftr) _root = bthr->rc;
    connect34(bthr->rc, bthr, pftr, bthr->lc, bthr->rc->lc, bthr->rc->rc, pftr->rc);
   }
   pftr->ftr->RBc = oldRBc;
   return;
  }
  if(pftr->RBc) {
   pftr->RBc = false;
   bthr->RBc = true;
   return;
  } else {
   bthr->RBc = true;
   nn = pftr;
  }
 }

}

int N, M, cnt, fa[500233], box[500233];
bool eaten[500233];
redblacktree<int> t;
int init() {
    for(int i = 1;i <= N;++ i)
        fa[i] = i;
}

int find(int x) {
    if(fa[x] == x) return x;
    else return fa[x] = find(fa[x]);
}

int bind(int x, int y) {
    fa[find(x)] = find(y);
}

int main() {
	int maxi = 1;
	scanf("%d%d", &N, &M);
    cnt = N;
	init();
	for(int i = 1;i <= N;++ i)
		box[i] = 1;
	for(int i = 1;i <= N;++ i)
		t.insert(1);
    for(int i = 1;i <= M;++ i) {
        char op[2];
        scanf("%s", op);
        if(op[0] == 'C') {
            int x, y;
            scanf("%d%d", &x, &y);
            int fx = find(x), fy = find(y);
			if(eaten[fx] | eaten[fy]) continue;
			if(fx == fy) continue;
			bind(fx, fy);
			t.remove(box[fx]);
			t.remove(box[fy]);
			t.insert(box[fx] + box[fy]);
			box[fy] += box[fx];
			-- cnt;
        } else if(op[0] == 'D') {
            int x;
            scanf("%d", &x);
			int tmp = find(x);
			if(eaten[tmp]) continue;
			else {
				t.remove(box[tmp]);
				eaten[tmp] = 1;
				-- cnt;
			}
        } else {
            int p;
            scanf("%d", &p);
			if(cnt < p) {
				printf("0\n");
				continue;
			}
            printf("%d\n", *t.kth(cnt - p + 1));
        }
    }
}