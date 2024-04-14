#include <iostream>
#include <fstream>
#include <chrono>
#include <sys/stat.h>

#include "logger.h"

using namespace std;

string GetCurrentLogTime();

bool fileOpen = false;

ofstream logFile;
string lastLogTime;

void InitializeLogger()
{
    mkdir("logs");

    string filePath = "logs/log_";
    filePath += GetCurrentLogTime();
    filePath += ".log";
    logFile.open(filePath);

    if (logFile.is_open())
    {
        fileOpen = true;
        PrintToLog("log initialized");
    }
}

void PrintToLog(string_view inputString, bool isError)
{
    if (fileOpen)
    {
        string outputString = "";
        string currentLogTime = GetCurrentLogTime();
        if (currentLogTime != lastLogTime)
        {
            outputString += currentLogTime;
            outputString += ": ";
        }

        logFile << outputString << inputString << endl;
        
        lastLogTime = currentLogTime;

        if (isError)
        {
            cout << "ERROR: " << inputString << endl;
        }
    }
}

void CloseLogger()
{
    logFile.close();
    fileOpen = false;
}

string GetCurrentLogTime()
{
    time_t currentTime = time(0);
    tm currentLocal = *localtime(&currentTime);

    string currentTimeString = "";
    currentTimeString += to_string(1900 + currentLocal.tm_year);
    currentTimeString += '_';
    currentTimeString += to_string(currentLocal.tm_mon);
    currentTimeString += '_';
    currentTimeString += to_string(currentLocal.tm_mday);
    currentTimeString += '_';
    currentTimeString += to_string(currentLocal.tm_hour);
    currentTimeString += '_';
    currentTimeString += to_string(currentLocal.tm_min);
    currentTimeString += '_';
    currentTimeString += to_string(currentLocal.tm_sec);

    return currentTimeString;
}