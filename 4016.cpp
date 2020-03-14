#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int a[4];
    for(int n = 0;n < N;++ n) {
        int ans = 0;
        cin >> a[0] >> a[1] >> a[2] >> a[3];
        for(int i = 0;i < 4;++ i)
            for(int j = 0;j < 4;++ j) {
                if(j == i) continue;
                int tmp1[5] = {0};
                tmp1[0] = a[i] + a[j];
                tmp1[1] = a[i] - a[j];
                tmp1[2] = a[j] - a[i];
                tmp1[3] = a[i] * a[j];
                if(a[i] % a[j] == 0) tmp1[4] = a[i] / a[j];
                if(a[j] % a[i] == 0) tmp1[4] = a[j] / a[i];
                for(int k = 0;k < 4 + 1 * (tmp1[4] != 0);++ k)
                    for(int p = 0;p < 4;++ p) {
                        if((p == i)||(p == j)) continue;
                        int tmp2[5] = {0};
                        tmp2[0] = tmp1[k] + a[p];
                        tmp2[1] = tmp1[k] - a[p];
                        tmp2[2] = a[p] - tmp1[k];
                        tmp2[3] = tmp1[k] * a[p];
                        if(a[p] != 0 && tmp1[k] % a[p] == 0) tmp2[4] = tmp1[k] / a[p];
                        if(tmp1[k] != 0 && a[p] % tmp1[k] == 0) tmp2[4] = a[p] / tmp1[k];
                        for(int t = 0;t < 4 + 1 * (tmp2[4] != 0);++ t)
                            for(int q = 0;q < 4;++ q) {
                                if((q == i)||(q == j)||(q == p)) continue;
                                int tmp3[5] = {0};
                                tmp3[0] = tmp2[t] + a[q];
                                tmp3[1] = tmp2[t] - a[q];
                                tmp3[2] = a[q] - tmp2[t];
                                tmp3[3] = tmp2[t] * a[q];
                                if(a[q] != 0 && tmp2[t] % a[q] == 0) tmp3[4] = tmp2[t] / a[q];
                                if(tmp2[t] != 0 && a[q] % tmp2[t] == 0) tmp3[4] = a[q] / tmp2[t];
                                for(int b = 0;b < 5;++ b)
                                    if(tmp3[b] <= 24 && ans < tmp3[b]) ans = tmp3[b];
                            }
                    }
                for(int c = 0;c < 4;++ c) {
                    if((c == i)||(c == j)) continue;
                    for(int d = 0;d < 4;++ d) {
                        if((d == i)||(d == j)||(d == c)) continue;
                        int tmp4[5] = {0};
                        tmp4[0] = a[c] + a[d];
                        tmp4[1] = a[c] - a[d];
                        tmp4[2] = a[d] - a[c];
                        tmp4[3] = a[c] * a[d];
                        if(a[c] % a[d] == 0) tmp4[4] = a[c] / a[d];
                        if(a[d] % a[c] == 0) tmp4[4] = a[d] / a[c];
                        for(int e = 0;e < 4 + 1 * (tmp4[4] != 0);++ e)
                            for(int f = 0;f < 4 + 1 * (tmp1[4] != 0);++ f) {
                                int tmp5[5];
                                tmp5[0] = tmp4[e] + tmp1[f];
                                tmp5[1] = tmp4[e] - tmp1[f];
                                tmp5[2] = tmp1[f] - tmp4[e];
                                tmp5[3] = tmp4[e] * tmp1[f];
                                if(tmp4[e] != 0 && tmp1[f] % tmp4[e] == 0) tmp5[4] = tmp1[f] / tmp4[e];
                                if(tmp1[f] != 0 && tmp4[e] % tmp1[f] == 0) tmp5[4] = tmp4[e] / tmp1[f];
                                for(int g = 0;g < 5;++ g)
                                    if(tmp5[g] <= 24 && ans < tmp5[g]) ans = tmp5[g];
                            }
                    }
                }
            }
            cout << ans << endl;
        }
}