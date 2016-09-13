#include "argparsing.h"

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

int parse(arguments* args, int argc, char** argv){
	argp_parse(&argp, argc, argv, 0, 0, args);
	return 0;
}
