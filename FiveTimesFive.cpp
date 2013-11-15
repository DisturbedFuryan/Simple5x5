#include <iostream>
#include "FiveTimesFive.hpp"

using namespace std;

CFiveTimesFive::CFiveTimesFive() : m_oneRepMax(0.0f), m_progressFromWeekToWeek(0.0f),
                                   m_weightAccuracy(0.0f) {}
                                   
void CFiveTimesFive::start() {
    getValues();
}                                   


void CFiveTimesFive::getValues() {
    cout << "Type one rep max: ";
    cin >> m_oneRepMax;
    cout << "Type progress weight from week to week: ";
    cin >> m_progressFromWeekToWeek;
    cout << "Type accuracy of result weights: ";
    cin >> m_weightAccuracy;
}
