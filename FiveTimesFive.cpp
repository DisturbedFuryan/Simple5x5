#include <iostream>
#include "FiveTimesFive.hpp"
#include "utilities.hpp"

using namespace std;

CFiveTimesFive::CFiveTimesFive() : m_oneRepMax(0.0f), m_progressFromWeekToWeek(0.0f) {}
                                   
void CFiveTimesFive::start() {
    getValues();
    makeSchedule();
}                                   


void CFiveTimesFive::getValues() {
    /* NOTE: The obtained parameters will be normalized.
     * Thanks to that, will be much less normalizations in the future. */
    
    cout << "Type one rep max: ";
    cin >> m_oneRepMax;
    m_oneRepMax = normalizeWeight(m_oneRepMax);
    
    cout << "Type progress weight from week to week: ";
    cin >> m_progressFromWeekToWeek;
    m_progressFromWeekToWeek = normalizeWeight(m_progressFromWeekToWeek);
}

void CFiveTimesFive::makeSchedule() const {
    /* Compute the five rep max. */
    float fiveRepMax = normalizeWeight(m_oneRepMax * g_oneRepToFiveMultiplier);
    
    cout << "Your five rep max: " << fiveRepMax << endl;
    
    /* Compute a weight in the last set. The first will be a weight for the first week. */
    float lastSetWeight = (fiveRepMax - (m_progressFromWeekToWeek * (g_weekWithFiveRepMax - 1)));
    
    /* Compute weights for g_weekNum weeks and show the result. */
    for (int i = 0; i < g_weekNum; ++i) {
        cout << "Week " << (i + 1) << ":  ";
        
        /* Weights in the first four sets... */
        for (int j = 0; j < 4; ++j) {
            cout << normalizeWeight(lastSetWeight * g_setMultiplier[j]) << "  ";
        }
        
        /* ...and in the last set. */
        cout << lastSetWeight << endl;
        
        /* The last set weight will be increased by m_progressFromWeekToWeek in the next week. */
        lastSetWeight += m_progressFromWeekToWeek;
    }
}

float CFiveTimesFive::normalizeWeight(const float weight) const {
    /* Round down the weight with the gym stuff accuracy. */
    float floorWeight = (g_weightAccuracy * static_cast<int>(weight / g_weightAccuracy));
    
    /* Compute the excess. */
    float end = (weight - floorWeight);
    
    /* If the excess is greater than the given treshold
     * you can come face-to-face with more weight. */
    return ((end > g_treshold) ? (floorWeight + g_weightAccuracy) : floorWeight);
}
