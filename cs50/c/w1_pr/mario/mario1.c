#include <cs50.h>
#include <stdio.h>

void print_row(int height, int i);

int main(void)
{
	// get the height of the pyramid
	int height;
	do
	{
		height = get_int("Enter the height: ");
	} while(height < 1 || height > 8);

	// Outer loop to print the rows of pyramid
	for(int i = 0; i < height; i++)
	{
    print_row(height, i);
  }
}


void print_row(int height, int i)
{
		//loop to print spaces before each brick
		for(int j = 0; j<height-1-i; j++)
		{
			printf(" ");
		}

		//loop to print bricks in each rows
		for (int k = 0; k < i+1; k++)
		{
			printf("#");
		}
		printf("\n");
	

}






