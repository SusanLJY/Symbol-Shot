/* Workflow
    1. print Guide
    2. initialization
        current_level=0
        string[10][3] record_level={["0","0","0"]}  --> [User's name, Level, CurrentTime]
        vector<string[3]> record_shortest_time --> [Level(1-current), User's name, Time of passing the level]
    3. call Menu
    4. 
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
// #include "Timer.h"
// #include "Playing.h"
#include "NewGame.h"
#include "Menu.h"
#include "Record.h"
using namespace std;

int main() {
	cout << "  restoring User Name Record...\n" << endl;
	restoringUserNameRecord();
	cout << "  restoring Shortest Time Record...\n" << endl;
	restoringShortestTimeRecord();
	cout << "  restoring Highest Level Record...\n" << endl;
	restoringHighestLevelRecord();
  cout<<"Done!\n"<<endl;
  char choice;
  while (1){
    cout<<"\033[;31mDo \033[;32myou \033[;33mwant to \033[;34m  enjoy \033[1;35mSymbol Shot\033[0m \033[;36mnow? \033[4;31mY or N\033[0m"<<endl;
    cin>>choice;
    if (choice=='Y') {
      system("clear");
      menu();
    }
    else{
      cout<<"\033[;32m  Bye-bye!!!\n Have a nice day!!!\033[0m"<<endl;
			exit(0);
    }
  }
  return 0; 
}
 