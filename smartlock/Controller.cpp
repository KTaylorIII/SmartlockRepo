#include "Controller.h"

Controller::Controller(){

}
Controller::~Controller(){

}

void Controller::unlock(){
    Lock lock = Lock();
    lock.unlock(CONTROL_PIN);
}

void Controller::lock(){
    Lock lock = Lock();
    lock.lock(CONTROL_PIN);
}
