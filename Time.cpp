//
// Created by admin on 07.09.2025.
//

#include "Time.h"

Time_::Time_() {
    time_t pc_time = time(nullptr);
    tm* obj = localtime(&pc_time);

    hour = obj -> tm_hour;
    minutes = obj -> tm_min;
    seconds = obj -> tm_sec;
    format = true;
}

Time_::Time_(int hour, int minutes, int seconds, bool format) {

}

Time_::Time_(const Time_ &obj) {

}

Time_ &Time_::operator=(const Time_ &obj) {

}

Time_::~Time_() {

}

void Time_::setHour(int hour) {

}

int Time_::gerHour() const {
    return 0;
}

void Time_::setMinutes(int minutes) {

}

int Time_::getMinutes() const {
    return 0;
}

void Time_::setSeconds(int seconds) {

}

int Time_::getSeconds() const {
    return 0;
}

void Time_::setFormat(bool format) {

}

bool Time_::getFormat() const {
    return false;
}

bool Time_::valid() const {
    return false;
}

void Time_::tickTime() {

}

void Time_::untickTime() {

}

void Time_::showTime() const {

}

//--------- Comparison operators ---------
bool Time_::operator==(const Time_ &obj) const &{
    return false;
}

bool Time_::operator!=(const Time_ &obj) const &{
    return false;
}

bool Time_::operator>(const Time_ &obj) const &{
    return false;
}

bool Time_::operator<(const Time_ &obj) const &{
    return false;
}

bool Time_::operator>=(const Time_ &obj) const &{
    return false;
}

bool Time_::operator<=(const Time_ &obj) const &{
    return false;
}

//--------- Assignment operators ---------
Time_ &Time_::operator+=(float s) {
}

Time_ &Time_::operator-=(float s) {
}

Time_ &Time_::operator+=(int m) {
}

Time_ &Time_::operator-=(int m) {
}

Time_ &Time_::operator+=(long h) {
}

Time_ &Time_::operator-=(long h) {
}


//--------- Arithmetic operators ---------
Time_ Time_::operator+(float s) const &{
    return Time_();
}

Time_ Time_::operator-(float s) const &{
    return Time_();
}

Time_ Time_::operator+(int m) const &{
    return Time_();
}

Time_ Time_::operator-(int m) const &{
    return Time_();
}

Time_ Time_::operator+(long h) const &{
    return Time_();
}

Time_ Time_::operator-(long h) const &{
    return Time_();
}
