class Engine
{
public:
    int initialise();
    static unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader);
    static unsigned int compileShader(unsigned int type, const std::string& source);
};