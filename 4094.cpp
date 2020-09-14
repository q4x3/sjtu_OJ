/**
 * 模拟题
 * 注意 顾客第一次没床位第二次也不会进来...
 * 理解题意5555
 **/
#include <iostream>
#include <cstring>

using namespace std;

int num, cnt, cur;
char cus[100];
int in[30], lef[30];

int main() {
    while(1) {
        scanf("%d", &num);
        if(num == 0) break;
        cnt = 0; cur = 0;
        for(int i = 0;i < 30;++ i) {
            in[i] = 0;
            lef[i] = 0;
        }
        scanf("%s", cus);
        for(int i = 0;i < strlen(cus);++ i) {
            if(in[cus[i] - 'A']) {
                in[cus[i] - 'A'] = 0;
                -- cur;
            } else {
                if(cur < num) {
                    if(lef[cus[i] - 'A']) continue;
                    in[cus[i] - 'A'] = 1;
                    ++ cur;
                }
                else {
                    if(! lef[cus[i] - 'A']) ++ cnt;
                    lef[cus[i] - 'A'] = 1;
                }
            }
        }
        if(cnt) printf("%d customer(s) walked away.\n", cnt);
        else printf("All customers tanned successfully.\n");
    }
}