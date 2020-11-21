/*
    1. void showInstructions(int current_level);
        bool valid_instr=true;
        string instruction;
        while valid_instr
        1) if (current_level==0); 
            print: NewGame, Quit, Record 
            cin>>instruction;
            Switch
                NewGame --> New_Game()
                Quit --> Exit()
                Record --> Record()

        2) else; Play, NewGame, Pause, Quit, Record
            Similar to 1)
1. Play
2. New Game
4. Records
5. Instructions
6. Quit
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
    case 'P': play(); break;
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