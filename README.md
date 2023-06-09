# Simple_shell

This repository contains an implementation of a simple UNIX command interpreter in C. It was developed as part of the curriculum for the ALX School Full-Stack Software Engineering program.

## Functionality

The simple_shell is able to:

* Execute commands in interactive and non-interactive mode
* Execute commands with arguments
* Execute commands with and without the PATH

## File structure

The repository contains the following files:

- `main.h`: Header file containing all function prototypes and libraries used in the project.
- `main.c`: Contains the main loop of the shell.
- `parse_cmd.c`: Contains the function that parses the command line and the path.
- `execution.c`: Contains the functions that execute the commands.
- `functions1.c`: Contains some utils functions.
- `functions2.c`: Contains some utils functions.
- `functions3.c`: Contains some utils functions.
- `b_env.c`: Contains `env()` built-in.
- `b_exit.c`: Contains `exit()` built-in(without arguments).

## Usage

The simple_shell can be compiled with the following command:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

The shell can be run in interactive mode with the following command:

```
./hsh
```
![alt text](screenshots/one.png)

The shell can be run in non-interactive mode with the following command:

```
echo "command" | ./hsh
```
![alt text](screenshots/two.png)
## Authors

See [AUTHORS](./AUTHORS) for more information.
