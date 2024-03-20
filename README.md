# Re:Display

A custom crafted Display Manager

---

This is a display manager I am coding to use for myself. It is being designed for Arch Linux with Hyprland, and for the moment is only being tested on that.

Heavily inspired by ly, and taking concepts from other display managers. ly was being problematic with my hyprland sessions, so I decided to try and solve this (it's not going to work).


## Installing

Clone this repo into wherever you want.

    git clone https://github.com/Debankle/Re-Display.git

From there, compile it using the makefile. Again, this has only been tested on my Arch Linux Hyprland environment for the time being

    make

Next, install the file. The makefile installs to /usr/bin.

    sudo make install

Finally, the systemd service file needs to be installed, and then begun.

    sudo make installsystemd

    sudo systemctl enable re-display.service

---

### Planning to do

1. ~~switch to tty2~~
2. ~~print keyboard input~~
3. systemd service file improvements
4. login system
5. ~~display sessions~~
6. choose session
7. custom TUI
8. config file
9. terminal args
10. hyprland specific launch/logout
0. come up with name


Work:
read session file
create session class
print session class details for each session
username password input print out after
PAM
launch Hyprland
propper logging of messages in the background