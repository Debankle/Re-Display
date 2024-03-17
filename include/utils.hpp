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

class Session {
  public:
    Session(std::string session_file);
    void begin_session();

  private:
    std::string name;
    std::string exec;
    std::string type;

    bool valid_session_file();
    void parse_session();

}

#endif // UTILS_REDISPLAY_HPP