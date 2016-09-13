#ifndef __ARGS_H__
#define __ARGS_H__

#include <argp.h>

const char *argp_program_version = 
	"ext2-inspect 0.0.1";
const char * argp_program_bug_address = 
	"jonadev95@posteo.org";

static char doc[] = 
	"ext2-inspect -- a program for inspecting ext2 filesystems on the fly.";

static char args_doc[] = "COMMAND PATH";

static struct argp_option options[] = {
	{"verbose", 'v', 0, 0, "Produce verbose output"},
	{0}
};


struct arguments
{
	char *args[2];
	int verbose;
};
typedef struct arguments arguments;

int parse(arguments* args, int argc, char** argv);

static struct argp argp = { options, parse_opt, args_doc, doc };
#endif
