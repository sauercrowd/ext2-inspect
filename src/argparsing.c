#include "argparsing.h"
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


static error_t parse_opt(int key, char *arg, struct argp_state *state){
	struct arguments *arguments = state->input;
	switch(key){
		case 'v':
		        arguments->verbose = 1;
	                break;

	        case ARGP_KEY_ARG:
		        if(state->arg_num >= 2)
		                argp_usage(state);
	                arguments->args[state->arg_num] = arg;
	                break;
                default:
                        return ARGP_ERR_UNKNOWN;
        }
        return 0;
}
static struct argp argp = { options, parse_opt, args_doc, doc };

int parse(arguments* args, int argc, char** argv){
        argp_parse(&argp, argc, argv, 0, 0, args);
        return 0;
}



