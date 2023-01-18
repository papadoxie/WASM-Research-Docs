#include <stdio.h>
#include <stdbool.h>

typedef void (*action_t)(void);

void vuln(void)
{
    static bool visited = false;
    if (!visited)
    {
        puts("This is the function you need to visit again");
        visited = true;
        return;
    }
    char buf[0x100];
    FILE *flag = fopen("flag.txt", "r");
    fread(buf, 1, 0x100, flag);
    puts(buf);
}

void func1(void)
{
    puts("This is function 1");
}

void func2(void)
{
    puts("This is function 2");
}

int main(void)
{
    action_t jump_table[] = {func1, func2};
    action_t vuln_ptr = vuln;
    vuln_ptr();
    int choice;
    puts("Choose a function to call");
    scanf("%d", &choice);
    jump_table[choice]();
    return 0;
}