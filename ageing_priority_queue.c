// Ageing in priority queue

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define size 30

typedef struct node_tag 
{
	char[size] process_name;
	int priority; //range from 1-15
	struct node_tag* next;
}node;

node* newnode(char str[], int val)
{
	 node* new_node = (node*)malloc(sizeof(node));
	 strcpy(new_node->process_name, str);
	 new_node->priority = val;
	 new_node->next = NULL;
	 
	 return new_node;
}

void push(node** head, char str[], int val)
{
	node* start = *head;
	node* new_node = newnode(str, val);
	
	node *temp;
	
	if(start==NULL)
	{
		start = new_node;
		start->next = NULL;
	}
	
	if ((*head)->priority > p) 
	{ 
        new_node->next = *head; 
        (*head) = new_node;
	}
	
	while(start->next!=NULL && start->next->priority < new_node->priority)
	{
        start=start->next;
	}
	
	temp=start->next;
	start->next=new_node;
	new_node->next = temp;
	
}

int peek(node** head) 
{ 
    return (*head)->data; 
} 
   
node* pop(node** head) 
{ 
    node* temp = *head; 
    (*head) = (*head)->next; 
	node* retval = temp;
    free(temp); 
	
	while(head!=NULL)
	{
        if(head->priority!= 0)
            head->priority -=1;
		head=head->next;
	}		
} 

void list_process(node* head)
{
	printf("\t **PROCESS TABLE** \t \n");
	printf("Process name \t Priority \t \n");
	if(head==NULL)
	{
		printf("No pending processes \n");
	}
	else{
		
		while(head!=NULL)
		{
			printf("%s \t %d \t \n", head->process_name, head->priority);
			head=head->next;
		}
	}
}

void list_highest(node* head)
{
	printf("\t **PROCESS TABLE** \t \n");
	printf("Process name \t Priority \t \n");
	if(head==NULL)
	{
		printf("No pending processes \n");
	}
	else{
		int x = head->priority;
		while(head!=NULL && (head->priority==x))
		{
			printf("%s \t %d \t \n", head->process_name, head->priority);
			head=head->next;
		}
	}
}
	
void main()
{
	node* head;
	int c = -1;

    while(c != 0)
    {
		printf("1. Add a process \n");
		printf("2. Run the process queue \n");
		printf("3. Print process list \n");
		printf("4. Print highest priority tasks. \n");

        printf("Enter your choice :");
        scanf("%d",&c);
        getchar();

        switch(c)
        {
        case 1:
		

        case 0: printf("\n");
            break;
        default:printf("\nPlease choose a valid option\n");
        }

    }
	
	