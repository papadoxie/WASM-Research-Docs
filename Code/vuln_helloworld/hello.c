#include <stdio.h>
#include <emscripten.h>

int main(void)
{
	char hello[] = "Hello World\n";
	char buf[10];
	scanf("%s", buf); // Buffer Overflow
	printf("%s\n", buf);
	printf(hello);	// Format String
	printf("\n");
	return 0;
}
