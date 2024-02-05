#include <stdio.h>
#include <errno.h>

int main(void)
{
	
	errno = 1;
	perror("error");
	
	char *str = strerror(1);
	printf("%s",str);
	
	
	return 0;
}