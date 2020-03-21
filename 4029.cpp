#include <iostream>
#include <stdio.h>

using namespace std;

int N, a[1010], M, ask[300233], dis[20233], m = 20233, INF = 41000000, que[10100000];
bool vis[20233]; //访问标记 是否在队中

void spfa() {
    int head = 0, rear = 0;
    for(int i = 1;i < m;++ i)
        dis[i] = INF;
    que[head] = 0; ++ rear;
    //队空则结束循环
    while(head < rear) {
        //记录队首
        int cur = que[head];
        //队首出队
        vis[que[head]] = 0;
        ++ head;
        //计算每条边可以到达的节点及路径长度 若短于记录 则更新记录 若vis为0 则入队
        for(int i = 0;i < N;++ i) {
            //计算
            int node = (cur + a[i]) % m;
            int tmpdis = dis[cur] + a[i];
            //判断
            if(tmpdis < dis[node]) {
                //更新
                dis[node] = tmpdis;
                //入队
                if(vis[node] == 0) {
                    que[rear] = node;
                    ++ rear;
                    vis[node] = 1;
                }
            }
        }
    }
}

int main() {
    cin >> N;
    for(int i = 0;i < N;++ i) {
        scanf("%d", &a[i]);
        if(a[i] < m) m = a[i];
    }
    spfa();
    cin >> M;
    for(int i = 0;i < M;++ i) {
        scanf("%d", &ask[i]);
    }
    for(int i = 0;i < M;++ i) {
        if(dis[ask[i] % m] <= ask[i]) printf("YES\n");
        else printf("NO\n");
    }
}