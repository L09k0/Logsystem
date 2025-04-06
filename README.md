# Logsystem

Example
```cpp
#include <iostream>
#include <fstream>
#include <filesystem>
#include <ctime>
#include <string>
#include "loglist.h"

int main()
{
   // logsrecord(Message, Tipy message)
   // Tipy DEBUG the usual message for the debugger
   // Tipy WARNING problem warning
   // Tipy ERROR Error in the program
   // Tipy FATAL_ERROR Program error before it crashes
   logsystem::logsrecord("Start program Debug !", logsystem::DEBUG);
   logsystem::logsrecord("Start program warning !", logsystem::WARNING);
   logsystem::logsrecord("Start program Error !", logsystem::ERROR);
   logsystem::logsrecord("Start program FATAL_ERROR !!!", logsystem::FATAL_ERROR);
   return 0;
}
```cpp

Out file
logs\log.log

DEBUG: 10:56:32 Start program Debug !
WARNING: 10:56:32 Start program warning !
ERROR: 10:56:32 Start program Error !
FATAL_ERROR: 10:56:32 Start program FATAL_ERROR !!!
