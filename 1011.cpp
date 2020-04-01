/**
 * 复数类
 **/
#include <iostream>
#include <iomanip>
using namespace std;

class MyComplex
{
private:
    double x,y;
public:
    friend istream& operator>>(istream &in, MyComplex &obj);
    friend ostream& operator<<(ostream &os, const MyComplex &obj);
    friend MyComplex operator+(const MyComplex &i1, const MyComplex &i2);
    friend MyComplex operator-(const MyComplex &i1, const MyComplex &i2);
    friend MyComplex operator*(const MyComplex &i1, const MyComplex &i2);
    friend MyComplex operator/(const MyComplex &i1, const MyComplex &i2);
    friend MyComplex operator+=(MyComplex &i1, const MyComplex &i2);
    friend MyComplex operator-=(MyComplex &i1, const MyComplex &i2);
    friend MyComplex operator*=(MyComplex &i1, const MyComplex &i2);
    friend MyComplex operator/=(MyComplex &i1, const MyComplex &i2);
};

istream& operator>>(istream &in, MyComplex &obj) {
    in >> obj.x >> obj.y;
    return in;
}

ostream& operator<<(ostream &os, const MyComplex &obj) {
    os << fixed << setprecision(2) << obj.x << " " << obj.y;
    return os;
}

MyComplex operator+(const MyComplex &i1, const MyComplex &i2) {
    MyComplex tmp;
    tmp.x = i1.x + i2.x;
    tmp.y = i1.y + i2.y;
    return tmp;
}

MyComplex operator-(const MyComplex &i1, const MyComplex &i2) {
    MyComplex tmp;
    tmp.x = i1.x - i2.x;
    tmp.y = i1.y - i2.y;
    return tmp;
}

MyComplex operator*(const MyComplex &i1, const MyComplex &i2) {
    MyComplex tmp;
    tmp.x = i1.x * i2.x - i1.y * i2.y;
    tmp.y = i1.x * i2.y + i1.y * i2.x;
    return tmp;
}

MyComplex operator/(const MyComplex &i1, const MyComplex &i2) {
    MyComplex tmp;
    int t = i2.x * i2.x + i2.y * i2.y;
    tmp.x = (i1.x * i2.x + i1.y * i2.y) / t;
    tmp.y = (i1.y * i2.x - i1.x * i2.y) / t;
    return tmp;
}

MyComplex operator+=(MyComplex &i1, const MyComplex &i2) {
    i1 = i1 + i2;
    return i1;
}

MyComplex operator-=(MyComplex &i1, const MyComplex &i2) {
    i1 = i1 - i2;
    return i1;
}

MyComplex operator*=(MyComplex &i1, const MyComplex &i2) {
    i1 = i1 * i2;
    return i1;
}

MyComplex operator/=(MyComplex &i1, const MyComplex &i2) {
    i1 = i1 / i2;
    return i1;
}

int main()
{
    MyComplex z1;
    MyComplex z2;

    cin >> z1 >> z2;

    cout << z1 + z2 <<endl;
    cout << z1 - z2 <<endl;
    cout << z1 * z2 <<endl;
    cout << z1 / z2 <<endl;
    cout << (z1 += z2) <<endl;
    cout << (z1 -= z2) <<endl;
    cout << (z1 *= z2) <<endl;
    cout << (z1 /= z2) <<endl;

    return 0;
}