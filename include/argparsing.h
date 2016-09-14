#ifndef __ARGS_H__
#define __ARGS_H__

#include <argp.h>

struct arguments
{
	char *args[2];
	int verbose;
};
typedef struct arguments arguments;

int parse(arguments* args, int argc, char** argv);

#endif
