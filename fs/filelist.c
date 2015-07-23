/*************************************************************************//**
 *****************************************************************************
 * @file   fs/filelist.c
 * The file contains:
 *   - do_filelist()
 * @author OnClouds
 * @date   2010
 *****************************************************************************
 *****************************************************************************/

#include "type.h"
#include "stdio.h"
#include "const.h"
#include "protect.h"
#include "string.h"
#include "fs.h"
#include "proc.h"
#include "tty.h"
#include "console.h"
#include "global.h"
#include "keyboard.h"
#include "proto.h"

/*****************************************************************************
 *                                do_filelist
 *****************************************************************************/
/**
 * Show the list of files.
 * 
 * @return 0
 *****************************************************************************/
PUBLIC int do_filelist()
{
	int i, j;

	struct inode * dir_inode = root_inode;
	
	int dir_blk0_nr = dir_inode->i_start_sect;
	int nr_dir_blks = (dir_inode->i_size + SECTOR_SIZE - 1) / SECTOR_SIZE;
	int nr_dir_entries =
	  dir_inode->i_size / DIR_ENTRY_SIZE; /**
					       * including unused slots
					       * (the file has been deleted
					       * but the slot is still there)
					       */
	int m = 0;
	struct dir_entry * pde;

	printl("\ninode        filename\n");
	printl("============================\n");

	for (i = 0; i < nr_dir_blks; i++) {
		RD_SECT(dir_inode->i_dev, dir_blk0_nr + i);

		pde = (struct dir_entry *)fsbuf;		

		for (j = 0; j < SECTOR_SIZE / DIR_ENTRY_SIZE; j++,pde++) {

			printl("  %2d        %s\n", pde->inode_nr , pde->name );

			if (++m >= nr_dir_entries){
				printl("\n");
				break;
			}
		}
		if (m > nr_dir_entries) /* all entries have been iterated */
			break;
	}

	printl("============================\n");

	return 0;
}
