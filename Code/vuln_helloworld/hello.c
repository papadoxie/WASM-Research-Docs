#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <emscripten.h>

int main(void)
{
	char hello[] = "Hello World\n";
    char *str = malloc(255);
    strcpy(str, "This is a test string");
    char buf[10];
    scanf("%s", buf); // Buffer Overflow
	printf("%s\n", buf);
	printf(hello);	// Format String
	printf("\n");
    printf("%s\n", str); // Buffer Overflow
	return 0;
}
