#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

char op[] = {'+', '-', '*', '/', '^'};
int pr[] = {1, 1, 2, 2, 3};    //决定运算优先级
int flag = true;//是否出现错误
char input[200];
char str[130];

long long dfs(char *a, int l);

void SkipSpace(char *);

int main()
{
    std::cin.getline(input, 200);
    SkipSpace(input);
    long long result = dfs(str, strlen(str));
    if (flag) 
        std::cout << result;
    else 
        std::cout << "Error";
    return 0;
}


void SkipSpace(char *a) {
    int count = 0;
    for (int i = 0; i < strlen(a); i++) {
        if (a[i] != ' ') {
            str[count] = a[i];
            count++;
        }
    } 
    return;
}
long long dfs(char *a, int l)
{
    if (!flag) 
        return 0;       //出错跳出
    //去除首尾括号、空格， 同时检查括号匹配
    
    while (1) { //去除外层的括号
        int d = 0;
        for (int i = 0; i < l - 1; i++) {
            if (a[i] == '(')
                d++;
            if (a[i] == ')') 
                d--;
            if (d == 0) {
                d = -1;
                break;
            }
        }
        if (d == 1 && a[l - 1] == ')') {
            a++;
            l -= 2;
        } else {
            break;
        }
    }
    int dep = 0, mm = 0x3f3f3f3f, mp = -1;      //找到优先级最低的运算符
    bool isNegSign = true;
    if (a[0] == '-' && a[1] == '(' && a[l - 1] == ')') {        //特判 -( ... ) 这种情况
        long long R = dfs(a + 1, l - 1);
        if (!flag)
            return 0;
        return -1 * R;
    }
    for (int i = 0; i < l; i++) {
        if (a[i] == '(') {
            dep++;
        }
        if (a[i] == ')') {
            dep--;
        }
        for (int j = 0; j < 5; j++) { //deal with the priority of the operator
            if (a[i] == op[j]) {
                if (dep > 0) {
                    continue;
                }
                if (a[i] == '-' && isNegSign)
                    continue;
                if (j == 4 && pr[j] < mm || j != 4 && pr[j] <= mm) {
                    mm = pr[j];
                    mp = i;
                }
                isNegSign = true;
            }
        }
        if (a[i] >= '0' && a[i] <= '9')
            isNegSign = false;
        
    }
    if (dep != 0) {         //抛出异常
        flag = false;
        return 0;
    }
    if (mp == -1) {
        long long num = 0;
        int start = 0;
        bool isNegetive = false;
        if (a[0] == '-'){
            start = 1;
            isNegetive = true;
        }
        for (int i = start; i < l; i++) {
            num = num * 10 + a[i] - '0';
        }
        if (isNegetive) 
            num = 0 - num;
        return num;
    }
    //std::cout << a[mp - 1] << a[mp] << a[mp + 1] << std::endl;
    if (a[mp] == '+') {
        long long L = dfs(a, mp);
        if (!flag)
            return 0;
        long long R = dfs(a + mp + 1, l - mp - 1);
        if (!flag)
            return 0;
        return L + R;
    } else if (a[mp] == '-') {
        long long L = dfs(a, mp);
        if (!flag)
            return 0;
        long long R = dfs(a + mp + 1, l - mp - 1);
        if (!flag)
            return 0;
        return L - R;
    } else if (a[mp] == '*') {
        long long L = dfs(a, mp);
        if (!flag)
            return 0;
        long long R = dfs(a + mp + 1, l - mp - 1);
        if (!flag)
            return 0;
        return L * R;
    } else if (a[mp] == '/') {
        long long L = dfs(a, mp);
        if (!flag)
            return 0;
        long long R = dfs(a + mp + 1, l - mp - 1);
        if (!flag)
            return 0;
        if (R == 0) {
            flag = false;
            return 0;
        }
        else 
            return L / R;
    } else if (a[mp] == '^') {
        long long L = dfs(a, mp);
        if (!flag)
            return 0;
        long long R = dfs(a + mp + 1, l - mp - 1);
        if (!flag)
            return 0;
        return (int)pow(L, R);
    }
}
