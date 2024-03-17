NAME = re-display
CC = g++
FLAGS = --std=c++17 -g 
FLAGS+= -pedantic -Wall -Wextra -Werror

OBJD = obj
BIND = bin
SRCD = src
RESD = res
INCD = include

INCL = -I$(INCD)

SRC = $(wildcard $(SRCD)/*.cpp)
SRC_OBJS = $(patsubst $(SRCD)/%.cpp, $(OBJD)/%.o, $(SRC))

.PHONY: final
final: $(BIND)/$(NAME)

$(BIND)/$(NAME): $(SRC_OBJS)
	mkdir -p $(@D)
	$(CC) $(INCL) $(FLAGS) $(SRC_OBJS) -o $@

$(OBJD)/%.o: $(SRCD)/%.cpp
	mkdir -p $(@D)
	$(CC) $(INCL) $(FLAGS) -c $< -o $@

run:
	cd $(BIND) && ./$(NAME)

install: $(BIND)/$(NAME)
	install -DZ $(BIND)/$(NAME) -t /usr/bin

installsystemd:
	install -DZ $(RESD)/re-display.service -m 644 -t /usr/lib/systemd/system/

uninstall:
	rm -rf /urs/bin/$(NAME)
	rm -rf /usr/lib/systemd/system/re-display.service

clean:
	rm -rf $(BIND) $(OBJD)