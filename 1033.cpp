/**
 * 计算器
 * longlong
 * 不判-1 1 0会超时
 * -1 ^ 2 = 1 (这就尼玛离谱)
 * 脑子有病的一个题
 **/
#include <iostream>
#include <stdio.h>
 
using namespace std;
 
struct stk {
    char dat[233];
    int top;
};
struct istk {
    long long dat[233];
    int top;
};
 
char tot[233], tmp;
char pre, cur;
long long cnt, head, flag = 1;
int main() {
    while(1) {
        tmp = getchar();
        if(tmp == ' ') continue;
        if(tmp == '\n') {
            tot[cnt ++] = 0;
            break;
        } else {
            tot[cnt ++] = tmp;
        }
    }
    stk tok;
    istk num;
    tok.top = -1;
    num.top = -1;
    while(1) {
        if(head + 1 == cnt) break;
        pre = cur;
        cur = tot[head ++];
        if(cur > '9' || cur < '0') {
            if(cur == '-') {
                if(pre == 0 || pre == '(' || pre == '*' || pre == '/' || pre == '^' || pre == '+' || pre == '-') {
                    tok.dat[++ tok.top] = '|';
                } else {
                    while(tok.top != -1 && tok.dat[tok.top] != '(') {
                        long long tmp1 = num.dat[num.top - 1], tmp2 = num.dat[num.top];
                        if(tok.dat[tok.top] == '+') {
                            num.dat[num.top - 1] = tmp1 + tmp2;
                            -- num.top;
                            -- tok.top;
                        } else 
                        if(tok.dat[tok.top] == '-') {
                            num.dat[num.top - 1] = tmp1 - tmp2;
                            -- num.top;
                            -- tok.top;
                        } else
                        if(tok.dat[tok.top] == '*') {
                            num.dat[num.top - 1] = tmp1 * tmp2;
                            -- num.top;
                            -- tok.top;
                        } else
                        if(tok.dat[tok.top] == '/') {
                            if(tmp2 == 0) {
                                cout << "Error" << endl;
                                return 0;
                            } else {
                                num.dat[num.top - 1] = tmp1 / tmp2;
                                -- num.top;
                                -- tok.top;
                            }
                        } else
                        if(tok.dat[tok.top] == '^') {
                            long long tmp = 1;
                            for(int i = 0;i < tmp2;++ i) {
                                if(tmp1 == 0) {
                                    tmp = 0;
                                    break;
                                } else if(tmp1 == 1) {
                                    tmp = 1;
                                    break;
                                } else if(tmp1 == -1) {
                                    if(tmp2 % 2 == 0)
                                        tmp = 1;
                                    else tmp = -1;
                                    break;
                                }
                                tmp *= tmp1;
                            }
                            num.dat[num.top - 1] = tmp;
                            -- num.top;
                            -- tok.top;
                        } else
                        if(tok.dat[tok.top] == '|') {
                            num.dat[num.top] = - num.dat[num.top];
                            -- tok.top;
                        }
                    }
                    tok.dat[++ tok.top] = '-';
                }
            } else
            if(cur == '(') {
                tok.dat[++ tok.top] = '(';
            } else
            if(cur == ')') {
                while(tok.top != -1 && tok.dat[tok.top] != '(') {
                    long long tmp1 = num.dat[num.top - 1], tmp2 = num.dat[num.top];
                    if(tok.dat[tok.top] == '+') {
                        num.dat[num.top - 1] = tmp1 + tmp2;
                        -- num.top;
                        -- tok.top;
                    } else 
                    if(tok.dat[tok.top] == '-') {
                        num.dat[num.top - 1] = tmp1 - tmp2;
                        -- num.top;
                        -- tok.top;
                    } else
                    if(tok.dat[tok.top] == '*') {
                        num.dat[num.top - 1] = tmp1 * tmp2;
                        -- num.top;
                        -- tok.top;
                    } else
                    if(tok.dat[tok.top] == '/') {
                        if(tmp2 == 0) {
                            cout << "Error" << endl;
                            return 0;
                        } else {                                
                            num.dat[num.top - 1] = tmp1 / tmp2;
                            -- num.top;
                            -- tok.top;
                        }
                    } else
                    if(tok.dat[tok.top] == '^') {
                        long long tmp = 1;
                        for(int i = 0;i < tmp2;++ i) {
                            if(tmp1 == 0) {
                                tmp = 0;
                                break;
                            } else if(tmp1 == 1) {
                                tmp = 1;
                                break;
                            } else if(tmp1 == -1) {
                                if(tmp2 % 2 == 0)
                                    tmp = 1;
                                else tmp = -1;
                                break;
                            }
                            tmp *= tmp1;
                        }
                        num.dat[num.top - 1] = tmp;
                        -- num.top;
                        -- tok.top;
                    }
                    if(tok.dat[tok.top] == '|') {
                        num.dat[num.top] = - num.dat[num.top];
                        -- tok.top;
                    }
                }
                if(tok.dat[tok.top] != '(') {
                    cout << "Error" << endl;
                    return 0;
                } else {
                    -- tok.top;
                }
            } else
            if(cur == '^') {
                while(tok.top != 1 && tok.dat[tok.top] == '|') {
                    num.dat[num.top] = - num.dat[num.top];
                    -- tok.top;
                }
                tok.dat[++ tok.top] = '^';
            } else
            if(cur == '*') {
                while(tok.top != -1 && tok.dat[tok.top] != '(' && tok.dat[tok.top] != '+' && tok.dat[tok.top] != '-') {
                    long long tmp1 = num.dat[num.top - 1], tmp2 = num.dat[num.top];
                    if(tok.dat[tok.top] == '*') {
                        num.dat[num.top - 1] = tmp1 * tmp2;
                        -- num.top;
                        -- tok.top;
                    } else
                    if(tok.dat[tok.top] == '/') {
                        if(tmp2 == 0) {
                            cout << "Error" << endl;
                            return 0;
                        } else {                                
                            num.dat[num.top - 1] = tmp1 / tmp2;
                            -- num.top;
                            -- tok.top;
                        }
                    } else
                    if(tok.dat[tok.top] == '^') {
                        long long tmp = 1;
                        for(int i = 0;i < tmp2;++ i) {
                            if(tmp1 == 0) {
                                tmp = 0;
                                break;
                            } else if(tmp1 == 1) {
                                tmp = 1;
                                break;
                            } else if(tmp1 == -1) {
                                if(tmp2 % 2 == 0)
                                    tmp = 1;
                                else tmp = -1;
                                break;
                            }
                            tmp *= tmp1;
                        }
                        num.dat[num.top - 1] = tmp;
                        -- num.top;
                        -- tok.top;
                    } else
                    if(tok.dat[tok.top] == '|') {
                        num.dat[num.top] = - num.dat[num.top];
                        -- tok.top;
                    }
                }
                tok.dat[++ tok.top] = '*';
            } else
            if(cur == '/') {
                while(tok.top != -1 && tok.dat[tok.top] != '(' && tok.dat[tok.top] != '+' && tok.dat[tok.top] != '-') {
                    long long tmp1 = num.dat[num.top - 1], tmp2 = num.dat[num.top];
                    if(tok.dat[tok.top] == '*') {
                        num.dat[num.top - 1] = tmp1 * tmp2;
                        -- num.top;
                        -- tok.top;
                    } else
                    if(tok.dat[tok.top] == '/') {
                        if(tmp2 == 0) {
                            cout << "Error" << endl;
                            return 0;
                        } else {                                
                            num.dat[num.top - 1] = tmp1 / tmp2;
                            -- num.top;
                            -- tok.top;
                        }
                    } else
                    if(tok.dat[tok.top] == '^') {
                        long long tmp = 1;
                        for(int i = 0;i < tmp2;++ i) {
                            if(tmp1 == 0) {
                                tmp = 0;
                                break;
                            } else if(tmp1 == 1) {
                                tmp = 1;
                                break;
                            } else if(tmp1 == -1) {
                                if(tmp2 % 2 == 0)
                                    tmp = 1;
                                else tmp = -1;
                                break;
                            }
                            tmp *= tmp1;
                        }
                        num.dat[num.top - 1] = tmp;
                        -- num.top;
                        -- tok.top;
                    } else
                    if(tok.dat[tok.top] == '|') {
                        num.dat[num.top] = - num.dat[num.top];
                        -- tok.top;
                    }
                }
                tok.dat[++ tok.top] = '/';
            } else
            if(cur == '+') {
                while(tok.top != -1 && tok.dat[tok.top] != '(') {
                    long long tmp1 = num.dat[num.top - 1], tmp2 = num.dat[num.top];
                    if(tok.dat[tok.top] == '+') {
                        num.dat[num.top - 1] = tmp1 + tmp2;
                        -- num.top;
                        -- tok.top;
                    } else 
                    if(tok.dat[tok.top] == '-') {
                        num.dat[num.top - 1] = tmp1 - tmp2;
                        -- num.top;
                        -- tok.top;
                    } else
                    if(tok.dat[tok.top] == '*') {
                        num.dat[num.top - 1] = tmp1 * tmp2;
                        -- num.top;
                        -- tok.top;
                    } else
                    if(tok.dat[tok.top] == '/') {
                        if(tmp2 == 0) {
                            cout << "Error" << endl;
                            return 0;
                        } else {                                
                            num.dat[num.top - 1] = tmp1 / tmp2;
                            -- num.top;
                            -- tok.top;
                        }
                    } else
                    if(tok.dat[tok.top] == '^') {
                        long long tmp = 1;
                        for(int i = 0;i < tmp2;++ i) {
                            if(tmp1 == 0) {
                                tmp = 0;
                                break;
                            } else if(tmp1 == 1) {
                                tmp = 1;
                                break;
                            } else if(tmp1 == -1) {
                                if(tmp2 % 2 == 0)
                                    tmp = 1;
                                else tmp = -1;
                                break;
                            }
                            tmp *= tmp1;
                        }
                        num.dat[num.top - 1] = tmp;
                        -- num.top;
                        -- tok.top;
                    } else
                    if(tok.dat[tok.top] == '|') {
                        num.dat[num.top] = - num.dat[num.top];
                        -- tok.top;
                    }
                }
                tok.dat[++ tok.top] = '+';
            }
        } else {
            if(pre > '9' || pre < '0')
                num.dat[++ num.top] = cur - '0';
            else {
                long long tmpi = num.dat[num.top];
                tmpi = tmpi * 10 + cur - '0';
                num.dat[num.top] = tmpi;
            }
        }
    }
    while(tok.top != -1) {
        if(tok.dat[tok.top] == '(') {
            cout << "Error" << endl;
            return 0;
        }
        long long tmp1 = num.dat[num.top - 1], tmp2 = num.dat[num.top];
        if(tok.dat[tok.top] == '+') {
            num.dat[num.top - 1] = tmp1 + tmp2;
            -- num.top;
            -- tok.top;
        } else 
        if(tok.dat[tok.top] == '-') {
            num.dat[num.top - 1] = tmp1 - tmp2;
            -- num.top;
            -- tok.top;
        } else
        if(tok.dat[tok.top] == '*') {
            num.dat[num.top - 1] = tmp1 * tmp2;
            -- num.top;
            -- tok.top;            
        } else
        if(tok.dat[tok.top] == '/') {
            if(tmp2 == 0) {
                cout << "Error" << endl;
                return 0;
            } else {                                
                num.dat[num.top - 1] = tmp1 / tmp2;
                -- num.top;
                -- tok.top;
            }
        } else
        if(tok.dat[tok.top] == '^') {
            long long tmp = 1;
            for(int i = 0;i < tmp2;++ i) {
                if(tmp1 == 0) {
                    tmp = 0;
                    break;
                } else if(tmp1 == 1) {
                    tmp = 1;
                    break;
                } else if(tmp1 == -1) {
                    if(tmp2 % 2 == 0)
                        tmp = 1;
                    else tmp = -1;
                    break;
                }
                tmp *= tmp1;
            }
            num.dat[num.top - 1] = tmp;
            -- num.top;
            -- tok.top;
        } else
        if(tok.dat[tok.top] == '|') {
            num.dat[num.top] = - num.dat[num.top];
            -- tok.top;
        }
    }
    cout << num.dat[num.top] << endl;
    //cout << "Error" << endl;
    return 0;
}