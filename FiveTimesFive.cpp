#include <iostream>
#include "FiveTimesFive.hpp"
#include "utilities.hpp"

using namespace std;

CFiveTimesFive::CFiveTimesFive() : m_oneRepMax(0.0f), m_progressFromWeekToWeek(0.0f),
                                   m_weightAccuracy(0.0f), m_treshold(0.0f) {}
                                   
void CFiveTimesFive::start() {
    getValues();
    makeSchedule();
}                                   


void CFiveTimesFive::getValues() {
    cout << "Type one rep max: ";
    cin >> m_oneRepMax;
    
    cout << "Type progress weight from week to week: ";
    cin >> m_progressFromWeekToWeek;
    
    cout << "Type accuracy of result weights: ";
    cin >> m_weightAccuracy;
    
    m_treshold = ((2.0f / 3.0f) * m_weightAccuracy);
}

void CFiveTimesFive::makeSchedule() const {
    float fiveRepMax = normalizeWeight(m_oneRepMax * g_oneRepToFiveMultiplier);
    
    cout << "Your five rep max: " << fiveRepMax << endl;
    
    float lastSetWeight = (fiveRepMax - (m_progressFromWeekToWeek * (g_weekWithFiveRepMax - 1)));
    float setMultiplier;
    
    for (int i = 0; i < g_weekNum; ++i) {
        cout << "Week " << (i + 1) << ":  ";
        
        setMultiplier = 0.6f;
        for (int j = 0; j < 4; ++j) {
            cout << normalizeWeight(lastSetWeight * setMultiplier) << "  ";
            setMultiplier += 0.1f;
        }
        
        cout << lastSetWeight << endl;
        
        lastSetWeight += m_progressFromWeekToWeek;
    }
}

float CFiveTimesFive::normalizeWeight(const float weight) const {
    float floorWeight = (m_weightAccuracy * static_cast<int>(weight / m_weightAccuracy));
    float end = (weight - floorWeight);
    return ((end > m_treshold) ? (floorWeight + m_weightAccuracy) : floorWeight);
}
