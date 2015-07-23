#include "type.h"
#include "stdio.h"
#include "sys/fs.h"

int main(int argc, char * argv[])
{
	printf("Show file list in [TTY #0].\n");
	flist();

	return 0;
}
