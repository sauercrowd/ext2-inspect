#include "superblock.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int getData(unsigned char* data, int start, int size);

int sb_readFromRaw(superblock* sb, unsigned char* data, int offset){
	
	printf("State: %d\n", getData(data, 58, 2));
	printf("Magic: %04x\n", getData(data, 56, 2));


	return 0;
	int i;
	for(i=0;i<1024;i++){
		printf("%02x ", 0 | data[i]);
		if((i+1)%20==0) printf("\n");
	}
	printf("\n");
	return 0;

	unsigned char *test = malloc(sizeof(char)*4);
	test = "ABCD";
	printf("as char array: [%d, %d, %d, %d]\n", 
			(int) 'A', (int) 'B', (int) 'C', (int) 'D');
	printf("as unsigned: %d\n", getData(test, 0, 4));
	unsigned int ret = getData(test,0,4);
	printf("Back as char array: %d\n", (char) ret);
	sb->s_inodes_count = 0;
	return 0;
}

void sb_printInfo(superblock* sb){

}

unsigned int getData(unsigned char* data, int offset, int size){
	/*
	 *Iterate size bytes through the data array and create 
	 *an int from it, start with the least significant byte (obviously)
	 *
	 */
	unsigned int ret=0;
	int i;
	for(i=0;i<size;i++){
		ret |= (unsigned int) data[offset+i] << 8*i;
	}
	return ret;
}
