#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <iostream>
#include <ctime>
#include <string>

class logger
{
    public:
        logger();
        ~logger();

        void log(std::string message);
        void logNoTStamp(std::string message);

        std::string strFix(int n);
        std::string timestamp();

    private:

        std::ofstream logFile = std::ofstream();
};
#endif // LOGGER_H
