/*AUTHOR : SAHIL.A 2107
PROGRAM: COIN CHANGE.
DATE CREATED: 4TH JAN 2022
DATE MODIFIED: 5th JAN 2022
*/
// DS DEVELOPER

#include<stdio.h>
#include"2107_coin.h"

void count(int c[n][s], int table[], int n, int s)
{
  int temp1,temp2, i, j;
  //initialize the 1st row with one as the denomination
  for (i = 0; i <= s; i++)
  {
    c[n-1][i] = i;
  }
  //check for other denominations
  for (i = n-2; i >= 0; i--)
  {
    for (j = 0; j <= s; j++) 
    {
      //if the denomination is greater than the required value
      //then take the previous denominations count
      if (table[i] > j)
      {
        c[i][j] = c[i+1][j];
      }
      //else if the denomination is greater or equal
      //then first subract the den from the value and then add one
      //compare the least from the calculated value with the previous denominations
      //assign the least to that denomination
      else
      {
        if(c[i+1][j] < (1 + c[i][j - table[i]]))
        {
          c[i][j]=c[i+1][j];
        }
        else
        {
          c[i][j]=(1 + c[i][j - table[i]]);
        }
      }  
    }
  }
  //print
  printf("\n Smallest possible combinations for each denomination");
  printf("\ndenomination |  number of combinations");
  printf("\n-----------------------------------------");
  for (i = 0; i < n; i++) 
  {
    printf("\n    %d        |           %d", table[i], c[i][s]);
  }
  printf("\n");
}