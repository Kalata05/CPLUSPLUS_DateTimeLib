#ifndef DATETIME_H
#define DATETIME_H
#include <string>
#include <ctime>

using namespace std;

class DateTime
{

private:
        int currentYear;
        int currentMonth;
        int currentDay;
        string currentLocalDateStr;
        string currentDayStr;
        string currentYearStr;
        string currentMonthStr;
        
        int specificYear;
        string specificYearStr;
        string UTCTime;
        
        time_t now;
        tm *timeObj;
        
public:
        DateTime();
        string getCurrentYearAsString();
        string getCurrentLocalDate();
        string getCurrentMonthAsString();
        string getCurrentDayAsString();
        int getCurrentYearAsInt();
        int getCurrentMonthAsInt();
        int getCurrentDayAsInt();
        int getSpecificYear(int &n);
        string getUTCTime();
};

#endif