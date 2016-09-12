#include <argp.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

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

	int fh = open("/home/jonas/Dokumente/03_uni/04_betriebssysteme/ext2fs.img",
		O_RDONLY);
	if(fh == -1){
		//TODO: eror message
		return -1;
	}
	
	//reading first 2048 bytes to get to the superblock, located at an 1024 offset.
	unsigned char *file_buffer = malloc(2048);
	int read_res = read(fh, file_buffer, 2048);

	//just get the superblock, throw the bootloader stuff away.	
	unsigned char *buffer = malloc(1024);
	buffer = memcpy(buffer, &file_buffer[1024], 1024);
	free(file_buffer);

	superblock* sb = malloc(sizeof(superblock));
	sb_readFromRaw(sb, buffer, 0);

	close(fh);
	return 0;
}

