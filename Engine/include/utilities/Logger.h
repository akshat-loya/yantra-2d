/* 
 * ====================================================================
 * Logger class declaration for basic logging functioanlity
 * ====================================================================
 */

#pragma once
#include <string>

class Logger
{
public:
    enum Level { Info, Warn, Error, Fatal };

private:
    static void log(Level level, const std::string& mess);
    static Level m_dispLevel;

public:
    static void info(const std::string& mess);
    static void warn(const std::string& mess);
    static void error(const std::string& mess);
    static void fatal(const std::string& mess);
    static void setLevel(const Level level);
};