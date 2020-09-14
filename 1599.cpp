/**
 * 括号栈模拟
 * 优化？
 **/
#include <iostream>
#include <stdio.h>
using namespace std;

char a[100233], b[100233], tmp;
int cura, curb, n, op;

int main() {
    scanf("%d", &n);
    for(int i = 0;i < n;++ i) {
        scanf("%d", &op);
        if(op == 1) {
            scanf(" %c", &tmp);
            a[cura ++] = tmp;
            continue;
        }
        if(op == 2) {
            if(cura == 0) continue;
            -- cura;
            continue;
        }
        if(op == 3) {
            if(cura == 0) continue;
            printf("%c\n", a[cura - 1]);
            continue;
        }
        if(op == 4) {
            curb = 0;
            for(int i = 0;i < cura;++ i) {
                b[++ curb] = a[i];
                if((b[curb] == ')' && b[curb - 1] == '(')||(b[curb] == ']' && b[curb - 1] == '[')||(b[curb] == '}' && b[curb - 1] == '{'))
                    curb -= 2;
            }
            if(curb) printf("NO \n");
            else printf("YES \n");
        }
    }
}