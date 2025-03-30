#include <cs50.h>
#include <stdio.h>

// Declaring prototypes
void print_row(int bricks);
void print_space(int space);

int main(void)
{
  // getting the heights of pyramids
  int height;
  do
  {
    height = get_int("Enter the height of pyramid: ");
  } while(height < 1 || height > 8);
  
  // loop to print pyramids of height
  for(int i = 0; i< height; i++)
  {
    print_space(height-i-1);
    print_row(i+1);
    // space between two pyramids
    printf(" ");
    print_row(i+1);
    printf("\n");
  }
}

// Function to print space for the left pyramid
void print_space(int space)
{
  for(int j = 0; j < space; j++)  
  {
    printf(" "); 
  }
}

// Function to print the bricks of pyramid
void print_row(int bricks)
{  
  for(int k = 0; k<bricks; k++) 
  {      
    printf("#");    
  }
}
