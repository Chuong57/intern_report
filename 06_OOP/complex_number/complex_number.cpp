#include <iostream>
using namespace std;

class complex_number
{
private:
    int real;
    int imaginary;

public:
    friend complex_number operator + (complex_number a, complex_number b);
    friend complex_number operator - (complex_number a, complex_number b);
    friend ostream &operator << (ostream &out, complex_number a);
    friend istream &operator >> (istream &in, complex_number &a);
    bool operator == (complex_number another);
};

istream &operator >> (istream &in, complex_number &a)
{
    cout << "\nReal part: ";
    cin >> a.real;
    cout << "Imaginary part: ";
    cin >> a.imaginary;
    return in;
}

ostream &operator << (ostream &out, complex_number a)
{
    cout << a.real << " + " << a.imaginary << "i" << endl;
    return out;
}

complex_number operator + (complex_number a, complex_number b)
{
    complex_number sum;
    sum.real = a.real + b.real;
    sum.imaginary = a.imaginary + b.imaginary;
    return sum;
}

complex_number operator - (complex_number a, complex_number b)
{
    complex_number diff;
    diff.real = a.real - b.real;
    diff.imaginary = a.imaginary - b.imaginary;
    return diff;
}

bool complex_number::operator == (complex_number another)
{
    if ((this->real == another.real) && (this->imaginary == another.imaginary))
    {
        return true;
    }
    return false;
}

int main()
{
    complex_number x, y;
    cin >> x;
    cin >> y;

    cout << "\nSUM: " << x + y << endl;
    cout << "DIFF: " << x - y << endl;
    if (x == y)
    {
        cout << "2 complex numbers are equal\n";
    }
    else
    {
        cout << "2 complex number are unequal\n";
    }
    return 0;
}
