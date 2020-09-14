/**
 * 栈模拟
 * 为什么每道题都要快读TATTTTT
 **/
#include <iostream>
#include <stdio.h>

using namespace std;
int tmp, nex, flag = 1;

struct sstack
{
    int a[1000233];
    int top;
};

void read(int &x){
	x = 0;
	char ch;
	while (ch = getchar(), (ch < '0' || ch > '9'));
	x = ch - '0';
	while(ch = getchar(), ch >= '0' && ch <= '9') x = 10 * x + ch - '0';
}

int main() {
    int T;
    cin >> T;
    for(int i = 0;i < T;++ i) {
        int N;
        nex = 0; flag = 1;
        read(N);
        sstack s;
        s.top = 0; s.a[0] = nex;
        for(int i = 0;i < N;++ i) {
            read(tmp);
            while(flag) {
                if(s.a[s.top] == tmp - 1) {
                    -- s.top;
                    break;
                }
                ++ s.top;
                ++ nex;
                if(nex + 1 > N) flag = 0;
                s.a[s.top] = nex;
            }
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
}