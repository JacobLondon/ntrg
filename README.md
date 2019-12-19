# NTRG NeT-hack RoGue-like
Roguelike game made to test my NCE and JLib libraries. Note that each library is statically linked.

# Cloning
```
# HTTPS
$ git clone https://github.com/JacobLondon/ntrg.git --recurse-submodules
# SSH
$ git clone git@github.com:/JacobLondon/ntrg.git --recurse-submodules
```

# Dependencies
```
# Clang
sudo apt install clang
# GNU Make
sudo apt install make
# NCurses
sudo apt install libncurses5-dev libncursesw5-dev
```

# Building
ONLY made for Linux, will also work with WSL (Windows Subsystem for Linux)
```
# build the system and the submodules
$ make
```

# Game
Run `./ntrg`. Press `wasd` to move, and `ctrl+c` or `ESC` to exit.
```
##########
#........#
#.@......#
#........#
#........#
#........#
#........#
#........#
#........#
##########
```