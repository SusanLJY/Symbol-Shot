/* Workflow
  1. initialization
    1.1 Call restoring functions in "Record.h" to restore the userName, ShortestTimeRecord, and HighestLevelRecord from different txt files.
    
  2. Start the game or not?
    2.1 if yes --> go to menu.
    2.2 else   --> quit the game
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
 
