#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int value = 5;
	const int MAX_BUFFER_SIZE = 8;
	char buffer_one[MAX_BUFFER_SIZE], buffer_two[MAX_BUFFER_SIZE];

	strncpy(buffer_one, "one", MAX_BUFFER_SIZE); /* put "one" into buffer_one */
	strncpy(buffer_two, "two", MAX_BUFFER_SIZE); /* put "two" into buffer_two */

	// Insert Null Terminators
	buffer_one[MAX_BUFFER_SIZE] = '\0';
	buffer_two[MAX_BUFFER_SIZE] = '\0';

	printf("[BEFORE] buffer_two is at %p and contains \'%s\'\n", &buffer_two, buffer_two);
	printf("[BEFORE] buffer_one is at %p and contains \'%s\'\n", &buffer_one, buffer_one);
	printf("[BEFORE] value is at %p and is %d (0x%08x)\n", &value, value);

	//If we dont set this running with no argument will cause a segfault
	if(argv[1]==NULL) {
		argv[1] = "";
	}

	printf("\n[STRCPY] copying %d bytes into buffer_two\n\n",  strlen(argv[1]));
	strncpy(buffer_two, argv[1], MAX_BUFFER_SIZE); /* copy first argument into buffer_two */

	printf("[AFTER] buffer_two is at %p and contains \'%s\'\n", buffer_two, buffer_two);
	printf("[AFTER] buffer_one is at %p and contains \'%s\'\n", buffer_one, buffer_one);
	printf("[AFTER] value is at %p and is %d (0x%08x)\n", &value, value, value);
}
