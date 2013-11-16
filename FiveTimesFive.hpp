#ifndef FIVETIMESFIVE_HPP
#define FIVETIMESFIVE_HPP

//==================================================================================================
class CFiveTimesFive {
public:
    CFiveTimesFive();
    
    void start();
    
private:
    void getValues();
    
    void makeSchedule() const;
    
    float normalizeWeight(const float weight) const;
    
    float m_oneRepMax;
    float m_progressFromWeekToWeek;
};
//==================================================================================================

#endif
