#ifndef SESSION_REDISPLAY_HPP
#define SESSION_REDISPLAY_HPP

// TODO: Decide whether it is session or desktop
// Folder is sessions, choose which session to
// launch, but each file is a desktop file
// doesn't matter for now because I know

// TODO: this is just basic hardcoded parsing
// should write some proper arg parsing at some point
// some key element dict type that manages all args
// actually shouldn't be too hard
// std::map off the top of my head
// would make it better to write session specific
// parsers if all the code is in a map
// ok yeah I'll do that

#include <iostream>
#include <string>
#include <map>
#include <fstream>

class Session {
    public:
    Session(std::string session_file);
    void begin_session();
    void print();
    void print_main();

    bool valid_session;

    private:
    std::map<std::string, std::string> args;
};

#endif // SESSION_REDISPLAY_HPP