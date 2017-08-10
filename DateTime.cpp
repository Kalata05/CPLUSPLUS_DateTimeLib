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

DateTime::DateTime()
{
    now = time(0);
    
    timeObj = localtime(&now); 
    
}

string DateTime::getCurrentYearAsString()
{
    currentYearStr = to_string(1900+timeObj->tm_year);
    return currentYearStr;
    
}

string DateTime::getCurrentLocalDate()
{
        char *tmpdate = ctime(&now);
        
        int i = 0;
        while(tmpdate[i] != '\0')
        {
                currentLocalDateStr.push_back(tmpdate[i]);
                i++;
        }
        
        return currentLocalDateStr;
}

string DateTime::getCurrentMonthAsString()
{
    currentMonthStr = to_string(1 + timeObj->tm_mon);
    return currentMonthStr;
}

string DateTime::getCurrentDayAsString()
{
    currentDayStr = timeObj->tm_mday;
    
    return currentDayStr;
}

int DateTime::getCurrentYearAsInt()
{
        currentYear = 1900 + timeObj->tm_year;
        return currentYear;
}

int DateTime::getCurrentMonthAsInt()
{
        currentMonth = 1 + timeObj->tm_mon;
        return currentMonth;
}

int DateTime::getCurrentDayAsInt()
{
        currentDay = timeObj->tm_mday;
        return currentDay;
    
}

int DateTime::getSpecificYear(int &n)
{
    int yearNow = getCurrentYearAsInt();
    
    specificYear = yearNow + n;
    return specificYear;
}

string DateTime::getUTCTime()
{
    timeObj = gmtime(&now);
    char *utctime_p = asctime(timeObj);
    
    int i = 0;
    
    while(utctime_p[i] != '\0')
    {
            UTCTime.push_back(utctime_p[i]);
            i++;
    }
    
    return UTCTime;
}