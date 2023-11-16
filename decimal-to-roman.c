#include <stdio.h>
#include <string.h>

char *decimalToRoman(int decimalNumber, char finalString[]);

int reduceNumber(int *number, int numToReduce);

int main(void)
{
  int decimalNumber;
  char romanString[10];
  decimalToRoman(5200, romanString);
  printf("%s\n", romanString);

  return 0;
}

char *decimalToRoman(int decimalNumber, char finalString[])
{
  // Max number is 3999 condition.
  int number = decimalNumber;
  if (number > 3999)
  {
    printf("O maior número que se pode representar é 3999.\n");
    number = 3999;
  }
  char romanNums[13][3] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
  int finalStringIndex = 0;

  // M (1000) -> can happen up to three times
  int thousands = reduceNumber(&number, 1000);
  if (thousands >= 1)
  {
    for (int i = 0; i < thousands; i++)
    {
      finalString[finalStringIndex] = romanNums[0][0];
      finalStringIndex++;
    }
  }
  finalString[finalStringIndex] = '\0';

  // CM (900) -> Can only happen once
  int nineHundred = reduceNumber(&number, 900);
  if (nineHundred == 1)
  {
    for (int i = 0; i < strlen(romanNums[1]); i++)
    {
      finalString[finalStringIndex] = romanNums[1][i];
      finalStringIndex++;
    }
  }
  finalString[finalStringIndex] = '\0';

  // D (500) -> Can only happen once
  int fiveHundred = reduceNumber(&number, 500);
  if (fiveHundred == 1)
  {
    finalString[finalStringIndex] = romanNums[2][0];
    finalStringIndex++;
  }
  finalString[finalStringIndex] = '\0';

  // CD Can only happen once
  int fourHundred = reduceNumber(&number, 400);
  if (fourHundred == 1)
  {
    for (int i = 0; i < strlen(romanNums[3]); i++)
    {
      finalString[finalStringIndex] = romanNums[3][i];
      finalStringIndex++;
    }
  }
  finalString[finalStringIndex] = '\0';

  // C (100) -> Can happen up to three times:
  int hundreds = reduceNumber(&number, 100);
  for (int i = 0; i < hundreds; i++)
  {
    finalString[finalStringIndex] = romanNums[4][0];
    finalStringIndex++;
  }
  finalString[finalStringIndex] = '\0';

  // L (90) -> Can only happen once
  int ninety = reduceNumber(&number, 90);
  if (ninety == 1)
  {
    for (int i = 0; i < strlen(romanNums[5]); i++)
    {
      finalString[finalStringIndex] = romanNums[5][i];
      finalStringIndex++;
    }
  }
  finalString[finalStringIndex] = '\0';

  // 50 (L) -> Can only happen once
  int fifty = reduceNumber(&number, 50);
  if (fifty == 1)
  {
    finalString[finalStringIndex] = romanNums[6][0];
    finalStringIndex++;
  }
  finalString[finalStringIndex] = '\0';

  // 40 (XL) -> Can only happen once
  int fourty = reduceNumber(&number, 40);
  if (fourty == 1)
  {
    for (int i = 0; i < strlen(romanNums[7]); i++)
    {
      finalString[finalStringIndex] = romanNums[7][i];
      finalStringIndex++;
    }
  }
  finalString[finalStringIndex] = '\0';

  // 10 (X) -> Can happen up to three times
  int ten = reduceNumber(&number, 10);
  if (ten >= 1)
  {
    for (int i = 0; i < ten; i++)
    {
      finalString[finalStringIndex] = romanNums[8][0];
      finalStringIndex++;
    }
  }
  finalString[finalStringIndex] = '\0';

  // 9 (IX) can only happen once
  int nine = reduceNumber(&number, 9);
  if (nine == 1)
  {
    for (int i = 0; i < strlen(romanNums[10]); i++)
    {
      finalString[finalStringIndex] = romanNums[9][i];
      finalStringIndex++;
    }
  }
  finalString[finalStringIndex] = '\0';

  // 5 (V) -> Can only happen once
  int five = reduceNumber(&number, 5);
  if (five == 1)
  {
    finalString[finalStringIndex] = romanNums[10][0];
    finalStringIndex++;
  }
  finalString[finalStringIndex] = '\0';

  // 4 (IV) -> Can only happen once
  int four = reduceNumber(&number, 4);
  if (four == 1)
  {
    for (int i = 0; i < strlen(romanNums[11]); i++)
    {
      finalString[finalStringIndex] = romanNums[11][i];
      finalStringIndex++;
    }
  }
  finalString[finalStringIndex] = '\0';

  // Can happen up to three times
  int one = reduceNumber(&number, 1);
  if (one >= 1)
  {
    for (int i = 0; i < one; i++)
    {
      finalString[finalStringIndex] = romanNums[12][0];
      finalStringIndex++;
    }
  }
  finalString[finalStringIndex] = '\0';

  return finalString;
}

int reduceNumber(int *number, int numToReduce)
{
  int counter = 0;
  while (*number >= numToReduce)
  {
    *number -= numToReduce;
    counter++;
  }
  return counter;
}
