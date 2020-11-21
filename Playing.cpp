/* Functions needed
    1. Timing 
    2.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Timer.h"
#include "Menu.h"
#include "Record.h"
#include "NewGame.h"
using namespace std;

const int bs = 10;
char board[bs][bs]={};
int score=0;
int scoreLimit;
string a, b;
Timer t;

// Function Declaration
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


bool win(){
  int timeOfPassing = time(0) - t.start_time;
  int tl;
  if (level>10) tl=30;
  else tl=(60-3*level);
  if (timeOfPassing>=tl){
    t.Stop();
    storeHighestLevelRecord(userName[userName.size()-1],level);
    return false;
  } else if (score >= scoreLimit){
		cout << "storing shortest time" << endl; ///
    storeShortestTimeRecord(level, userName[userName.size()-1],timeOfPassing,score);
		cout << "stoping timer" <<endl; ///
    t.Stop();
    system("clear");
    cout<<"\nYou Win!!!"<<endl;
    cout<<"\n Your score in level "<<level<<" is "<<score <<" ! "<<endl;
		cout<<"\n Score Limit in this level is "<<scoreLimit<< endl;
    cout<<"\nNext Level? Y or N"<<endl;
    char choice;
    cin>>choice;
    while (choice != 'Y' && choice != 'N'){
      cout<<"Invalid choice! Please input Y or N!"<<endl;
			cout<<endl;
      cin>>choice;
    }
    if (choice=='Y'){
      //system("color 05");
      cout<<"-------------------\n"<<"----Next-Level-----\n"<<"-------------------"<<endl;
      play();
    }else{
      storeHighestLevelRecord(userName[userName.size()-1],level);
      showRecords();
    }
    return false;
  }else return true;
}

void generate(){
  char jews[6]={'@','#','$','%','&','+'};
  srand(time(0));
  for (int i=0; i<bs; i++){
    for (int j=0; j<bs; j++){
      if (board[i][j]=='\0' || board[i][j]==' '){
        int jew = rand()%6;
        board[i][j] = jews[jew];
      }
    }
  }
  printBoard();
}

int check(int hits){
  for (int i = 0; i < bs; i++){
    for (int nums = 5; nums >=3; nums--){
      for (int j = 0; j <= bs-nums; j++){
        bool same= true;
        if (board[i][j]==' ') continue;
        for (int k = j+1; k < j+nums; k++){
          same = (same && (board[i][k]==board[i][j]));
        }
        if (same){
          hits++;
          score += hits * nums;
          eliminate(i,j,'R',nums);
          return hits;
        }
      }
    }
  }

  //check in columns
  for (int j = 0; j < bs; j++){
    for (int nums = 5; nums >= 3; nums--){
      for (int i = 0; i <= bs-nums; i++){
        bool same= true;
        if (board[i][j]==' ') continue;
        for (int k = i; k < i+nums; k++){
          same = (same && board[k][j]==board[i][j]);
        }
        if (same){
          hits++;
          score += hits * nums;
          eliminate(i,j,'C',nums);
          return hits;
        }
      }
    }
  }
  return hits;
}

void swap(int r1, int c1, int r2, int c2) {
  char temp = board[r1][c1];
  board[r1][c1] = board[r2][c2];
  board[r2][c2] = temp;
}

bool find(string roc, char substring) {
  if (roc.find(substring) == string::npos) return false;
  else return true;
}

bool validInput(string a, string b) {
  string row = "ABCDEFGHIJ";
  string column = "0123456789";
  if (a.length() > 2 || b.length() > 2)
    return false;
  else if (!(find(row,a[0]) && find(column,a[1]) && find(row,b[0]) && find(column,b[1])))
    return false;
  else if (abs(a[0]-b[0])>1 || abs(a[1]-b[1])>1)
    return false;
  return true;
}

void eliminate(int i0, int j0, char roc, int number) {
  int i1 = i0+1, j1 = j0+1; //terminal tile
  int i2 = i0, j2 = j0; //middle tile, only applicable to case 5
  switch (roc){
    case 'C':
      i1 = i0 + number;
      break;
    case 'R':
      j1 = j0 + number;
      break;
  }
  switch (number){
    case 5:
      (roc == 'C') ? i2 = (i0 + 2) : j2 = (j0 + 2);
      deletet(i0, i1, j0, j1);
      board[i2][j2] = '!';
      break;
    case 4:
      if (roc == 'C') {i0 = 0; i1 = 10;}
      else {j0 = 0; j1 = 10;}
      deletet(i0, i1, j0, j1);
      break;
    case 3:
      deletet(i0, i1, j0, j1);
      break;
  }
  fall();
}

void deletet(int i0, int i1, int j0 ,int j1) {
  for (int i=i0; i<i1; i++){
    for (int j=j0; j<j1; j++){
      board[i][j] = ' ';
    }
  }
}

void fall() {
  printBoard();
  for (int i=bs-1; i>=0; i--){
    for (int j=0; j<bs; j++){
      if (board[i][j] == ' '){
        for (int r=1; r<=i; r++){
            if (board[i-r][j]!=' '){
              board[i][j] = board[i-r][j];
              board[i-r][j] = ' ';
              break;
            }
        }
      }
    }
  }
  printBoard();
  generate();
}

int pairElimination(){
  int hits = 0;
  int hit = check(hits);
  while (hit>hits){ // eliminate successfully
    hits = hit;
    hit = check(hits);
  }  
  hits = hit;
  return hits;
}

void printBoard(){
  system("clear");
  cout<<" -----[See Menu] -- Back to Menu! "<<endl;
  cout<<" -----[Pause Game] to Pause! "<<endl;
	cout<<endl;
  cout<<"    0 1 2 3 4 5 6 7 8 9"<<endl;
  for (int i=0; i<bs; i++){
    char rowC = 65+i;
    cout<<"  "<<rowC;
    for (int j=0; j<bs; j++){
      switch (board[i][j]){
        case '@': cout<<" \033[;31m"; break;
        case '#': cout<<" \033[;32m"; break;
        case '$': cout<<" \033[;33m"; break;
        case '%': cout<<" \033[;34m"; break;
        case '&': cout<<" \033[;35m"; break;
        case '+': cout<<" \033[;36m"; break;
        case '!': cout<<" \033[4;31m"; break;
        //case '?': cout<<" \033[;37m"; break;
        //case '~': cout<<" \033[4;37m"; break;
      }
      cout<<board[i][j]<<"\033[0m";
    }
    cout<<endl;
  }
	cout<<endl;
  cout<<"\033[1;31mCurrent Level: "<<level<<endl;
  cout<<"Score: "<<score<<endl;
  cout<<"Win: "<<scoreLimit<<endl;
  if( !t.isStop()&& !t.isPause()){
    int ct = time(0);  
    int time = 63 - 3*level - (ct - t.start_time);
  cout<<"!!! "<<time<<"seconds left !!!\033[0m"<<endl;
  } 
}

void superElimination(char symbol) {
  for (int i=0; i<bs; ++i)
    for (int j=0; j<bs; ++j)
      if (board[i][j] == symbol)
        board[i][j] = ' ';
  fall();
  pairElimination();
}

void play(){
  int r1=-1, c1=-1, r2=-1, c2=-1;
  level ++;
  t.Start();
  if (newBoard){
    for (int i = 0; i<100; i++){
      board[i/10][i%10]='\0';
    }
  }
  srand(time(0));
  board[rand()%10][rand()%10] = '!';
  generate();
  pairElimination();
  score=0;
  printBoard();
  scoreLimit = 100 + 50 * level;
  while (win()){
		cout << endl;
    cout << "Please input a swapping pair: ";
    cin >> a >> b;
    while (1){ 
      if (a == "Pause" && b == "Game"){
        cout<<"Input [C] to continue!"<<endl;
        t.Pause();
        char con='\0';
        while (con != 'C'){
          cin>>con;
          t.Start();
        }
      }else if (a == "See" && b == "Menu"){
        t.Pause();
        menu();
      }else if (validInput(a,b)) break;
      else cout << "Invalid input. Please input again.\n" << endl;
      cout << "Please input a swapping pair: ";
      cin >> a >> b;
    }
    r1 = a[0] - 65;
    c1 = a[1] - 48;
    r2 = b[0] - 65;
    c2 = b[1] - 48;
    if (board[r1][c1] == '!'){
      board[r1][c1]=' ';
      superElimination(board[r2][c2]);
      cout<<"\033[1;41m BOOM!!! \033[0m"<<endl;
    } else if (board[r2][c2] == '!'){
      board[r2][c2]=' ';
      superElimination(board[r1][c1]);
      cout<<"\033[1;41m BOOM!!! \033[0m"<<endl;
    }else{
      swap(r1, c1, r2, c2);
      int hits = pairElimination();
      if (hits > 0){
        cout << hits << " hits!" << endl;
      }else{
        swap(r1,c1,r2,c2);
        cout << "Invalid move. Please input again.\n" << endl;
      }
    }
  }
  system("clear");
  for (int i=0; i<5; i++){
    cout<<"\n \033[1;31mGame Over\033[0m"<<endl;
  }
  cout<<"\n \033[4;32m TIMES UP !!! \n\033[0m"<<endl;
  cout<<"\n \033[4;36m You Scored "<<score<<" in level "<<level<<" !\033[0m"<<endl;
  level = 0;
  char com;
  cout<<"\nPress any button -- back to Menu "<<endl;
  cin>>com;
  menu();
}