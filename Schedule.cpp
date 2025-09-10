//
// Created by admin on 09.09.2025.
//

#include "Schedule.h"

Schedule::Schedule(Time_ start, int lessonDur, int shortBr, int longBr, int longAfter, int lessons) {
    this -> startTime = start;
    this -> lessonDuration = lessonDur;
    this -> shortBreak = shortBr;
    this -> longBreak = longBr;
    this -> longBreakAfter = longAfter;
    this -> totalLessons = lessons;
}

void Schedule::generateSchedule() const {
    Time_ currentTime = startTime;

    for(int i = 1; i <= totalLessons; i++){
        Time_ lessonStart = currentTime;
        Time_ lessonEnd = currentTime + lessonDuration;
        cout << i << ". ";
        lessonStart.showTime();
        cout << " - ";
        lessonEnd.showTime();
        cout << endl;

        currentTime = lessonEnd;

        if(i < totalLessons){
            if(i == longBreakAfter){
                currentTime += longBreak;
                cout << " break " << longBreak << " min" << endl;
            }else{
                currentTime += shortBreak;
                cout << " break " << shortBreak << " min" << endl;
            }
        }
    }
}