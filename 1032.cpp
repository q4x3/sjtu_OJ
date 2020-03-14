#include <iostream>

using namespace std;

long long ackerman(int m, int n)
{
    if (! m) return n + 1;
    else if(! n) return ackerman(m - 1, 1);
    else return ackerman(m - 1, ackerman(m, n - 1));
}

int main()
{
    int m, n;
    cin >> m >> n;
    cout << ackerman(m, n) << endl;
}