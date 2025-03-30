#include <cs50.h>
#include <stdio.h>

// function prototype
int calculate_change(int cents, int coin);

int main(void)
{
  // declaring the value of each avilable coin
  const int QUARTER = 25;
  const int DIME = 10;
  const int NICKEL = 5;
  const int PENNY = 1;

  // Take user input
  int cents;
  do
  {
    cents = get_int("Change owed: ");
  }
  while(cents <= 0);
  
  // calculate quarter
  int quarters = calculate_change(cents, QUARTER);
  cents -= quarters * QUARTER;

  // calculate dime
  int dimes = calculate_change(cents, DIME);
  cents -= dimes * DIME;

  // calculate nickel 
  int nickels = calculate_change(cents, NICKEL);
  cents -= nickels * NICKEL;

  // calculate penny 
  int pennies = calculate_change(cents, PENNY);
  cents -= pennies * PENNY;

  // calculate total change
  int total = quarters + dimes + nickels + pennies;

  // print total number of coins needed
  printf("%i\n", total);

}


// calculate change 

int calculate_change(int cents, int coin)
{
  int change = 0;

  while(cents >= coin)
  {
    change++;
    cents -= coin;
  }
  return change;
}






