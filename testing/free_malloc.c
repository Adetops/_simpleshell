#include <stdarg.h>
#include "fuji.h"


/**
* free_cptrn - frees n amounts of strings
* @status: the status to exit with
* @n: the number of strings to free
*/
void free_cptrn(int status, const unsigned int n, ...)
{
	unsigned int i;
	va_list args;
	char *ptr;

	va_start(args, n);


	for (i = 0; i < n; i += 1)
	{
		ptr = va_arg(args, char *);
		free(ptr);
	}

	va_end(args);
	if (status == 99)
		return;
	exit(0);
}

/**
* free_array - frees an array of char pointers
* @array: a pointer to the array of chars
*/
void free_array(char **array)
{
	int i;

	if (!array)
		exit(0);
	i = 0;

	while (array[i])
	{
		free(array[i]);
		i += 1;
	}
	free(array);
}
