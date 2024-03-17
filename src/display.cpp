#include "display.hpp"


// TODO: Error handling
void switch_tty() {
    int fd = open("/dev/tty2", O_RDWR);
    ioctl(fd, VT_ACTIVATE, 2);
    ioctl(fd, VT_WAITACTIVE, 2);

    close(fd);
}