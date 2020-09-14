/**
 * 数学题
 * 横线竖线中较多的那一个
 **/
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int n, a, b, x1, y1, x2, y2, tmp1, tmp2, tmp3, tmp4;
    cin >> n;
    for(int i = 0;i < n;++ i) {
        cin >> a >> b >> x1 >> y1 >> x2 >> y2;
        tmp1 = (x1 - y1) / (2 * b);
        tmp2 = (x2 - y2) / (2 * b);
        tmp3 = (x1 + y1) / (2 * a);
        tmp4 = (x2 + y2) / (2 * a);
        if(x1 - y1 < 0) -- tmp1;
        if(x2 - y2 < 0) -- tmp2;
        if(x1 + y1 < 0) -- tmp3;
        if(x2 + y2 < 0) -- tmp4;
        if(abs(tmp1 - tmp2) > abs(tmp3 - tmp4)) cout << abs(tmp1 - tmp2) << endl;
        else cout <<  abs(tmp3 - tmp4) << endl;
    }
}