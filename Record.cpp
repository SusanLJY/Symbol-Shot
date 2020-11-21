/* Record.cpp
  This file includes all the structs, variables, and functions needed in Symbol-Shot to save, store, show, and restore the users' game records.
 Variables and Functions include:
  1. Structs:
    1.1 HighestLevel:
      Includes userName, highest level, and Time of achieving this record (GMT).
    1.2 ShortestTime:
      Includes level, time of passing the level, score, and user name.
  2. Variables: //Both using dynamic memory.
    vector<HighestLevel> highestLevelRecord:
          The highest current level that a player has achieved.
    map<int,ShortestTime> shortestTimeRecord:
          The shortest time of passing each level in history.
  3. Functions:
    Includes functions to save, store, show, restore, and delete(clean) the users' game records.
*/
//Imports
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#include<iomanip>
#include<fstream>
#include "Timer.h"
#include "Menu.h"
#include "NewGame.h"
using namespace std;

//Function Declaration
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

//Structs
struct HighestLevel{
  string name; //timeOfGettingThisRecord;
  int level;
  string time;
};

struct ShortestTime{
  int level, time, score;
  string name; //timeOfPassingTheLevel;
};


//Arrays: Vector and Map
vector<HighestLevel> highestLevelRecord;
map<int,ShortestTime> shortestTimeRecord;

//Operator Overloading

bool operator<(const HighestLevel & a, const HighestLevel & b) {
  if (a.level == b.level) return (a.time < b.time);
  return (a.level > b.level);
}

bool operator<(const ShortestTime & a, const ShortestTime & b) {
  return (a.time < b.time);
}


//Methods: storing records

void savingHighestLevelRecord(){
  ofstream fout;
  fout.open("Highest Level Record.txt", ios::ate);
  if (fout.fail()) {
		cout << "Error in saving game highest level record information!" << endl;
    menu();
  }
  for (int i=0; i<highestLevelRecord.size(); i++){
    fout << highestLevelRecord[i].name<<" "<<highestLevelRecord[i].level<<" "<<highestLevelRecord[i].time<<endl;
  }
}

void savingShortestTimeRecord(){
  ofstream fout;
  fout.open("Shortest Time Record.txt", ios::ate);
  if (fout.fail()) {
		cout << "Error in saving game shortest time record information!" << endl;
    menu();
  }
  for (int i=1; i<shortestTimeRecord.size()+1; i++){
    // if (shortestTimeRecord[0].level == ) continue;
    fout << shortestTimeRecord[i].level<<" "<<shortestTimeRecord[i].time<<" "<<shortestTimeRecord[i].score<<" "<<shortestTimeRecord[i].name<<endl;
  }
	fout.close();
}

void restoringHighestLevelRecord(){
  ifstream fin("Highest Level Record.txt", ifstream::out);
  if (fin.fail()) {
		ofstream fout("Highest Level Record.txt");
		cout << "Creating Highest Level Record.txt ..." << endl;
    restoringHighestLevelRecord();
  }
  string name;
	int level;
	string time;
	int i = 0;
  HighestLevel h;
	while (fin >> name >> level >> time){
    bool duplicate =false;
    for (int i=0; i<highestLevelRecord.size(); i++){
      if (highestLevelRecord[i].name==name){
        if (highestLevelRecord[i].level<level){
          highestLevelRecord[i].level = level;
          highestLevelRecord[i].time = time;
        }
        duplicate=true;
      }
    }
    if (!duplicate){
      h = {name, level, time};
      highestLevelRecord.push_back(h);
    }
	}
	fin.close();
}

void restoringShortestTimeRecord(){
  ifstream fin("Shortest Time Record.txt", ifstream::out);
  if (fin.fail()) {
		ofstream fout("Shortest Time Record.txt");
		cout << "Creating Shortest Time Record.txt ..." << endl;
    restoringShortestTimeRecord();
  }
	int level, time, score;
	string name;
	int i = 1;
  ShortestTime s;
	while (fin >> level >> time >> score >> name){
    shortestTimeRecord[i].level = level;
		shortestTimeRecord[i].time = time;
		shortestTimeRecord[i].score = score;
		shortestTimeRecord[i].name = name;
		i++;
	}
  fin.close();
}

void storeHighestLevelRecord(string name, int level){
  int ti[3];
  Timer t2;
  t2.currentTime(ti);
  string s = "";
  s = to_string(ti[0])+":"+to_string(ti[1])+":"+to_string(ti[2]);
  bool dup = false;
	for(int i=0; i < highestLevelRecord.size(); ++i){
		if (highestLevelRecord[i].name == name){
		  if (highestLevelRecord[i].level < level){
				highestLevelRecord[i].level = level;
				highestLevelRecord[i].time = s;
			}
      dup=true;
    }
	} 
  if (!dup){
    HighestLevel hl = {name, level, s};
    highestLevelRecord.push_back(hl);
  }
  sort(highestLevelRecord.begin(), highestLevelRecord.end());
  if ( highestLevelRecord.size() > 10 )
	  highestLevelRecord.pop_back();
  savingHighestLevelRecord();
}

void storeShortestTimeRecord(int level, string user_name, int timeOfPassing, int score) {
  ShortestTime st = {level, timeOfPassing, score, user_name};
	if (level != 0 and score !=0){
	  if (shortestTimeRecord.count(level) == 0 || st < shortestTimeRecord[level])
      shortestTimeRecord[level] = st;
  }
  savingShortestTimeRecord();
}

//Methods: showing records
void showRecords(){
  char rn;
  cout << endl;
  cout<<" See which Record? ------------"<<endl;
  cout<<" [H]--The Highest Level Record"<<endl;
  cout<<" [S]--The Shortest Time Record"<<endl;
  cout<<" [M]--Back to Menu"<<endl;
  cout<<"  ";
  cin>>rn;
  cout << endl;
  if (rn=='H') showHighestLevelRecord();
  else if (rn=='S') showShortestTimeRecord();
  menu();
}

void showHighestLevelRecord() {
  showMenu();
  cout << endl;
	cout << "The below shows the highest current level\n" << endl;
  cout << "  | Level |  High Achievers  |   Recorded Time   |" << endl;
  for (int i = 0; i < highestLevelRecord.size(); ++i){
    cout << "  | " << setw(5) << highestLevelRecord[i].level << " | " << setw(16) << highestLevelRecord[i].name << " | " << setw(13) << highestLevelRecord[i].time << " GMT" << " |" << endl;
  }
  cout << "\n  Press R to return\n  ";
  char r;
  while (cin >> r){
    if (r == 'R') showRecords();
    else cout << "Invalid Input" << endl;
  }
}

void showShortestTimeRecord() {
	showMenu();
  cout << endl;
	cout << "The below shows the highest finished level\n" << endl;
  cout << "  | Level |   High Achievers  |  Time  |  Score  |" << endl;
  for (int i = 1; i < shortestTimeRecord.size()+1; ++i){
    cout << "  | " << setw(5) << i << " | " << setw(17) << shortestTimeRecord[i].name << " | " << setw(6) << shortestTimeRecord[i].time << " | " << setw(7) << shortestTimeRecord[i].score << " |" << endl;
  }
  cout << "\n  Press R to return\n  ";
  char r;
  while (cin >> r){
    if (r == 'R') showRecords();
    else cout << "  Invalid Input";
  }
}

void cleanRecords(){
  userName.clear();
  highestLevelRecord.clear();
  shortestTimeRecord.clear();
  if( remove( "UserNameRecord.txt" ) == 0 && remove("Shortest Time Record.txt")==0 && remove("Highest Level Record.txt")==0)
    cout<<"\n\033[;31mFile successfully deleted\033[0m\n"<<endl;
}
