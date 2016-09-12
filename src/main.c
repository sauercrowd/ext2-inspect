#include <argp.h>
#include <stdio.h>
#include "superblock.h"

const char *argp_program_version = 
	"ext2-inspect 0.0.1";
const char * argp_program_bug_address = 
	"jonadev95@posteo.org";

const char doc[] = 
	"ext2-inspect -- a program for inspecting ext2 filesystems on the fly.";

int main(int argc, char** argv){
	struct argp args = {0,0,0,doc};
	argp_parse(&args, argc, argv, 0, 0,0);
	return 0;
}

