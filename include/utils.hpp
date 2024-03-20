#ifndef UTILS_REDISPLAY_HPP
#define UTILS_REDISPLAY_HPP

#include <fstream>
#include <string>
#include <iostream>
#include <filesystem>
#include <list>

// #TODO: Code custom type for reading a session file, name, exec, etc

std::string get_hostname(std::string file);
std::list<std::string> get_sessions();

#endif // UTILS_REDISPLAY_HPP