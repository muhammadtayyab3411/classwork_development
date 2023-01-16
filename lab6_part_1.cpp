#include <iostream>
using namespace std;

class RationalNumber
{
    int numerator, denominator;

public:
    RationalNumber()
    {
        numerator = 0;
        denominator = 0;
    }

    RationalNumber(int n, int d)
    {
        numerator = n;
        if (d != 0)
        {
            denominator = abs(d);
        }
    }

    friend RationalNumber operator+(RationalNumber, RationalNumber);
    friend RationalNumber operator-(RationalNumber, RationalNumber);
    friend RationalNumber operator*(RationalNumber, RationalNumber);
    friend RationalNumber operator/(RationalNumber, RationalNumber);
    friend bool operator>(RationalNumber, RationalNumber);
    friend bool operator<(RationalNumber, RationalNumber);
    friend bool operator>=(RationalNumber, RationalNumber);
    friend bool operator<=(RationalNumber, RationalNumber);
    friend bool operator==(RationalNumber, RationalNumber);
    friend bool operator!=(RationalNumber, RationalNumber);
    void getRN();
    void showRN();
};

RationalNumber operator+(RationalNumber a, RationalNumber b)
{
    RationalNumber temp;
    temp.numerator = (a.numerator * b.denominator) + (a.denominator * b.numerator);
    temp.denominator = a.denominator * b.denominator;

    return temp;
}

RationalNumber operator-(RationalNumber a, RationalNumber b)
{
    RationalNumber temp;
    temp.numerator = (a.numerator * b.denominator) - (a.denominator * b.numerator);
    temp.denominator = a.denominator * b.denominator;

    return temp;
}

RationalNumber operator*(RationalNumber a, RationalNumber b)
{
    RationalNumber temp;
    temp.numerator = a.numerator * b.numerator;
    temp.denominator = a.denominator * b.denominator;

    return temp;
}

RationalNumber operator/(RationalNumber a, RationalNumber b)
{
    RationalNumber temp;
    temp.numerator = a.numerator * b.denominator;
    temp.denominator = a.denominator * b.numerator;

    return temp;
}

bool operator>(RationalNumber a, RationalNumber b)
{
    bool isGreater;
    float firstnum = a.numerator / a.denominator;
    float secondnum = b.numerator / b.denominator;

    if (firstnum > secondnum)
    {
        isGreater = true;
    }
    else
    {
        isGreater = false;
    }

    return isGreater;
}

bool operator<(RationalNumber a, RationalNumber b)
{
    bool isSmaller;
    float firstnum = a.numerator / a.denominator;
    float secondnum = b.numerator / b.denominator;

    if (firstnum < secondnum)
    {
        isSmaller = true;
    }
    else
    {
        isSmaller = false;
    }

    return isSmaller;
}

bool operator>=(RationalNumber a, RationalNumber b)
{
    bool isGreaterEqual;
    float firstnum = a.numerator / a.denominator;
    float secondnum = b.numerator / b.denominator;

    if (firstnum >= secondnum)
    {
        isGreaterEqual = true;
    }
    else
    {
        isGreaterEqual = false;
    }

    return isGreaterEqual;
}

bool operator<=(RationalNumber a, RationalNumber b)
{
    bool isSmallerEqual;
    float firstnum = a.numerator / a.denominator;
    float secondnum = b.numerator / b.denominator;

    if (firstnum <= secondnum)
    {
        isSmallerEqual = true;
    }
    else
    {
        isSmallerEqual = false;
    }

    return isSmallerEqual;
}

bool operator==(RationalNumber a, RationalNumber b)
{
    bool isEqual;
    float firstnum = a.numerator / a.denominator;
    float secondnum = b.numerator / b.denominator;

    if (firstnum == secondnum)
    {
        isEqual = true;
    }
    else
    {
        isEqual = false;
    }

    return isEqual;
}

bool operator!=(RationalNumber a, RationalNumber b)
{
    bool isNotEqual;
    float firstnum = a.numerator / a.denominator;
    float secondnum = b.numerator / b.denominator;

    if (firstnum == secondnum)
    {
        isNotEqual = false;
    }
    else
    {
        isNotEqual = true;
    }

    return isNotEqual;
}

void RationalNumber::getRN()
{
    cout << "Enter the numerator : ";
    cin >> numerator;
    cout << "Enter the denominator : ";
    cin >> denominator;
}

void RationalNumber::showRN()
{
    cout << numerator << " / " << denominator << endl;
}

int main()
{
    RationalNumber r1(3, 4), r2(6, 4);

    r1.showRN();
    r2.showRN();

    const bool isGreater = r1 > r2;
    cout << isGreater << endl;
}