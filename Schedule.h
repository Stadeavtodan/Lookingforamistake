#pragma once
#include <iostream>
#include <ctime>
#include "Time_.h"
using namespace std;

class Schedule{
private:
    Time_ startTime;
    int lessonDuration;
    int shortBreak;
    int longBreak;
    int longBreakAfter;
    int totalLessons;

public:
    Schedule(Time_ start, int lessonDur, int shortBr, int longBr, int longAfter, int lessons);

    void generateSchedule()const;
};