// TASK 5
// Adds two Time objects together with hour/minute/second rollover.
#include <iostream>
using namespace std;

class ClockTime
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    ClockTime() // default: midnight
    {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    ClockTime(int hour, int min, int sec)
    {
        hours = hour;
        minutes = min;
        seconds = sec;
    }

    void addTimes(ClockTime const& time1, ClockTime const& time2, ClockTime& result)
    {
        result.hours = time1.hours + time2.hours;
        result.minutes = time1.minutes + time2.minutes;
        result.seconds = time1.seconds + time2.seconds;

        // FIX: rollover should trigger at 60, not 59, otherwise a
        // legitimate value of 59 gets incorrectly carried over.
        while (result.seconds >= 60)
        {
            result.minutes++;
            result.seconds -= 60;
        }
        while (result.minutes >= 60)
        {
            result.hours++;
            result.minutes -= 60;
        }
    }

    void display(ClockTime const& time1, ClockTime const& time2) const
    {
        cout << "THE TIME OF OBJECT T1 IS :" << time1.hours << ":" << time1.minutes << ":" << time1.seconds << endl;
        cout << "THE TIME OF OBJECT T2 IS :" << time2.hours << ":" << time2.minutes << ":" << time2.seconds << endl;
        cout << "THE TIME IS :" << hours << ":" << minutes << ":" << seconds << endl;
    }
};

int main()
{
    ClockTime time1(16, 40, 15);
    ClockTime time2(6, 41, 30);
    ClockTime time3; // will hold the sum

    time3.addTimes(time1, time2, time3);
    time3.display(time1, time2);
}