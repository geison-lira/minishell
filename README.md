# Minishell

## Simple command line interface that emulates a linux shell

This project implements what I call a "miniature shell", a very simplified version of the linux shell. It can run programs by creating processes and redirect their input and output. To run a program you must specify its full path.

Some examples of code that the minishell correctly interprets:
```
cmd> /bin/ls
```
Executes the linux `ls` command.
```
cmd> ./my_dir/my_program
```
By assuming that the minishell executable is inside the root, it can run the my_program executable.
```
cmd> ./my_program arg1 arg2 arg3
```
The minishell can read the arguments passed to the program and execute it with them.
```
cmd> ./my_program < in.txt > out.txt
```
The minishell can redirect a program input or output using `<` and `>` operators respectively, it assumes that the argument right after the operators is the file that will receive or pass the arguments.
```
cmd> ./my_program arg1 arg2 < in.txt > out.txt
```
You can combine more complex commands like the one above.

The input/output operations can be written in any order, in the beggining or in the end of the command, there can be arguments in between them, the only restriction is to provide the file name right after the operators.

The minishell accepts 256 character long commands with up to 64 arguments.