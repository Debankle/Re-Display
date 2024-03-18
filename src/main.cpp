#include <iostream>
#include <string>
#include <list>

#include "utils.hpp"
#include "display.hpp"

int main() {

    std::string hostname = get_hostname("/etc/hostname");
    std::cout << hostname << std::endl;

    std::list<std::string> n = get_sessions();

    switch_tty();

    while(1) {
        std::string input;
        std::cin >> input;
        std::cout << input << std::endl;
    }

    return 0;
}
