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

    RationalNumber operator+(RationalNumber);
    RationalNumber operator-(RationalNumber);
    RationalNumber operator*(RationalNumber);
    RationalNumber operator/(RationalNumber);
    bool operator>(RationalNumber);
    bool operator<(RationalNumber);
    bool operator>=(RationalNumber);
    bool operator<=(RationalNumber);
    bool operator==(RationalNumber);
    bool operator!=(RationalNumber);
    void getRN();
    void showRN();
};

RationalNumber RationalNumber::operator+(RationalNumber b)
{
    RationalNumber temp;
    temp.numerator = (numerator * b.denominator) + (denominator * b.numerator);
    temp.denominator = denominator * b.denominator;

    return temp;
}

RationalNumber RationalNumber ::operator-(RationalNumber b)
{
    RationalNumber temp;
    temp.numerator = (numerator * b.denominator) - (denominator * b.numerator);
    temp.denominator = denominator * b.denominator;

    return temp;
}

RationalNumber RationalNumber ::operator*(RationalNumber b)
{
    RationalNumber temp;
    temp.numerator = numerator * b.numerator;
    temp.denominator = denominator * b.denominator;

    return temp;
}

RationalNumber RationalNumber::operator/(RationalNumber b)
{
    RationalNumber temp;
    temp.numerator = numerator * b.denominator;
    temp.denominator = denominator * b.numerator;

    return temp;
}

bool RationalNumber::operator>(RationalNumber b)
{
    bool isGreater;
    float firstnum = numerator / denominator;
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

bool RationalNumber::operator<(RationalNumber b)
{
    bool isSmaller;
    float firstnum = numerator / denominator;
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

bool RationalNumber::operator>=(RationalNumber b)
{
    bool isGreaterEqual;
    float firstnum = numerator / denominator;
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

bool RationalNumber::operator<=(RationalNumber b)
{
    bool isSmallerEqual;
    float firstnum = numerator / denominator;
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

bool RationalNumber::operator==(RationalNumber b)
{
    bool isEqual;
    float firstnum = numerator / denominator;
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

bool RationalNumber::operator!=(RationalNumber b)
{
    bool isNotEqual;
    float firstnum = numerator / denominator;
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
    RationalNumber r1, r2;
    r1.getRN();
    r2.getRN();

    RationalNumber r3 = r1 + r2;
    r3.showRN();

    bool isGreater = r1 > r2;
    if (isGreater)
    {
        cout << "R1 is greater than r2" << endl;
    }
    else
    {
        cout << "R1 is less than r2" << endl;
    }
}