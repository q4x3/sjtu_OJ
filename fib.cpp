#include <iostream>
#include <vector>
using namespace std;

int fib(int n, int& prev) {
    if (0 == n) {
        prev = 1; return 0;
    }
    else {
        int prevPrev; prev = fib(n - 1, prevPrev);
        return prevPrev + prev;
    }
}

int main()
{
    int tmp;
    cout << fib(13, tmp) << endl;
}