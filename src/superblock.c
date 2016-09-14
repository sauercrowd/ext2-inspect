#include "superblock.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int getData(unsigned char* data, int start, int size);

int sb_readFromRaw(superblock* sb, unsigned char* data, int offset){
	
	printf("State: %d\n", getData(data, 58, 2));
	printf("Magic: %04x\n", getData(data, 56, 2));
	printf("Inodes Count: %d\n", (unsigned int) getData(data, 0, 4));

	sb->s_inodes_count	= getData(data, 0, 4);
	sb->s_blocks_count	= getData(data, 4, 4);
	sb->s_r_blocks_count	= getData(data, 8, 4);
	sb->s_free_blocks_count = getData(data, 12, 4);
	sb->s_free_inodes_count = getData(data, 16, 4);

	printf("Free Inodes: %d\n", sb->s_free_inodes_count);

	sb->s_first_data_block	= getData(data, 20, 4);
	sb->s_log_block_size	= getData(data, 24, 4);
	sb->s_log_frag_size	= getData(data, 28, 4);
	sb->s_blocks_per_group	= getData(data, 32, 4);
	sb->s_frags_per_group	= getData(data, 36, 4);
	sb->s_inodes_per_group	= getData(data, 40, 4);
	sb->s_mtime		= getData(data, 44, 4);
	sb->s_wtime		= getData(data, 48, 4);
	sb->s_mnt_count		= getData(data, 52, 2);
	sb->s_max_mnt_count	= getData(data, 54, 2);
	sb->s_magic		= getData(data, 56, 2);
	sb->s_state		= getData(data, 58, 2);
	sb->s_errors		= getData(data, 60, 2);
	sb->s_minor_rev_level	= getData(data, 62, 2);
	sb->s_lastcheck		= getData(data, 64, 4);
	sb->s_checkinterval	= getData(data, 68, 4);
	sb->s_creator_os	= getData(data, 72, 4);
	sb->s_rev_level		= getData(data, 76, 4);
	sb->s_def_resuid	= getData(data, 80, 2);
	sb->s_def_resgid	= getData(data, 82, 2);
	
	sb->s_first_ino		= getData(data, 84, 4);
	sb->s_inode_size	= getData(data, 88, 2);
	sb->s_block_group_nr	= getData(data, 90, 2);
	sb->s_feature_compat	= getData(data, 92, 4);
	sb->s_feature_incompat	= getData(data, 96, 4);
	sb->s_feature_ro_compat	= getData(data, 100, 4);
	
	/*
	sb->s_uuid		= getData(data, 104, 16);
	sb->volume_name		= getData(data, 120, 16);
	sb->s_last_mounted	= getData(data, 136, 64);
	sb->s_algo_bitmap	= getData(data, 200, 4);
	*/

	sb->s_prealloc_blocks	= getData(data, 204, 1);
	sb->s_prealloc_dir_blocks
				= getData(data, 205, 1);
	/* alignment? */

	/*
	sb->s_journal_uuid	= getData(data, 208, 16);
	*/
	sb->s_journal_inum	= getData(data, 224, 4);
	sb->s_journal_dev	= getData(data, 228, 4);
	sb->s_last_orphan	= getData(data, 232, 4);

	/*
	sb->hash_seed		= getData(data, 236, 16);
	*/
	sb->s_def_hash_version	= getData(data, 252, 1);
	/*
	sb->padding		= getData(data, 253, 3);
	*/

	sb->s_default_mount_options 
				= getData(data, 256, 4);
	sb->s_first_meta_bg	= getData(data, 260, 4);
	/* unused? */

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
