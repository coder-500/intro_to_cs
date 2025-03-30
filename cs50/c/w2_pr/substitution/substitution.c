#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// function prototype
bool validate_key(string key);
string encrypt(string plaintext, string k);

// main function 
int main(int argc, string argv[])
{
  // making sure user provided right numbers of inputs
  if(argc != 2)
  {
    printf("Usage: ./substitution KEY\n");
    return 1;
  }
  // making sure if the key size is accurate
  else if(strlen(argv[1]) != 26)
  {
    printf("Key must contain 26 characters\n");
    return 1;
  }
  // further validating the key 
  bool is_valid = validate_key(argv[1]);

  if(!is_valid)
  {
    printf("Key must contain only alphabets and duplicates are not allowed!\n");
    return 1;
  }

  // prompting user for input 
  string plaintxt = get_string("Plaintext:  ");
  // enciphering plaintext
  string ciphertxt = encrypt(plaintxt, argv[1]);
  // printing ciphertext
  printf("Ciphertext: %s\n", ciphertxt);

  return 0;
}

// function to check if the key contains only alphabets and does not contain duplicates 
bool validate_key(string key)
{
  // looping through each characters
  for(int i = 0, len = strlen(key); i < len; i++)
  {
    // checking for non alphabet characters
    if(!isalpha(key[i]))
    {
      return false;
    }

    // checking if the key doesn't contain duplicates
    for(int j = i+1; j < len; j++)
    {
      if(tolower(key[i]) == tolower(key[j]))
      {
        return false;
      }
    }
  }
  return true;
}


// function to encipher plaintext using substitution algorithm
string encrypt(string plaintext, string k)
{
  string res = plaintext;
  // looping through each character of the plaintext
  for(int i = 0, len = strlen(res); i < len; i++)
  {
    // checking for alphabets
    if(isalpha(res[i]))
    {
      // preserving case
      if(isupper(res[i]))
      {
        // applying substitution 
        res[i] = toupper(k[res[i]-'A']);
      }
      else
      {
        // applying substitution
        res[i] = tolower(k[res[i]-'a']);
      }
    }
  }
  return res;
}








































