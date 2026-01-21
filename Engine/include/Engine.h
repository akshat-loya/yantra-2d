#include <iostream>

class Engine
{
public:
    Engine() { std::cout << "Engine contructed..." << std::endl; };
    ~Engine() { std::cout << "Engine destructed..." << std::endl; };
};