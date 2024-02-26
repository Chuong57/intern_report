#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int greatest_common_divisor(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return greatest_common_divisor(b, a%b);
}


class fraction
{
private:
    int numerator;
    int denominator;

public:
    friend istream &operator >> (istream &ins, fraction &a);
    friend ostream &operator << (ostream &extr, fraction a);
    friend fraction operator + (fraction a, fraction b);
    friend fraction operator - (fraction a, fraction b);
    friend fraction operator * (fraction a, fraction b);
    friend fraction operator / (fraction a, fraction b);
//    void simplify();
    friend fraction simplify(fraction a);
};

istream &operator >> (istream &ins, fraction &a)
{
    cout << "numerator: ";
    cin >> a.numerator;
    cout << "denominator: ";
    cin >> a.denominator;
    return ins;
}

ostream &operator << (ostream &extr, fraction a)
{
    cout << a.numerator << "/" << a.denominator << endl;
    return extr;
}

fraction operator + (fraction a, fraction b)
{
    fraction sum;
    sum.numerator = (a.numerator * b.denominator) + (b.numerator * a.denominator);
    sum.denominator = a.denominator * b.denominator;
//    sum.simplify();
    return simplify(sum);
}

fraction operator - (fraction a, fraction b)
{
    fraction diff;
    diff.numerator = (a.numerator * b.denominator) - (b.numerator * a.denominator);
    diff.denominator = a.denominator * b.denominator;
    return simplify(diff);
}

fraction operator * (fraction a, fraction b)
{
    fraction multi ;
    multi.numerator = a.numerator * b.numerator;
    multi.denominator = a.denominator *b.denominator;
    return simplify(multi);
}

fraction operator / (fraction a, fraction b)
{
    fraction div;
    div.numerator = a.numerator * b.denominator;
    div.denominator = a.denominator * b.numerator;
    return simplify(div);
}

//void fraction::simplify()
//{
//    int gcd = greatest_common_divisor(numerator, denominator);
//    numerator /= gcd;
//    denominator /= gcd;
//}

fraction simplify(fraction a)
{
    int gcd = greatest_common_divisor(a.numerator, a.denominator);
    a.numerator /= gcd;
    a.denominator /= gcd;
    return a;
}

int main()
{
    fraction x, y;
    cin >> x;
    cin >> y;

    cout << endl;
    cout << "SUM = " << x + y << endl;
    cout << "DIFF = " << x - y << endl;
    cout << "MULTI = " << x * y << endl;
    cout << "DIV = " << x / y << endl;

    return 0;
}
