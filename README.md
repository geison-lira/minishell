# Minishell

[![Release](https://img.shields.io/github/v/release/geison-lira/minishell)](https://github.com/geison-lira/minishell/releases)

A lightweight Command Line Interface (CLI) built in C that emulates core Linux shell functionalities, including process creation and I/O redirection.

## Latest Release

**v1.0.0** – Initial Release.

* [Release Notes](https://github.com/geison-lira/minishell/releases/tag/v1.0.0)

## Features & Examples

The Minishell accepts commands up to 256 characters long with up to 64 arguments. It supports absolute and relative executable paths, along with flexible I/O redirection placement.

### Standard Command Execution

```bash
cmd> /bin/ls
cmd> ./prog arg1 arg2
```

### I/O Redirection

The `<` and `>` operators redirect standard input and output. Input and output files can be placed anywhere in the command, provided they immediately follow the corresponding operator.

```bash
cmd> ./prog < in.txt > out.txt
cmd> ./dir/prog arg1 < in.txt arg2 > out.txt
```

## Getting Started

### Prerequisites

* Linux environment
* CMake
* Ninja build system
* GCC or Clang compiler

### Build and Run

#### 1. Clone the repository

```bash
git clone https://github.com/geison-lira/minishell.git
cd minishell
```

#### 2. Generate the build configuration

```bash
cmake -B build -G Ninja
```

#### 3. Compile the project

```bash
cmake --build build
```

#### 4. Run Minishell

```bash
./build/app/shell/minishell
```

> **Note:** To exit the shell, press `CTRL+C`.

## Architecture & Implementation

The architecture follows a three-stage pipeline that reads, parses, and executes user commands:

```text
[ User Input ]
       │
       ▼
   ( Prompt )
       │
       ▼
   ( Parser )
       │
       ▼
 [ Shell State ]
       │
       ▼
  ( Executor )
       │
       ▼
[ Linux Process ]
```

### 1. Prompt

A simple interface loop that manages the terminal session lifecycle, displays the `cmd>` prompt, and waits for user input.

### 2. Parser

Responsible for lexical analysis and semantic validation of raw user input.

* Tokenizes continuous input into an argument array.
* Removes shell control symbols from executable arguments.
* Enforces shell constraints such as maximum command length and argument count.
* Extracts input and output redirection targets.
* Produces a structured shell state consumed by the executor.

### 3. Executor

Translates the parser state into native Linux processes using POSIX system calls from `<unistd.h>`.

* **fork()** — Creates a child process for command execution.
* **dup2()** — Redirects standard input and output file descriptors.
* **execv()** — Replaces the child process image with the target executable.

## Project Structure

```text
minishell/
├── .vscode/
├── app/
│   └── shell/
│       ├── CMakeLists.txt
│       └── main.c
├── libs/
│   ├── cliexecutor/
│   │   ├── include/
│   │   │    └── cliexecutor/
│   │   │        └── executor.h
│   │   ├── CMakeLists.txt
│   │   └── executor.c
│   ├── cliparser/
│   │   ├── include/
│   │   │    └── cliparser/
│   │   │        └── parser.h
│   │   ├── CMakeLists.txt
│   │   └── parser.c
│   └── cliprompt/
│       ├── include/
│       │    └── cliprompt/
│       │        └── prompt.h
│       ├── CMakeLists.txt
│       └── prompt.c
├── .gitignore
├── CMakeLists.txt
└── README.md
```
