#ifndef __SUPERBLOCK_H__
#define __SUPERBLOCK_H__

struct superblock{
	unsigned int s_inodes_count;
	unsigned int s_blocks_count;
	unsigned int s_r_blocks_count;
	unsigned int s_free_blocks_count;
	unsigned int s_free_inodes_count;
	unsigned int s_first_data_block;
	unsigned int s_log_block_size;
	unsigned int s_log_frag_size;
	unsigned int s_blocks_per_group;
	unsigned int s_frags_per_group;
	unsigned int s_inodes_per_group;
	unsigned int s_mtime;
	unsigned int s_wtime;
	unsigned int s_mnt_count;
	unsigned int s_max_mnt_count;
	unsigned int s_magic;
	unsigned int s_state;
	unsigned int s_errors;
	unsigned int s_minor_rev_level;
	unsigned int s_lastcheck;
	unsigned int s_checkinterval;
	unsigned int s_creator_os;
	unsigned int s_rev_level;
	unsigned int s_def_resuid;
	unsigned int s_def_resgid;

	// EXT2_DYNAMIC_REV Specific

	unsigned int s_first_ino;
	unsigned int s_inode_size;
	unsigned int s_block_group_nr;
	unsigned int s_feature_compat;
	unsigned int s_feature_incompat;
	unsigned int s_feature_ro_compat;
	unsigned int s_uuid[4];
	unsigned int s_volume_name[4];
	unsigned int s_last_mounted[16];
	unsigned int s_algo_bitmap;

	// Performance Hints

	unsigned int s_prealloc_blocks;
	unsigned int s_prealloc_dir_blocks;
	unsigned int alignment; //TODO: What the heck is that?

	// Journaling Support

	unsigned int s_journal_uuid[4];
	unsigned int s_journal_inum;
	unsigned int s_journal_dev;
	unsigned int s_last_orphan;

	// Directory Indexing Support

	unsigned int s_hash_seed[4][4];
	unsigned int s_def_hash_version;
	unsigned int padding; //TODO: Maybe throw that out since unnecessary

	// Other options

	unsigned int s_default_mount_options;
	unsigned int s_first_meta_bg;
	unsigned int unused[190]; //TODO: Throw that out too?
};

typedef struct superblock superblock;

int sb_readFromRaw(superblock* sb, unsigned char* data, int offset);
void sb_printInfo(superblock* sb);

#endif
