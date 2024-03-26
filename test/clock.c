#include <stdio.h>
#include <limits.h>
#include <sys/time.h>
#include <time.h>

void	function_1(void)
{
	int a = INT_MAX;

	while (a != 0)
		a--;
}

int main(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	printf("Start = %li\n", tv.tv_sec);

	function_1();

	gettimeofday(&tv, NULL);
	printf("End = %li\n", tv.tv_sec);
}

int ft_strlen(char *str)
{
	int i = 0
	
}
