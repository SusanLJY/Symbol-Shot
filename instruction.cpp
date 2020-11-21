/*instruction.cpp
 Workflow
  1. Read the instruction.txt and deal with exceptions.
  2. If read successfully --> print the instructions of playing Symbol-Shot.
  3. Press 'M' to return to menu.
    Exception dealing: continuously get input until input 'M'.
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

void instruction() {
  ifstream fin;
  fin.open("instruction.txt");
  if (fin.fail()){ //deal with exceptions
    cout << "I'm sure you are so clever that you can play the game without instructions!" << endl;
    return;
  }

  string line;

  while(getline(fin, line))
    cout << line << endl;
  cout<<"\n\033[;32m [M]--Back to Menu\033[0m"<<endl;
	cout << "  \n";
  char co;
  cin>>co;
  while (co!='M'){ //deal with exceptions
    cout<<"Input again!"<<endl;
    cin>>co;
  }
  fin.close();
}
