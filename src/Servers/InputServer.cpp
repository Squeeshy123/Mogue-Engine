#include "InputServer.h"
#include "ServerManager.h"
namespace Mogue{
    InputServer* InputServer::singleton = nullptr;

    InputServer* InputServer::get_singleton() {
        if(InputServer::singleton != nullptr){
            return InputServer::singleton;
        } else {
            InputServer::singleton = new InputServer();
            return InputServer::singleton;
        }
    }

    void InputServer::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        // run press key functionality here
        printf("%i\n", key);
    }

    bool InputServer::get_key_down(int keycode) {
        
        if (glfwGetKey(ServerManager::get_window_server()->get_window(), keycode) == GLFW_PRESS)
        {
            return true;
        }
        return false;
    }

    void InputServer::initialize(){
        glfwSetKeyCallback(WindowServer::get_singleton()->get_window(), &InputServer::key_callback);
    }

    void InputServer::tick(){
        glfwPollEvents();
    }


    InputServer::InputServer() {
        InputServer::singleton = this;
    }
}