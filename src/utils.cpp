#include "utils.hpp"

std::string get_hostname(std::string file) {
    std::string hostname;
    std::ifstream hostname_stream(file);
    if (!hostname_stream.is_open()) {
        std::cout << "could not read hostname" << std::endl;
        hostname = "hostname";
    } else {
        getline(hostname_stream,hostname);
    }
    hostname_stream.close();
    
    return hostname;
}

std::list<std::string> get_sessions() {
    std::list<std::string> sessions;
    std::string wayland_sessions_dir = "/usr/share/wayland-sessions";
    for (const auto &entry : std::filesystem::directory_iterator(wayland_sessions_dir)) {
        std::cout << entry.path() << std::endl;
    };
    return sessions;
}