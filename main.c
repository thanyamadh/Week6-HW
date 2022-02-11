#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Queue.h"

/*
  -----Menu-----
  1.Strawberry Cheesecake 50 Bath
  2.Red Velvet Cake 60 Bath
  3.Nutella Cake 80 Bath
*/

int main(int argc, const char * argv[]) 
{
  int i,x,no=1,cash=0;
  Queue Q;
  Q.head=NULL;
  Q.tail=NULL;
  Q.size=0;
  for(i=1;i<argc;i++)
  {
    if(strcmp(argv[i],"x")==0)
    {
      if(Q.head!=NULL)
      {
        printf("Cutsomer no.%d\n",no);
        no++;
      }
      x=dequeue(&Q);
      if(x!=0)
      {
        printf("You have to pay %d\n",x);
        while(cash<x)
        {
          printf("Cash : ");
          if(scanf("%u",&cash)){};
        }
        if(cash!=x)
        {
          cash=cash-x;
          printf("Change : %d\n",cash);
        }
        cash=0;
      }
      printf("===========================\n");
    }
    else 
    {
      enqueue(&Q, atoi(argv[i]),atoi(argv[i+1]));
      i++;
    }
  }
  printf("There are %d ppl left in queue.\n",Q.size);
  return 0;
}