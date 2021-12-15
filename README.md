# Constraints
* Max runtime: 4s
* Max memory size: 400MB

# Checker
## Dependencies
checker.sh uses `valgrind` so make sure to install it using
on Debian-based distros
```sh
sudo apt-get install valgrind
```
on Arch-based distros
```sh
sudo pacman -S valgrind
```

## Usage
```sh
./checker.sh <compiled_program> <directory_where_inputs_are_stored>
```
