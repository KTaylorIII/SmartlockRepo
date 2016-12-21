#include "Lock.h"

Lock::Lock(){
    wiringPiSetup();
}
Lock::~Lock(){

}

void Lock::logWrite(std::string value){
    std::fstream fin;
    fin.open("/var/smartlock/status.txt", std::fstream::out);
    if (fin.is_open()){
        fin << value;
        fin.close();
    }
    else{
        return;
    }
    return;
}

void Lock::lock(int pin){
    pinMode(pin, OUTPUT);
    /*for (int delta_t = 0; delta_t < 2000000; delta_t += PERIOD){
        digitalWrite(pin, HIGH);
        delayMicroseconds(LOCKED_HIGH);
        digitalWrite(pin, LOW);
        delayMicroseconds(PERIOD - LOCKED_HIGH);
    }*/
    
    int pwm = softPwmCreate(pin, 6, 100);
    
    for (int t = 0; t < 2000000; t += PERIOD){
        softPwmWrite(pin, 6);
        delayMicroseconds(PERIOD);
    }
    logWrite("locked!");
}

void Lock::unlock(int pin){
    pinMode(pin, OUTPUT);
    /*for (int delta_t = 0; delta_t < 2000000; delta_t += PERIOD){
        digitalWrite(pin, HIGH);
        delayMicroseconds(UNLOCKED_HIGH);
        digitalWrite(pin, LOW);
        delayMicroseconds(PERIOD - UNLOCKED_HIGH);
    }*/
    
    int pwm = softPwmCreate(pin, 15, 100);
    
    for (int t = 0; t < 2000000; t+= PERIOD){
        softPwmWrite(pin, 24);
        delayMicroseconds(PERIOD);
    }
    logWrite("unlocked!");
}
