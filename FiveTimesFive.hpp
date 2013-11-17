#ifndef FIVETIMESFIVE_HPP
#define FIVETIMESFIVE_HPP

//==================================================================================================
class CFiveTimesFive {
public:
    CFiveTimesFive();
    
    /* Gets parameters from user and creates a workout schedule. */
    void start();
    
private:
    /* Gets the values needed to create a workout schedule from user. */
    void getValues();
    
    /* Creates a workout schedule. */
    void makeSchedule() const;
    
    /* Adjusts weight to available plates on the gym. */
    float normalizeWeight(const float weight) const;
    
    /* Variables to hold the parameters obtained from the user. */
    float m_oneRepMax;
    float m_progressFromWeekToWeek;
};
//==================================================================================================

#endif
