#include <cs50.h>
#include <math.h>
#include <stdio.h>

// function prototype 
string calculate_checksum(long card_num);
string get_card_details(long card_num, int len);
int get_digit_sum(int num);
int get_first_digits(long card_num);

// main function 
int main(void)
{
  // prompt user for input
  long card_num;
  do
  {
    card_num = get_long("Number: ");
  }
  while(card_num <= 0);

  // calculate checksum and get card details
  string card = calculate_checksum(card_num);
 
  // print result
  printf("%s\n", card);
}

// function to calculate checksum
string calculate_checksum(long card_num)
{
  long c_num = card_num;
  int num;
  int sum = 0, i = 0;
 
  // loop to go through all the digits of card number 
  while(floor(c_num)!=0)
  {
    // accessing each digits
    num = c_num % 10;
    // checking for even position from last
    if((i+1) % 2 == 0)
    {
      // multiplying by 2
      num *= 2;

      // getting sum of products' digits
      if(num >= 10)
      {
        sum += get_digit_sum(num);
      }
      else
      {
        sum += num;
      }
    }
    else
    {
      // getting sum of the digits that weren't multiplied by 2
      sum += num;
    }
    i++;
    c_num /= 10;
  }
  
  string card_details;
  // checking whether the number pass checksum
  if (sum % 10 == 0)
  {
    // finidng out what card it is
    card_details = get_card_details(card_num, i);
    return card_details;
  }
  return "INVALID";
}

// function to calculate sum of digits after multiplying by 2
int get_digit_sum(int num)
{
  int digit;
  int sum = 0;
  while (floor(num) != 0)
  {
    digit = num % 10;
    sum += digit;
    num /= 10;
  }
  return sum;
}

// function to get card details 
string get_card_details(long card_num, int len)
{
  long num = card_num;
  // getting the first 2 digits of the card num
  int first_digits = get_first_digits(num);
  
  // checking what card it is
  if ((first_digits == 34 || first_digits == 37) && len == 15)
  {
    return "AMEX";
  }
  else if ((first_digits == 51 || first_digits == 52 || first_digits == 53 || first_digits == 54 || first_digits == 55) && len == 16)
  {
    return "MASTERCARD";
  }
  else if (((first_digits / 10) == 4) && (len == 13 || len == 16))
  {
    return "VISA";
  }
  return "INVALID";
}

// function to get the first digits
int get_first_digits(long card_num)
{
  long num = card_num;

  // getting the first 2 digits
  while (num >= 100)
  {
    num /= 10;
  }
  return num;
}






























