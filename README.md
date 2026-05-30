# Minishell

## CLI to Emulate a Linux Shell

### The Project

This project implements what I call a "Miniature Shell", a very simplified version of the Linux Shell. It can run programs by creating processes and redirect their input and output. To run a program you must specify it's full path.

Some examples of code that the minishell correctly interprets:
* Execute the Linux `ls` command.
```
cmd> /bin/ls
```
---
* Assuming that the Minishell executable is in the same directory as the program `prog`, it can run the executable as follows.
```
cmd> ./prog
```
---
* The Minishell can read the arguments passed to the program and execute it with them.
```
cmd> ./prog arg1 arg2 arg3
```
---
* The Minishell can redirect a program I/O using `<` and `>` operators respectively, it assumes that the argument right after the operators is the file that will receive or pass the arguments.
```
cmd> ./prog < in.txt > out.txt
```
---
* You can combine commands to build more complex ones.
```
cmd> ./dir/prog arg1 arg2 < in.txt > out.txt
```
---
The I/O operations can be written in any order, in the beggining or in the end of the command, there can be arguments in between them, the only restriction is to provide the file name right after the operators.

The minishell accepts 256 character long commands with up to 64 arguments.

### Use the minishell
1. Clone the repository:
```
git clone https://github.com/geison-lira/minishell.git
```
2. Compile the code with CMake:
```
cmake --build build
```
3. Run the executable (the code below is executed from the root):
```
./build/app/shell/minishell
```

### Solution
The Minishell has 3 main modules, a prompt, a parser and an executor.

* Prompt

This is the module responsible to show the `cmd> ` in every new interaction the user starts, it's really just a printf.

* Parser

This module is responsible to get and interpret the user's command, it tokenizes the continuous command into the arguments, it checks the length and argument count of the command as well as handling the I/O redirection operators and flushing the input buffers. It generates a variable that represents the state of the shell, it encodes whether the command was syntatically correct, the I/O files and the arguments.

* Executor

This module takes the state variable produced by the parser and runs the program based on it. It uses the `unistd.h` library to access Linux system calls like the `fork()`, `execv()` and `dup2()`. The executor transforms the program binary into a Linux process, correctly passes the arguments and defines the I/O directions.

The Minishell runs in an infinite loop until the user hits `CTRL+C` to stop the process.
