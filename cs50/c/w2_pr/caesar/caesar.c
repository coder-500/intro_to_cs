#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototypes
bool digit_check(string key);
string rotate(string plaintext, int key);

// main function
int main(int argc, string argv[])
{
  // checking if user have entered any or >2 input
  if (argc != 2)
  {
    printf("Usage: ./caesar key\n");
    return 1;
  }
  // checking if the enter value is a digit 
  bool is_valid = digit_check(argv[1]);
  if(!is_valid)
  {
    printf("Usage: ./caesar key\n");
    return 1;
  }
  // converting string input to int 
  int key = atoi(argv[1]);
  
  // prompting user for input
  string plain = get_string("Plaintext:  ");
  
  // enciphering
  string cipher = rotate(plain, key);

  // printing output
  printf("Ciphertext: %s\n", cipher);

  return 0;
}

// function to check whether content of a string is numeric
bool digit_check(string key)
{
  for(int i = 0, len = strlen(key); i < len; i++)
  {
    if(!isdigit(key[i]))
    {
      return false;
    }
  }
  return true;
}


// function to encipher plaintext using caesar algo
string rotate(string plaintext, int key)
{
  string res = plaintext;
  // ci = (pi + k) % 26
  for(int i = 0, len = strlen(res); i < len; i++)
  {
    // checking if the character is alphabet
    if(isalpha(res[i]))
    {
      // checking case 
      if(isupper(res[i]))
      {
        // applying caesar algorithm
        res[i] = 'A' + ((res[i] - 'A') + key)%26;
      }
      else 
      {
        res[i] = 'a' + ((res[i] - 'a') + key)%26;
      }
      
    }
  }

  return res;
}







































