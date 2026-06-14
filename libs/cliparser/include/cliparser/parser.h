#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <types/command.h>

Command shell_parser();
void shell_cleaner(Command);

#endif