#pragma once
#include <iostream>
#include <ctime>
using namespace std;

class Time_
{
    int hour;
    int minutes;
    int seconds;
    bool format; // true = utc (24-hours), false = am/pm (12-hours),

public:
    Time_(); // current local time
    Time_(int hour, int minutes, int seconds, bool format = true);
    Time_(const Time_& obj); //Визначити: чи потрібен Конструктор Копіювання?
    Time_& operator = (const Time_& obj); // Визначити: чи потрібен Оператор Присвоювання?

    ~Time_(); // Визначити: чи потрібен Деструктор?

    void setHour(int hour);
    int gerHour()const;
    void setMinutes(int minutes);
    int getMinutes()const;
    void setSeconds(int seconds);
    int getSeconds()const;
    void setFormat(bool format);
    bool getFormat()const;

    bool valid()const; //time check
    void tickTime(); //every tick add one second
    void untickTime(); //every tick remove one second
    void showTime()const; //show time by the format

//--------- Comparison operators ---------
    bool operator == (const Time_& obj)const&;
    bool operator != (const Time_& obj)const&;
    bool operator > (const Time_& obj)const&;
    bool operator < (const Time_& obj)const&;
    bool operator >= (const Time_& obj)const&;
    bool operator <= (const Time_& obj)const&;

    //--------- Assignment operators ---------
    Time_& operator += (float s); // add seconds
    Time_& operator -= (float s);
    Time_& operator += (int m); // add minutes
    Time_& operator -= (int m);
    Time_& operator += (long h); // add hours
    Time_& operator -= (long h);


    //--------- Arithmetic operators ---------
    Time_ operator + (float s)const&; // add seconds
    Time_ operator - (float s)const&;
    Time_ operator + (int m)const&; // add minutes
    Time_ operator - (int m)const&;
    Time_ operator + (long h)const&; // add hours
    Time_ operator - (long h)const&;
};