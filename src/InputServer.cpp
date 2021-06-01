#include "InputServer.h"

InputServer* InputServer::get_singleton()
{
    if(InputServer::singleton != nullptr){
        return InputServer::singleton;
    } else {
        InputServer::singleton = new InputServer();
        return InputServer::singleton;
    }
}

InputServer::InputServer()
{
    InputServer::singleton = this;
}