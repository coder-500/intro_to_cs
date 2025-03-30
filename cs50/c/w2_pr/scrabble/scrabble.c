#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int POINTS[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};       

// function prototype
int compute_score(string word);
string get_result(int s1, int s2);

// main function
int main(void)
{
  // prompting players for input
  string word1 = get_string("Player 1: ");
  string word2 = get_string("Player 2: ");

  // calculating scores 
  int score1 = compute_score(word1);
  int score2 = compute_score(word2);

  // comparing scores and printing final result 
  string result = get_result(score1, score2);
  printf("%s\n", result);
}

// function to calculate scores 
int compute_score(string word)
{
  int score = 0;
  for (int i = 0, len = strlen(word); i < len; i++)
  {
    if(isupper(word[i]))
    {
      score += POINTS[word[i] - 'A'];
    }
       else if(islower(word[i]))
    {
      score += POINTS[word[i]- 'a'];
    }
  }
  return score;
}

// function to compare scores and retrieving result 
string get_result(int s1, int s2)
{
  if (s1 > s2)
  {
    return "Player 1 wins!";
  }
  else if(s2 > s1)
  {
    return "Player 2 wins!";
  }
  return "Tie!";
}


















