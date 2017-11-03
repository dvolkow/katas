#include <stdio.h>
#include <string.h>
#define MAX_SIZE 1000

typedef unsigned int uint;

int main() 
{
	char buffer[MAX_SIZE] = {' '};
	char rev[MAX_SIZE] = {' '};
	uint length = 0;

	scanf("%s", buffer);
	length = strlen(buffer);

	for (uint i = 0; i < length; ++i)
		rev[i] = buffer[length - 1 - i];

	printf("%s\n", rev);
}
