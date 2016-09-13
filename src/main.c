#include <argp.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#include "superblock.h"
#include "argparsing.h"

int main(int argc, char** argv){
	arguments args;
	
	//defaults
	args.verbose=0;

	parse(&args, argc, argv);
	
	printf("%s\n",args.verbose == 1 ? "VERBOSE" : "NON-VERBOSE");

	int fh = open("/home/jonas/Dokumente/03_uni/04_betriebssysteme/ext2fs.img",
		O_RDONLY);

	if(fh == -1){
		fprintf(stderr, "Could not open file.\n");
		return -1;
	}
	
	//reading first 2048 bytes to get to the superblock, located at an 1024 offset.
	unsigned char *file_buffer = malloc(1024);
	int read_res = pread(fh, file_buffer, 1024,1024);
	
	if(read_res == -1){
		fprintf(stderr, "Could not read 1024 bytes from file.\n");
		return -1;
	}


	superblock* sb = malloc(sizeof(superblock));
	sb_readFromRaw(sb, file_buffer, 0);

	free(file_buffer);
	close(fh);
	return 0;
}

