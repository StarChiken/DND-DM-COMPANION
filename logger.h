#pragma once
#include <iostream>

using namespace std;

/*
This system is for debugging
* Use PrintToLog() instead of cout when the user does not need to see the output
*/

void InitializeLogger();
void PrintToLog(string_view inputString, bool isError = false);
void CloseLogger();