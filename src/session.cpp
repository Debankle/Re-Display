#include "session.hpp"

Session::Session(std::string session_file) {
    std::ifstream session_stream(session_file);
    std::cout << session_file << std::endl;
    if (!session_stream.is_open()) {
        Session::valid_session = false;
        std::cout << "Could not open " << session_file << std::endl;
        return;
    }
    std::string line;
    std::getline(session_stream, line);
    if (!(line == "[Desktop Entry]")) {
        std::cout << session_file << " is missing [Desktop Entry] declaration. Cannot be sure it is a valid file." << std::endl;
        Session::valid_session = false;
        return;
    } else {
        int counter = 1;
        while (std::getline(session_stream, line)) {
            counter++;
            size_t pos = line.find("=");
            if (pos == std::string::npos) {
                std::cout << "Missing an equals on line " << counter << std::endl;
                Session::valid_session = false;
                return;
            } else {
                std::string key = line.substr(0,pos);
                std::string value = line.substr(pos+1);
                Session::args[key] = value;
            }
        }
    }
    Session::valid_session = true;
}

void Session::print() {
    for (const auto &pair : Session::args) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }
}

void Session::print_main() {
    std::cout << "Name: " << Session::args["Name"] << std::endl;
    std::cout << "Exec: " << Session::args["Exec"] << std::endl;
    std::cout << "Type: " << Session::args["Type"] << std::endl;
    std::cout << "TryExec: " << Session::args["TryExec"] << std::endl;
}

void Session::begin_session() {
    std::cout << Session::args["Exec"] << std::endl;
}
