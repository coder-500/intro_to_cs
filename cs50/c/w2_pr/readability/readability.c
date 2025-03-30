#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// function prototype
int get_grade(string text);

// main function
int main(void)
{
  // prompting user for text 
  string txt = get_string("Text: ");

  // getting grade using Coleman-Liau index
  int grade = get_grade(txt);

  // printing appropriate grade for the text 
  if (grade < 1)
  {
    printf("Before grade 1");
  }
  else if(grade >= 16)
  {
    printf("Grade 16+\n");
  }
  else
  {
    printf("Grade %i\n", grade);
  }
  
  return 0;
}

// function to calculate appropriate grade for a given text 
int get_grade(string text)
{
  int letter = 0;
  int word = 0;
  int sentence = 0;

  // looping through the text 
  for(int i = 0, len = strlen(text); i < len; i++)
  {
    // counting total number of letters in the text 
    if(isalpha(text[i]))
    {
      letter += 1;
    }
    // counting total number of spaces in the text 
      else if(text[i] == ' ')
    {
      word += 1;
    }
    // counting total number of sentences in the text 
      else if(text[i] == '.' || text[i] == '?' || text[i] == '!')
    {
      sentence += 1;
    }
  }
  // adding 1 to total number of spaces to get the total number of words in the text 
  word += 1;

// Coleman-Liau index
//  index = 0.0588 * L - 0.296 * S - 15.8
  float l = (letter/(float) word)*100;
  float s = (sentence/(float) word) * 100;
  int ind = round((0.0588 * l) - (0.296 * s) - 15.8);

  return ind;
}






