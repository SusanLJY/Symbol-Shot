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
/* Functions needed:
    1. string currentTime();
        Get current time (Format DD/MM/YYYY HH:MM HKT) (import)
        return current_time

    2. array[][3] storeLevel(string level, string user_name, array[][3] record_level):
        Store the level, user's name of last players, and the current time. --> (record_level[10][3]={[0,0,0]})
        return record_level;

    3. string newUserName():
        cin>>user_name
        Get new user's name (while loop)
            (if overlapped with previous players, cout<< "The name is used. Please change to another name.", recall this function)
        return user_name
    4. Call playing 
*/
vector<string> userName;
int level;
bool newBoard;

void restoringUserNameRecord(){
  ifstream fin("UserNameRecord.txt", ifstream::out);
	if ( fin.fail() ){
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
  if (fout.fail()) {
		cout << "Error in saving user-name information!" << endl;
    menu();
  }
  fout << un << endl;
	fout.close();
  play();
}