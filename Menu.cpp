/*Workflow
  1. void showMenu() to show different commands in Menu.
  2. void controlMenu() has different cases:
    2.1 Play 
      If you are totally new to this game, i.e., no previous user name, the game will send you to newGame stage.
      else --> using the last user name to play.
    2.2. New Game 
      Show current GMT time and input a new user name (without ' '). Exception dealing: If the user name is used before, it will ask you to input another.
    2.3 Clear
      Delete all the records and related txt files.
    2.4 Records 
      Show previous records: HighestLevelRecord or ShortestTimeRecord.
    2.5 Instructions
      Show instructions of playing Symbol-Shot
    2.6 Quit
      Save all current records and quit Symbol-Shot.
*/
#include <iostream>
#include "instruction.h"
#include "Playing.h"
#include "NewGame.h"
#include "Record.h"
using namespace std;

void showMenu(){
  system("clear");
  cout <<"\033[1;36m  ***************** Symbol Shot! *****************\033[0m" << endl;
  cout <<"\033[;32m  |  [P] Play  | [N] New Game | [C] Clear Record |\033[0m" << endl;
  cout << "\033[;33m  | [R] Records | [I] Instruction | [Q] Quit Game|\033[0m" << endl;
}

void controlMenu(){
  char command;
	cout << "  ";
  cin >> command;
  switch (command) {
    case 'P': 
      if (userName.size()==0) newGame(); //deal with exceptions
      else play(); 
      break;
    case 'N': newGame(); break;
		case 'C': cleanRecords(); break;
    case 'R': showRecords(); break;
    case 'I': instruction(); menu(); break;
    case 'Q':
		  cout << "  saving Highest Level Record...\n" << endl;
		  savingHighestLevelRecord();
			cout << "  saving Shortest Time Record...\n" << endl;
		  savingShortestTimeRecord();
			cout<<"\033[;32m Bye-bye!!!\n  Have a nice day!!!\033[0m"<<endl;
			exit(0);
    default: cout<<"  Invalid! Please input again!"<<endl; break;
  }
}

void menu(){
  showMenu();
  controlMenu();
}
