// Timer.cpp
#include <iostream>  
#include <cstdlib>  
#include <ctime>    
#include <iomanip> 
#include "NewGame.h"
using namespace std;

// class Timer{  
//     private:   
//         long pause_time;  
//         //Using 2 boolean to symbolize 4 status   
//         bool is_pause = false; //Pause or not  
//         bool is_stop = true;//Stop or not 
//     public:
//         long start_time; 
//         bool isPause(); //Return the status of Timer
//         bool isStop();  
//         //3 function of Timer
//         void Start();   
//         void Pause();  
//         void Stop();  
//         inline long getStartTime() {return start_time;}
//         void currentTime(char *);
// }; 

// Timer::Timer(){  
//     is_pause = false; //Initialize Timer. 
//     is_stop = true;  
// } 

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
     //如果处于停止/暂停状态,此动作不做任何处理，直接返回
    if(is_stop||is_pause) return;   
    //否则调制为暂停状态  
    else{  
        is_pause = true;  
        pause_time = time(0); //获取暂停时间
        cout<<"\nGame Paused!\nInput \"C\" to continue!"<<endl;   
    }  
}

void Timer::Stop(){  
    //如果正处于停止状态（不是暂停状态），不做任何处理
    if(is_stop) return ;   
    else if(is_pause){ //改变计时器状态   
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