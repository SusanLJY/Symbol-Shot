/* Timer.cpp
  This file is to store the current timing status and return the time of every points. It also has the functions to pause and stop timing.
*/
#include <iostream>  
#include <cstdlib>  
#include <ctime>    
#include <iomanip> 
#include "NewGame.h"
using namespace std;

bool Timer::isPause(){     
    if(is_pause)  return true;  
    else  return false;  
} 
bool Timer::isStop(){  
    if(is_stop)  return true;  
    return false;  
}  
void Timer::Start(){  
    if(is_stop){  
        start_time = time(0);  
        is_stop = false;  
    }else if(is_pause)  {  
        is_pause = false;  
        start_time += time(0)-pause_time; //update start_time: current_time - pause_time + last_start_time = current_start_time   
    }else start_time = time(0);
} 
void Timer::Pause(){  
    if(is_stop||is_pause) return;   
    else{  
        is_pause = true;  
        pause_time = time(0); //Get the length of  pausing time
        cout<<"\nGame Paused!\nInput \"C\" to continue!"<<endl;   
    }  
}

void Timer::Stop(){  
    if(is_stop) return ;   
    else if(is_pause){ //Change the status of timer  
        is_pause = false;  
        is_stop = true;  
    }  
    else if(!is_stop){  
        is_stop = true;  
    }   
}

void Timer::currentTime(int* ti){
	time_t curr_time;
	curr_time = time(NULL);
	tm *tm_local = localtime(&curr_time);
	ti[0]=tm_local->tm_hour;
  ti[1]=tm_local->tm_min;
  ti[2]=tm_local->tm_sec;
}
