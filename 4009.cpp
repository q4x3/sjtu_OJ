/**
 * 模拟
 * 别忘了No Solution
 **/
#include <iostream>
#include <cstring>
using namespace std;

char s[105], ans[105], tmp[105];
int a;
bool flag = 0;

int main() {
    cin >> s;
    cin >> ans;
    for(int i = 2;i < strlen(s);++ i) {
        if(strlen(s) % i != 0) continue;
        a = i;
        for(int j = 0;j < strlen(s) / a;++ j) {
            for(int k = 0;k < a;++ k) {
                tmp[j + k * strlen(s) / a] = s[j * a + k];
            }
        }
        if(strcmp(tmp, ans) == 0) {
            flag = 1;
            break;
        }
    }
    if(flag) cout << a << endl;
    else cout << "No Solution" << endl;
    return 0;
}