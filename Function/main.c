#include <stdio.h>


void say_hello(void); //function declaration, prototyping

int main(void)
{
	say_hello();

	return 0;
}

void say_hello(void) //function definition, linker will find this definition and linking with declaration
{
	printf("Hello");
}