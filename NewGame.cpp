/* NewGame.cpp 
 This file aims at doing preparation jobs for users to start a new game.
  Variables and Functions needed:
    1. external variables: 
      1.1 vector<string> userName: store userName in a vector //dynamic memory
      1.2 int level: initialize the level of games
      1.3 bool newBoard: determine whether we need to regenerate a new board or using the previous one.
    2. void restoringUserNameRecord():
      Restore the user name from UserNameRecord.txt file. 
      Exception dealing: 
        If the file does not exist, then create an empty file.
    3. void newGame():
      Get current GMT and input a new user name (without ' '). Store the user name in both vector and txt file. Then move to play stage.
      Exception dealing: 
        If the user name is used before, it will ask you to input another.
*/
#include <iostream>
#include <fstream>
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

vector<string> userName;
int level;
bool newBoard;

void restoringUserNameRecord(){
  ifstream fin("UserNameRecord.txt", ifstream::out);
	if ( fin.fail() ){//dealing with exception
		ofstream fout("UserNameRecord.txt");
		restoringUserNameRecord();
 	}
  
  string un;
  while (fin >> un)
    userName.push_back(un);
	fin.close();
}

void newGame(){
	restoringUserNameRecord();
  newBoard = true;
  level = 0;
  int ti[3];
  Timer t2;
  t2.currentTime(ti);
  cout << " Current local time : " <<setw(2)<<setfill('0')<< ti[0] << ":" <<setw(2)<<setfill('0')<< ti[1] << ":" <<setw(2)<<setfill('0')<< ti[2]<<setfill(' ')<<endl;
  string un;
  cout<<"\n Please input user name: ";
  cin>>un;
  while ( find(userName.begin(), userName.end(), un) != userName.end()){
    cout<<"User name is used, please change another one."<<endl;
    cout<<"Please input user name: ";
    cin>>un;
  }
  userName.push_back(un);

  ofstream fout("UserNameRecord.txt", ios::app);
  if (fout.fail()) { //dealing with exception
		cout << "Error in saving user-name information!" << endl;
    menu();
  }
  fout << un << endl;
	fout.close();
  play();
}
