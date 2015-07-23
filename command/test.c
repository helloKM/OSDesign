
#include "stdio.h"






int my_atoi(const char *s)
{	
	int num,i;
	char ch;
	num=0;
	for(i=0;i<strlen(s);i++)
	{
		ch=s[i];
		if(ch<'0' || ch>'9')
			break;
		num=num*10+(ch-'0');
	}
	return num;
}






//Ö÷º¯Êý£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡


int main(int argc, char* argv[])
{	
	
	char tty_name[] = "/dev_tty0";
	char rdbuf[128];
	int fd_stdin  = open(tty_name, O_RDWR);
	int select=0;
	int n;
	
	n = read(fd_stdin,rdbuf,80);
	rdbuf[n] = 0;
	printf(rdbuf);
	select=my_atoi(rdbuf);
	
	printf("%d",select);
	return 0;
}




