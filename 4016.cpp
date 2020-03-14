#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int a[4];
    for(int i = 0;i < N;++ i) {
        int ans = 0;
        cin >> a[0] >> a[1] >> a[2] >> a[3];
        for(int i = 0;i < 4;++ i)
            for(int j = 0;j < 4 && j != i;++ j) {
                int tmp1[5] = {0};
                tmp1[0] = a[i] + a[j];
                tmp1[1] = a[i] - a[j];
                tmp1[2] = a[j] - a[i];
                tmp1[3] = a[i] * a[j];
                if(a[i] % a[j] == 0) tmp1[4] = a[i] / a[j];
                if(a[j] % a[i] == 0) tmp1[4] = a[j] / a[i];
                for(int k = 0;k < 5;++ k)
                    for(int p = 0;p < 4 && p != i && p != j;++ p) {
                        int tmp2[5] = {0};
                        tmp2[0] = tmp1[k] + a[p];
                        tmp2[1] = tmp1[k] - a[p];
                        tmp2[2] = a[p] - tmp1[k];
                        tmp2[3] = tmp1[k] * a[p];
                        if(a[p] != 0 && tmp1[k] % a[p] == 0) tmp2[4] = tmp1[k] / a[p];
                        if(tmp1[k] != 0 && a[p] % tmp1[k] == 0) tmp2[4] = a[p] / tmp1[k];
                        for(int t = 0;t < 5;++ t)
                            for(int q = 0;q < 4;++ q) {
                                
                            }
                    }
            }
        }
}