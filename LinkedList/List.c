#include "List.h"
void cleanUp(List *list)
{
     Node* tp = list->head;
     Node* prev = tp;
     while(tp->next)
     {
     prev = tp;
     tp = tp->next;
     free(prev);
     }
     free(list);
     return;
}

List *flip(List *list)
{
	Node *temp = list->head;
	List *newList = (List*) malloc(sizeof(List));
	newList->head->val = temp->val;
	newList->head->next = 0;
	while(temp)
	{
		//temp one in here to be the iter
		//sets its value
		//grabs the next
		//moves along and resets itself
	}
}

void add(List *list, int val)
{
     list->size++;
     //if theres no list or we're pushing a value onto head
     if(list->head == 0)
	   addToHead(list, val);
     else if(val < list->head->val)
	   addToHead(list, val);
     else
     {     
		 Node* newNode = (Node*) malloc(sizeof(Node*));
		 newNode->val = val;
		 Node* curr = list->head;
		 
		 while(curr->next)
		 {
                 if(val >= curr->val && val <= curr->next->val)
                 {                   
			      newNode->next = curr->next;
			      curr->next = newNode;   
			      return;     
                 }
                 curr = curr->next;    
         }
	     newNode->next = 0;
	     curr->next = newNode;
     }     
}

void add_b(List *list, int val)
{
	int min = 0, mid = 0, max = 0;
	bool searching = true;
	if(list->head)
		min = list->head->val;
	max = list->size;
	mid = max / 2;
	while(searching)
	{
		if(val < mid)
		{
			max = mid;
			mid = max / 2;
		}
		else if(val == mid)
		{
			searching = false;
		}
		else if(val > mid)
		{
			min = mid;
			mid = (max - min + 1) / 2;
		}
	}
}

void addToHead(List *list, int val)
{
     Node *newNode = (Node*) malloc(sizeof(Node*));
     newNode->val = val;
     newNode->next = 0;
     
     if(!list->head)
         list->head = newNode;
     else
     {
         //push new node onto the head
         newNode->next = list->head;
         //set head to new node
         list->head = newNode;
     }                  
}

void printList(List *list)
{
     Node* tp = list->head;
     while(tp->next)
     {
             printf("%d\n", tp->val);
             tp = tp->next;
     }
     printf("\n");
}
