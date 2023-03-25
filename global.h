#ifndef GLOBAL_H
#define GLOBAL_H

#include "monty.h"

/**
  *struct matatu_s - variables -args, file, line content
  *@arg: value
  *@line_input: content to read
  *@file : pointer to monty file
  *Description variables that carries values throughout the program
  */
typedef struct matatu_s
{
	char *arg;
	FILE *file;
	char *line_input;
}mat_t;

extern mat_t mat;

#endif

