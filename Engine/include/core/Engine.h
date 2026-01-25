#define GL_SILENCE_DEPRECATION

#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGL/gl3.h>
#include <GLFW/glfw3.h>

class Engine
{
public:

    Engine()  { std::cout << "Engine contructed..." << std::endl; };
    ~Engine() { std::cout << "Engine destructed..." << std::endl; };

    int initialise();
};