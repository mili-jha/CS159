/* Programmers and Purdue Email Addresses:
 *  1. jha19@purdue.edu
 *  2. gwhitis@purdue.edu
 *  3. npaulett@purdue.edu
 *
 *  Lab #: 09
 *
 *  Academic Integrity Statement:
 *
 *  We have not used source code obtained from any other unauthorized source,
 *  either modified or unmodified.  Neither have we provided access to our code
 *  to another. The project we are submitting is our own original work.
 *
 *  Day, Time, Location of Lab: Tuesday, October 16, 2018. 7:30-9:20 AM. SC 189
 *
 *  Program Description:
 *
 ***************************************************************************/
 #include <stdio.h>
 #include <math.h>

int countNumber(int, int);
void input(int *, int *, int *, int *);
void results(int, int, int, int);
int findLoc(int, int, int, int);

int main(void)
{
  //Local Declarations
  int value; //integer value entered by user
  int digit1; //digit 1 entered by user
  int digit2; //digit 2 entered by user
  int digit3; //digit 3 enterd by user
  int count1; //number of times digit 1 is in the integer
  int count2; //number of times digit 2 is in the integer
  int count3; //number of times digit 3 is in the integer
  int combo; //total number of possible cominations of the three digits in the integer

  //Statements
  input(&value, &digit1, &digit2, &digit3);
  count1 = countNumber(digit1, value);
  count2 = countNumber(digit2, value);
  count3 = countNumber(digit3, value);
  combo = findLoc(value, digit1, digit2, digit3);
  results(count1, count2, count3, combo);

  return(0);
}


void input(int *val, int *d1, int *d2, int *d3)
{
  do {
    printf("Enter the integer value -> ");
    scanf("%d", val);
    if(*val < 0)
    {
      printf("Error! Non-negative values only!!\n");
    }
    else if(*val > 0 && *val < 100)
    {
      printf("Error! Minimum integer is 100!\n");
    }
  } while(((*val < 0) || (*val > 0 && *val < 100)));


  while(*d1 <= 0 || *d1 >= 10)
  {
    printf("Enter digit #1 -> ");
    scanf("%d", d1);
    if(*d1 <= 0)
    {
      printf("Error! Digit must be greater than zero!!\n");
    }
    else if(*d1 >= 10)
    {
      printf("Error! Digit must be less than ten!!\n");
    }
  }

  while(*d2 <= 0 || *d2 >= 10)
  {
    printf("Enter digit #2 -> ");
    scanf("%d", d2);
    if(*d2 <= 0)
    {
      printf("Error! Digit must be greater than zero!!\n");
    }
    else if(*d2 >= 10)
    {
      printf("Error! Digit must be less than ten!!\n");
    }
  }

  while(*d3 <= 0 || *d3 >= 10)
  {
    printf("Enter digit #3 -> ");
    scanf("%d", d3);
    if(*d3 <= 0)
    {
      printf("Error! Digit must be greater than zero!!\n");
    }
    else if(*d3 >= 10)
    {
      printf("Error! Digit must be less than ten!!\n");
    }
  }

}

int countNumber(int num, int n)
{
  int count = 0;

  while (n > 0)
  {
    if ((n % 10) == num)
    {
      count += 1;
    }

    n /= 10;
  }

  return (count);
}

int findLoc(int number, int d1, int d2, int d3)
{
  int a;
  int b;
  int c;
  int val = number;
  int count = 0;

  for (a = val; a != 0; a /= 10)
  {
    if (val % 10 == d3)
    {
      val /= 10;
      for (b = val; b != 0; b /= 10)
      {
        if (val % 10 == d2)
        {
          val /= 10;
          for (c = val; c != 0; c /= 10)
          {
            if (val % 10 == d1)
            {
              count += 1;
            }
          }
        }
      }
    }
  }

  return (count);
}

void results(int countV1, int countV2, int countV3, int combo)
{
  printf("\nDigit Counts: %d %d %d\n", countV1, countV2, countV3);
  printf("Possible Cominations: %d\n", combo);

  return;
}
