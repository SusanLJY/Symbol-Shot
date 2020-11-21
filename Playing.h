// Playing.h

#ifndef PLAYING_H
#define PLAYING_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Timer.h"
#include "Menu.h"
#include "Record.h"
#include "NewGame.h"
using namespace std;

bool win();
void generate();
int check(int);
void swap(int,int,int,int);
bool find(string, char);
bool validInput(string, string);
void eliminate(int,int,char,int);
void deletet(int, int, int, int);
void fall();
int pairElimination();
void printBoard();
void superElimination(char);
void play();

#endif
