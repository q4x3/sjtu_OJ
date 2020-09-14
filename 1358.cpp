#include <iostream>
 
using namespace std;
 
int map[100233][100], sonnum[100233];
int N, tmp1, tmp2, siz[100233], vis[100233];
 
int dfs(int rt) {
    siz[rt] = 1;
    vis[rt] = 1;
    for(int i = 1;i <= sonnum[rt];++ i) {
        if(! vis[map[rt][i]]) {
            siz[rt] += dfs(map[rt][i]);
        }
    }
    return siz[rt];
}
 
bool check(int num) {
    if(N - siz[num] > (N >> 1)) return 0;
    for(int i = 1;i <= sonnum[num];++ i) {
        if(siz[map[num][i]] < siz[num] && siz[map[num][i]] > (N >> 1)) return 0;
    }
    return 1;
}
 
int main() {
    scanf("%d", &N);
    for(int i = 0;i < N - 1;++ i) {
        scanf("%d%d", &tmp1, &tmp2);
        map[tmp1][++ sonnum[tmp1]] = tmp2;
        map[tmp2][++ sonnum[tmp2]] = tmp1;
    }
    dfs(1);
    for(int i = 1;i <= N;++ i) {
        if(check(i)) printf("%d ", i);
    }
    printf("\n");
    return 0;
}
提交者： 519021910876 陶青筱 那当然是救实验报告了，毕竟花的时间更长啊🙂
题目编号： 1358 
语言：C++
提交时间：2020-06-04 21:14:30
