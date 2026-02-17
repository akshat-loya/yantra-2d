/*
 * ====================================================================
 * Logger class defintions for basic logging functioanlity
 * // TODO : not thread safe yet
 * ====================================================================
 */

// TODO : logger to accept multiple arguments using variadic templates
// TODO : Think about making it a header style library or keeping the cpp
// TODO : Compile time and release build stripping of messages
// TODO : Segregation of engine vs editor logs

#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

#include "Logger.h"

/*
 * Colour and format codes for strings
 */
static constexpr const char* RED = "\033[31m";
static constexpr const char* GREEN = "\033[32m";
static constexpr const char* YELLOW = "\033[33m";
static constexpr const char* WHITE_FG_RED_BG = "\033[37;41m";
static constexpr const char* RESET = "\033[0m";

// Initialise the display level
Logger::Level Logger::m_dispLevel = Logger::Info;


void Logger::log(Level level, const std::string& mess)
/* =============
 * Main logging function
 */
{
    if(m_dispLevel > level)
        return;

    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::tm tm = *std::localtime(&now);

    const char* colour = "";
    const char* prefix = "";

    switch(level)
    {
        case Level::Info:
            colour = GREEN;
            prefix = "INFO: ";
            break;

        case Level::Warn:
            colour = YELLOW;
            prefix = "WARNING: ";
            break;

        case Level::Error:
            colour = RED;
            prefix = "ERROR: ";
            break;

        case Level::Fatal:
            colour = WHITE_FG_RED_BG;
            prefix = "FATAL: ";
            break;
    }

    std::cout << colour  
              << "[" << std::put_time(&tm, "%H:%M:%S") << "] "
              << prefix
              << mess 
              << RESET 
              << "\n";
}


/*
 * Interface wrappers exposed to users
 */

void Logger::info(const std::string& mess)
{
    log(Level::Info, mess);
}

void Logger::warn(const std::string& mess)
{
    log(Level::Warn, mess);
}

void Logger::error(const std::string& mess)
{
    log(Level::Error, mess);
}

void Logger::fatal(const std::string& mess)
{
    log(Level::Fatal, mess);
}

void Logger::setLevel(const Level level)
{
    Logger::m_dispLevel = level;
}