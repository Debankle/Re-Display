#include <iostream>
#include <string>
#include <list>

#include "utils.hpp"
#include "display.hpp"
#include "session.hpp"

int main() {

    std::string hostname = get_hostname("/etc/hostname");
    std::cout << hostname << std::endl;

    std::list<std::string> session_list = get_sessions();

    for (auto const& session : session_list) {
        Session s = Session(session);
        if (s.valid_session) {
            s.print_main();
        } else {
            std::cout << session << " is not a valid session." << std::endl;
        }
    }

    switch_tty();

    while(1) {
        std::string input;
        std::cin >> input;
        std::cout << input << std::endl;
    }

    return 0;
}
