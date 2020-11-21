// NewGame.h

#ifndef NEWGAME_H
#define NEWGAME_H

#include <iostream>
#include <time.h>
#include <algorithm>
#include <vector>
#include <cstdlib>  
#include <ctime>   
#include <iomanip>
#include <string>  
#include "Timer.h"
#include "Playing.h"
using namespace std;

extern vector<string> userName;
extern int level;
extern bool newBoard;

void newGame();
void restoringUserNameRecord();

#endif