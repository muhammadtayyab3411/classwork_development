#include <iostream>
using namespace std;

class Time
{
    int hours, minutes, seconds;

public:
    Time()
    {
        hours = minutes = seconds = 0;
    }
    Time(int h, int m, int s)
    {
        hours = h;
        minutes = m;
        seconds = s;
    }

    void getTime()
    {
        cout << "Enter the hours : ";
        cin >> hours;
        cout << "Enter the minutes : ";
        cin >> minutes;
        cout << "Enter the seconds : ";
        cin >> seconds;
    }

    void showTime()
    {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }

    friend Time operator+(Time, Time);
    // pre-increment
    friend Time operator++(Time);
    friend Time operator--(Time);
    // post-increment
    friend Time operator++(Time, int);
    friend Time operator--(Time, int);
};

Time operator+(Time a, Time b)
{
    Time temp;
    temp.hours = a.hours + b.hours;
    temp.minutes = a.minutes + b.minutes;
    temp.seconds = a.seconds + b.seconds;

    if (temp.minutes >= 60)
    {
        int extraMinutes = temp.minutes / 60;
        temp.minutes = temp.minutes - (60 * extraMinutes);
        temp.hours = temp.hours + extraMinutes;
    }
    if (temp.seconds >= 60)
    {
        int extraSeconds = temp.seconds / 60;
        temp.seconds = temp.seconds - (60 * extraSeconds);
        temp.minutes = temp.minutes + extraSeconds;
    }

    return temp;
}

Time operator++(Time a)
{
    a.seconds = a.seconds + 1;
    if (a.seconds >= 60)
    {
        a.seconds = 0;
        a.minutes = a.minutes + 1;
    }
    if (a.minutes >= 60)
    {
        a.minutes = 0;
        a.hours = a.hours + 1;
    }

    return a;
}

Time operator--(Time a)
{
    a.seconds = a.seconds - 1;
    if (a.seconds < 0)
    {
        a.seconds = 60;
        a.minutes = a.minutes - 1;
    }
    if (a.minutes < 0)
    {
        a.minutes = 60;
        a.hours = a.hours - 1;
    }
    if (a.hours < 0)
    {
        a.hours = 0;
    }

    return a;
}

Time operator++(Time a, int)
{
    a.seconds = a.seconds + 1;
    if (a.seconds >= 60)
    {
        a.seconds = 0;
        a.minutes = a.minutes + 1;
    }
    if (a.minutes >= 60)
    {
        a.minutes = 0;
        a.hours = a.hours + 1;
    }

    return a;
}

Time operator--(Time a, int)
{
    a.seconds = a.seconds - 1;
    if (a.seconds < 0)
    {
        a.seconds = 60;
        a.minutes = a.minutes - 1;
    }
    if (a.minutes < 0)
    {
        a.minutes = 60;
        a.hours = a.hours - 1;
    }
    if (a.hours < 0)
    {
        a.hours = 0;
    }

    return a;
}

int main()
{
    Time t1, t2(22, 10, 44);
    t1.getTime();

    Time t3 = t1 + t2;

    t3.showTime();
}