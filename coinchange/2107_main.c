/*AUTHOR : SAHIL.A 2107
PROGRAM: COIN CHANGE. main.
DATE CREATED: 4TH JAN 2022
DATE MODIFIED: 5th JAN 2022
*/
// DS DEVELOPER

#include<stdio.h>
#include"2107_coin.h"

int main()
{
  printf("\nEnter the total no. of denominations");
  scanf("%d", &n);
  for(i = 0; i < n; i++)
  {
    printf("\n%d  =  ", i+1);
    scanf("%d", &table[i]);
  }
  printf("\nEnter the sum");
  scanf("%d", &s);
  count(c, table, n, s);
}