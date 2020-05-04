#include <iostream>
#include <cstdio>

using namespace std;

int pre[60], mid[60], pos[60], k;

void dfs(int rt, int prel, int prer, int posl, int posr) {
    cout << pre[rt] << ' ';
    for(int i = pos;i < ;++ i) {

    }
}

int main() {
    cin >> k;
    for(int i = 0;i < k;++ i)
        cin >> pre[i];
    for(int i = 0;i < k;++ i)
        cin >> mid[i];
    for(int i = 0;i < k;++ i)
        cin >> pos[i];
    dfs(0, 0, k);
}