#include <iostream>
using namespace std;

class Distance
{
    int feets, inches;

public:
    Distance()
    {
        feets = 0;
        inches = 0;
    }

    Distance(int input_feet, int input_inches)
    {
        feets = input_feet;
        inches = input_inches;
    }

    void getDistance();
    void showDistance();
    Distance operator+(Distance);
    Distance operator+=(Distance);
    bool operator>(Distance);
    bool operator<(Distance);
    bool operator>=(Distance);
    bool operator<=(Distance);
    bool operator==(Distance);
    bool operator!=(Distance);
    void operator++();
    void operator++(int);
    void operator--();
    void operator--(int);
};

void Distance::getDistance()
{
    cout << "Enter the values (feets) : ";
    cin >> feets;
    cout << "Enter the values (inches) : ";
    cin >> inches;
}

void Distance::showDistance()
{
    cout << "Feets : " << feets << endl
         << "Inches : " << inches << endl;
}

Distance Distance::operator+(Distance d)
{
    Distance temp;
    temp.feets = feets + d.feets;
    temp.inches = inches + d.inches;

    if (temp.inches >= 12)
    {
        temp.feets++;
        temp.inches = temp.inches - 12;
    }
    return temp;
}

Distance Distance::operator+=(Distance d)
{
    Distance temp;
    temp.feets = feets + d.feets;
    temp.inches = inches + d.inches;
    cout << "inches: " << inches << "d inches : " << d.inches << endl;

    if (temp.inches >= 12)
    {
        temp.feets++;
        temp.inches = temp.inches - 12;
    }

    return temp;
}

bool Distance ::operator>(Distance d)
{
    bool isGreater;
    if (feets > d.feets)
    {
        isGreater = true;
    }
    else if (feets < d.feets)
    {
        isGreater = false;
    }
    else if (feets == d.feets)
    {
        if (inches > d.inches)
        {
            isGreater = true;
        }
        else
        {
            isGreater = false;
        }
    }

    return isGreater;
}

bool Distance ::operator<(Distance d)
{
    bool isLess;
    if (feets < d.feets)
    {
        isLess = true;
    }
    else if (feets > d.feets)
    {
        isLess = false;
    }
    else if (feets == d.feets)
    {
        if (inches < d.inches)
        {
            isLess = true;
        }
        else
        {
            isLess = false;
        }
    }

    return isLess;
}

bool Distance ::operator>=(Distance d)
{
    bool isGreaterOrEqual;
    if (feets > d.feets)
    {
        isGreaterOrEqual = true;
    }
    else if (feets < d.feets)
    {
        isGreaterOrEqual = false;
    }
    else if (feets == d.feets)
    {
        if (inches > d.inches)
        {
            isGreaterOrEqual = true;
        }
        else if (inches < d.inches)
        {
            isGreaterOrEqual = false;
        }
        else if (inches == d.inches)
        {
            isGreaterOrEqual = true;
        }
    }

    return isGreaterOrEqual;
}

bool Distance ::operator<=(Distance d)
{
    bool isLessOrEqual;
    if (feets < d.feets)
    {
        isLessOrEqual = true;
    }
    else if (feets > d.feets)
    {
        isLessOrEqual = false;
    }
    else if (feets == d.feets)
    {
        if (inches < d.inches)
        {
            isLessOrEqual = true;
        }
        else if (inches > d.inches)
        {
            isLessOrEqual = false;
        }
        else if (inches == d.inches)
        {
            isLessOrEqual = true;
        }
    }

    return isLessOrEqual;
}

bool Distance::operator==(Distance d)
{
    bool isEqual;
    if (feets == d.feets && inches == d.inches)
    {
        isEqual = true;
    }
    else
    {
        isEqual = false;
    }

    return isEqual;
}

bool Distance::operator!=(Distance d)
{
    bool isNotEqual;
    if (feets == d.feets && inches == d.inches)
    {
        isNotEqual = false;
    }
    else
    {
        isNotEqual = true;
    }

    return isNotEqual;
}

void Distance::operator++()
{
    ++inches;
    if (inches >= 12)
    {
        ++feets;
        inches = inches - 12;
    }
}

void Distance::operator++(int)
{
    inches++;
    if (inches >= 12)
    {
        ++feets;
        inches = inches - 12;
    }
}

void Distance::operator--()
{
    if (inches > 0)
    {
        --inches;
    }
    else
    {
        if (feets > 0)
        {
            --feets;
            inches = 11;
        }
    }
}

void Distance::operator--(int)
{
    if (inches > 0)
    {
        --inches;
    }
    else
    {
        if (feets > 0)
        {
            --feets;
            inches = 11;
        }
    }
}

int main()
{
    Distance d1, d2;
    d1.getDistance();
    d2.getDistance();
    d1.showDistance();
    d2.showDistance();

    Distance d3 = d1 + d2;
    d3.showDistance();

    if (d1 > d2)
    {
        cout << "d1 is greater than d2" << endl;
    }

    if (d1 < d2)
    {
        cout << "d1 is less than d2" << endl;
    }

    if (d1 >= d2)
    {
        cout << "d1 is greater than or equal to d2" << endl;
    }

    if (d1 <= d2)
    {
        cout << "d1 is less than or equal to d2" << endl;
    }

    if (d1 == d2)
    {
        cout << "d1 is equal to d2" << endl;
    }

    if (d1 != d2)
    {
        cout << "d1 is not equal to d2" << endl;
    }

    ++d2;
    d2.showDistance();

    d1--;
    d1.showDistance();
}