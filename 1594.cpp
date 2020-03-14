#include <stdio.h>
#include <cstring>

using namespace std;

int q[10000010][4];

int main()
{
    int N, M, Q;
    scanf("%d%d%d", &N, &M, &Q);
    int **a;
    long long **map;
    a = new int*[N + 1];
    map = new long long int*[N + 1];
    for(int i = 0;i <= N;++ i) {
        a[i] = new int[M + 1];
        map[i] = new long long[M + 1];
    }
    for(int i = 0;i <= N;++ i)
        for (int j = 0;j <= M;++ j) {
            a[i][j] = 0;
            map[i][j] = 0;
        }
    for(int i = 1;i <= N;++ i)
        for (int j = 1;j <= M;++ j)
            scanf("%d", &a[i][j]);
    for(int i = 1;i <= Q;++ i)
        scanf("%d%d%d%d",&q[i][0],&q[i][1],&q[i][2],&q[i][3]);
    for(int i = 1;i <= N;++ i)
        for(int j = 1;j <= M;++ j)
            map[i][j] = map[i - 1][j] + map[i][j - 1] - map[i - 1][j - 1] + a[i][j];
    for(int i = 1;i <= Q;++ i) {
        printf("%lld\n", map[q[i][2]][q[i][3]] + map[q[i][0] - 1][q[i][1] - 1] - map[q[i][2]][q[i][1] - 1] - map[q[i][0] - 1][q[i][3]]);
    }
        
}