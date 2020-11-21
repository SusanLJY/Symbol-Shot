// Timer.h
#ifndef _TIMER_H
#define _TIMER_H
 
#include <iostream>  
#include <cstdlib>  
#include <ctime>    
#include <iomanip> 
#include "NewGame.h"
#include "Playing.h"
using namespace std;
//Declare the Timer class
class Timer{  
    private:   
        long pause_time;  
        //Using 2 boolean to symbolize 4 status   
        bool is_pause; //Pause or not  
        bool is_stop;//Stop or not 
    public:
        long start_time;  
        bool isPause();
        bool isStop();  
        //functions of Timer
        void Start();   
        void Pause();  
        void Stop();  
        inline long getStartTime() {return start_time;} 
        void currentTime(int *);
};
 
#endif
