// Record.h

#ifndef RECORD_H
#define RECORD_H

#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#include<iomanip>
#include "Timer.h"
#include "Menu.h"
#include "NewGame.h"
using namespace std;

void savingHighestLevelRecord();
void savingShortestTimeRecord();
void restoringHighestLevelRecord();
void restoringShortestTimeRecord();
void storeHighestLevelRecord(string, int);
void storeShortestTimeRecord(int, string, int, int);
void showRecords();
void showHighestLevelRecord();
void showShortestTimeRecord();
void cleanRecords();

#endif
