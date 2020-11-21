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

// struct HighestLevel{
//   string user_name;
//   int level;
//   char[] time; //timeOfGettingThisRecord;
// }

// struct ShortestTime{
//   int level;
//   string user_name;
//   char[] time; //timeOfPassingTheLevel;
// }

// bool operator<(const HighestLevel & a, const HighestLevel & b);
// bool operator<(const ShortesTime & a, const ShortesTime & b);
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
