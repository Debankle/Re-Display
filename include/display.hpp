#ifndef DISPLAY_REDISPLAY_HPP
#define DISPLAY_REDISPLAY_HPP

#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/vt.h>

void switch_tty();

#endif // DISPLAY_REDISPLAY_HPP