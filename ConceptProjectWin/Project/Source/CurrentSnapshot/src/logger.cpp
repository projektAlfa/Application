#include "logger.h"

logger::logger()
{
    logFile.open("./loggerDiary.txt");

    if(logFile.good())
    {
        logNoTStamp("Logger initialized and good");
        logNoTStamp("    started: " + timestamp());
        logNoTStamp("--------------------------------");
    }
}

logger::~logger()
{
    logNoTStamp("--------------------------------");
    logNoTStamp("Logger says goodbye");
    logNoTStamp("    exited: " + timestamp());

    logFile.close();
}

void logger::log(std::string message) { logFile << timestamp() << " " << message << std::endl; }

void logger::logNoTStamp(std::string message) { logFile << message << std::endl; }

std::string logger::strFix(int n)
{
    if(n < 10) return "0" + std::to_string(n);

    return std::to_string(n);
}

std::string logger::timestamp()
{
    time_t currentTime = time(NULL);
    tm localTime = *localtime(&currentTime);

    return strFix(localTime.tm_hour)  + ":"
         + strFix(localTime.tm_min)  + ":"
         + strFix(localTime.tm_sec) + " "
         + strFix(localTime.tm_mday) + "."
         + strFix(localTime.tm_mon) + "."
         + std::to_string(1900 + localTime.tm_year);
}
