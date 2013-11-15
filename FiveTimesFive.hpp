#ifndef FIVETIMESFIVE_HPP
#define FIVETIMESFIVE_HPP

//==================================================================================================
class CFiveTimesFive {
public:
    CFiveTimesFive();
    
    void start();
    
private:
    void getValues();
    
    float m_oneRepMax;
    float m_progressFromWeekToWeek;
    float m_weightAccuracy;
};
//==================================================================================================

#endif
