#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  struct node* next;
  int order_number;
  int qty;
}order;
typedef order *QueuePtr;

typedef struct 
{
  order *head,*tail;
  int size;
}Queue;

void enqueue(Queue* Q, int ord,int qty)
{
  QueuePtr new_node = (QueuePtr)malloc(sizeof(order));
  if(new_node)
  {
    new_node->next=NULL;
    new_node->order_number=ord;
 	  new_node->qty=qty;
    if((Q->head)==NULL)
      Q->head=new_node;
    else
      Q->tail->next=new_node;
    Q->tail=new_node;
    Q->size++;
  }
}

/*
  -----Menu-----
  1.Strawberry Cheesecake 50 Bath
  2.Red Velvet Cake 60 Bath
  3.Nutella Cake 80 Bath
*/

int dequeue(Queue *Q)
{
  int value;
 	QueuePtr t = Q->head;
  if(t)
  {
    switch(t->order_number)
    {
      case 1 : 
        printf("Order : Strawberry Cheesecake\n");
        value = 50*t->qty;
        break;
      case 2 : 
        printf("Order : Red Velvet Cake\n");
        value = 60*t->qty;
        break;
      case 3 :
        printf("Order : Nutella Cake\n");
        value = 80*t->qty;
        break;
      default:
          printf("--Don't have in menu--\n");
          value=0;
    }
    Q->head = t->next;
    if(Q->head==NULL)
	    Q->tail=NULL;
	  free(t);
    Q->size--;
	  return value;
  }
  printf("No queue\n");
  return 0;
}