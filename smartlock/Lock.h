#ifndef lock_h
#define lock_h

#include "Config.h"
#include <wiringPi.h>
#include <softPwm.h>
#include <fstream>
class Lock{
    private:
    void logWrite(std::string value);
    
    
    public:
    Lock();
    ~Lock();

    void lock(int pin);
    void unlock(int pin);
};
#endif
