//
// Created by admin on 07.09.2025.
//

#include "Time_.h"

Time_::Time_() {
    time_t pc_time = time(nullptr);
    tm* obj = localtime(&pc_time);

    hour = obj -> tm_hour;
    minutes = obj -> tm_min;
    seconds = obj -> tm_sec;
    format = true;
}

Time_::Time_(int hour, int minutes, int seconds, bool format) {
    this -> hour = hour;
    this -> minutes = minutes;
    this -> seconds = seconds;
    this -> format = format;

    if (!format) {
        if (hour == 0) {
            this -> hour = 12; // північ
        } else if (hour > 12) {
            this -> hour -= 12; // 13 → 1, 14 → 2, ..., 23 → 11
        }
    }

}

Time_::Time_(const Time_ &obj) {
    hour = obj.hour;
    minutes = obj.minutes;
    seconds = obj.seconds;
    format = obj.format;
}

Time_ &Time_::operator=(const Time_ &obj) {
    if(this != &obj){
        hour = obj.hour;
        minutes = obj.minutes;
        seconds = obj.seconds;
        format = obj.format;
    }
    return *this;
}

Time_::~Time_() {
    // не потрібно бо немає ніякої змінної яка має динамічну пам'ять
}

void Time_::setHour(int hour) {
    if(hour >= 0 && hour <= 23){
        this -> hour = hour;
    }
}

int Time_::getHour() const {
    return hour;
}

void Time_::setMinutes(int minutes) {
    if(minutes >= 0 && minutes <= 59){
        this -> minutes = minutes;
    }
}

int Time_::getMinutes() const {
    return minutes;
}

void Time_::setSeconds(int seconds) {
    if(seconds >= 0 && seconds <= 59){
        this -> seconds = seconds;
    }
}

int Time_::getSeconds() const {
    return seconds;
}

void Time_::setFormat(bool format) {
    this -> format = format;

    if (!format) {
        if (hour == 0) {
            this -> hour = 12; // північ
        } else if (hour > 12) {
            this -> hour -= 12; // 13 → 1, 14 → 2, ..., 23 → 11
        }
    }
}

bool Time_::getFormat() const {
    return format;
}

bool Time_::valid() const {
    if(format){
        return true;
    } else {
        return false;
    }
}

void Time_::tickTime() {
    seconds++;
    if(seconds >= 60){
        seconds = 0;
        minutes++;
    }

    if(minutes >= 60){
        minutes = 0;
        hour++;
    }

    if(format){
        if(hour >= 24){
            hour = 0;
        }
    }else{
        if(hour > 12){
            hour = 1;
        }
    }
}

void Time_::untickTime() {
    seconds--;
    if(seconds == -1){
        seconds = 59;
        minutes--;
    }

    if(minutes == -1){
        minutes = 59;
        hour--;
    }
    if(format){
        if(hour == -1){
            hour = 23;
        }
    }else{
        if(hour == -1){
            hour = 11;
        }else if(hour == 0){
            hour = 12;
        }
    }
}

void Time_::showTime() const {
    cout << (hour < 10 ? "0" : "") << hour << ":"
         << (minutes < 10 ? "0" : "") << minutes << ":"
         << (seconds < 10 ? "0" : "") << seconds;
}

//--------- Comparison operators ---------
bool Time_::operator==(const Time_ &obj) const &{
    if(this -> hour == obj.hour && this -> minutes == obj.minutes && this -> seconds == obj.seconds)
        return true;
    else
        return false;
}

bool Time_::operator!=(const Time_ &obj) const &{
    return  !(*this == obj);
}

bool Time_::operator>(const Time_ &obj) const &{
    if (hour != obj.hour) return hour > obj.hour;
    if (minutes != obj.minutes) return minutes > obj.minutes;
    return seconds > obj.seconds;
}

bool Time_::operator<(const Time_ &obj) const &{
    if (hour != obj.hour) return hour < obj.hour;
    if (minutes != obj.minutes) return minutes < obj.minutes;
    return seconds < obj.seconds;
}

bool Time_::operator>=(const Time_ &obj) const &{
    return (*this > obj) || (*this == obj);
}

bool Time_::operator<=(const Time_ &obj) const &{
    return (*this < obj) || (*this == obj);
}

//--------- Assignment operators ---------
Time_ &Time_::operator+=(float s) {
    for(int i = 0; i < s; i++){
        tickTime();
    }
    return *this;
}

Time_ &Time_::operator-=(float s) {
    for(int i = 0; i < s; i++){
        untickTime();
    }
    return *this;
}

Time_ &Time_::operator+=(int m) {
    int totalSeconds = hour * 3600 + minutes * 60 + seconds + m * 60;

    if (format) {
        totalSeconds = (totalSeconds % (24 * 3600) + 24 * 3600) % (24 * 3600);
    } else {
        totalSeconds = (totalSeconds % (12 * 3600) + 12 * 3600) % (12 * 3600);
        if (totalSeconds == 0) totalSeconds = 12 * 3600;
    }

    hour = totalSeconds / 3600;
    minutes = (totalSeconds % 3600) / 60;
    seconds = totalSeconds % 60;

    return *this;
}

Time_ &Time_::operator-=(int m) {
    return *this += (-m);
}

Time_ &Time_::operator+=(long h) {
    return *this += (int)(h * 60);
}

Time_ &Time_::operator-=(long h) {
    return *this += (int)(-h * 60);
}


//--------- Arithmetic operators ---------
Time_ Time_::operator+(float s) const &{
    Time_ tmp = *this;
    tmp += s;
    return tmp;
}

Time_ Time_::operator-(float s) const &{
    Time_ tmp = *this;
    tmp -= s;
    return tmp;
}

Time_ Time_::operator+(int m) const &{
    Time_ tmp = *this;
    tmp += m;
    return tmp;
}

Time_ Time_::operator-(int m) const &{
    Time_ tmp = *this;
    tmp -= m;
    return tmp;
}

Time_ Time_::operator+(long h) const &{
    Time_ tmp = *this;
    tmp += h;
    return tmp;
}

Time_ Time_::operator-(long h) const &{
    Time_ tmp = *this;
    tmp -= h;
    return tmp;
}
