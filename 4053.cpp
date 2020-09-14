/**
 * dfs
 **/
#include <stdio.h>
#include <iostream>

using namespace std;

int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

bool isPrime(int a) {
    for(int i = 0;i < 11;++ i) {
        if(a == p[i]) return 1;
    }
    return 0;
}

int n, a[20], vis[20];

void dfs(int x) {
    if(x == n + 1 && isPrime(a[1] + a[n])) {
        for(int i = 1;i <= n;++ i) {
            printf("%d ", a[i]);
        }
        printf("\n");
        return;
    }
    for(int i = 2;i <= n;++ i) {
        if(!vis[i] && isPrime(a[x - 1] + i)) {
            vis[i] = 1;
            a[x] = i;
            dfs(x + 1);
            vis[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    if((n == 1) || (n == 3) || (n == 5) || (n == 7) || (n == 9) || (n == 11)|| (n == 13) || (n == 15)) {
        cout << "None" << endl;
    } else {
        a[1] = 1;
        dfs(2);
    }
    return 0;
}