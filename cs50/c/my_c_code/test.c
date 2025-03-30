#include <cs50.h>
#include <stdio.h>


int main(void)
{
	string name = get_string("What's your name? ");
	int age = get_int("What's your age: ");

	printf("Hello, %s!\n", name);

	if (age < 18)
	{
		printf("You are %i years old. You can't drink\n", age);
	}
	else 
	{
		printf("Congrats! You are %i years old and you can drink!\n", age);
		
	}


}
