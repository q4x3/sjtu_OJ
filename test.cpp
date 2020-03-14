#include <iostream>
#include <algorithm>
using namespace std;
void bubblesort1A(int*, int);
int countOnes(int);
int sumI(int*, int);
int sum(int*, int);
int hailstone(int);
void reverse(int*, int, int);
void reverse(int*, int);
inline long long sqr(long long a) {return a * a;}
long long power2(int);

int main ()
{
    int a[] = {3,6,2,3,3,87,1354,45};
    bubblesort1A(a, 8);
    for (int i = 0;i < 8;++ i)
        cout << a[i] << " "
        << countOnes(a[i]) << " "
        << hailstone(a[i]) << endl;
    cout << "sum: " << sum(a, 8) << endl;
    reverse(a, 8);
    reverse(a, 0, 7);
    for (int i = 0;i < 8;++ i)
        cout << a[i] << " "
        << power2(a[i]) << endl;
    return 0;
}

//time:O(n^2)
void bubblesort1A(int A[], int n)
{
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 1;i < n;++ i) {
            if (A[i - 1] > A[i]) {
                swap(A[i - 1], A[i]);
                sorted = false;
            }
        }
        -- n;
    }
}

//time:O(logn)
int countOnes(int n)
{
    int ones = 0;
    while (0 < n) {
        ones += (1 & n);
        n >>= 1;
    }
    return ones;
}

//time:O(n)
int sumI(int A[], int n)
{
    int sum = 0;
    for (int i = 0;i < n;++ i)
        sum += A[i];
    return sum;
}

//time:O(n)
int sum(int A[], int n)
{
    if (1 > n)
        return 0;
    else
        return sum(A, n - 1) + A[n - 1];
}

int hailstone(int n)
{
    int length = 1;
    while (1 < n) {
        n % 2 ? n = 3 * n + 1 : n /= 2;
        ++ length;
    }
    return length;
}

void reverse(int* A, int lo, int hi)
{
    if (lo < hi) {
        swap (A[lo], A[hi]);
        reverse (A, lo + 1, hi - 1);
    }
}

void reverse(int* A, int n)
{
    reverse(A, 0, n - 1);
}

long long power2(int n)
{
    if (0 == n) return 1;
    return (n & 1) ? sqr(power2(n >> 1)) << 1 : sqr(power2(n >> 1));
}