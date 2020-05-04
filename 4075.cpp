/**
 * kmp板子
 **/
#include <iostream>
#include <cstring>
using namespace std;

int nxt[100233];
char txt[1000233], pat[100233];

void cal_nxt(int len) {
    //nxt[0]初始化为-1，-1表示不存在相同的最大前缀和最大后缀
    nxt[0] = -1;
    //k初始化为-1
    int k = -1;
    for (int i = 1; i <= len - 1; ++ i) {
        //如果下一个不同，那么k就变成nxt[k]，注意nxt[k]是小于k的，无论k取任何值
        while (k > -1 && pat[k + 1] != pat[i]) {
            k = nxt[k];//往前回溯
        }
        //如果相同，k++
        if (pat[k + 1] == pat[i]) {
            ++ k;
        }
        //把算的k的值（就是相同的最大前缀和最大后缀长）赋给nxt[i]
        nxt[i] = k;
    }
}

int kmp(int tlen, int plen) {
    int k = -1;
    for (int i = 0; i < tlen; ++ i)
    {
        //pat和txt不匹配，且k > -1（表示pat和txt有部分匹配）
        while (k > -1 && pat[k + 1] != txt[i])
            //往前回溯
            k = nxt[k];
        if (pat[k + 1] == txt[i]) ++ k;
        //说明k移动到pat的最末端
        if (k == plen - 1) return i - plen + 1;//返回相应的位置
    }
    return -1;
}

int main() {
    scanf("%s%s", txt, pat);
    int plen = strlen(pat), tlen = strlen(txt);
    cal_nxt(plen);
    cout << kmp(tlen, plen) << endl;
}