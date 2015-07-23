/*************************************************************************//**
 *****************************************************************************
 * @file   flist.c
 * @brief  seek()
 * @author Forrest Y. Yu
 * @date   Mon Apr 21 11:28:59 2010
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
#include "proto.h"


/*****************************************************************************
 *                                flist
 *****************************************************************************/
/**
 * Show the list of files.
 * 
 * @return  The resulting offset location as measured in bytes from the
 *          beginning of the file.
 *****************************************************************************/
PUBLIC PUBLIC int flist()
{
	MESSAGE msg;
	msg.type   = FILELIST;

	//printf("this is in flist()\n");

	send_recv(BOTH, TASK_FS, &msg);

	return msg.RETVAL;
}
