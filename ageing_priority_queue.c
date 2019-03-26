// Ageing in priority queue

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define size 30

typedef struct node_tag 
{
	char process_name[size];
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
	
	if ((*head)->priority > val) 
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

void peek(node** head) 
{ 
    if((*head)==NULL)
		printf("The process queue is empty. \n");
    else{
		printf("Process name \t Priority \t \n");
		printf("%s \t %d \t \n", (*head)->process_name, (*head)->priority);
	}
} 
   
void pop(node** head) 
{ 
    if((*head)==NULL)
		return;
    else{
    node* temp = *head; 
	printf("The following process will be marked completed : \nProcess name \t Priority \t \n");
    printf("%s \t %d \t \n", temp->process_name, temp->priority);
    (*head) = (*head)->next; 
    free(temp); 
	
	node* start = *head;
	
	while(start!=NULL)
	{
        if(start->priority!= 0)
            start->priority -=1;
		start=start->next;
	}	
	}	
} 

void age_queue(node** head)
{
	node *start = *head;
	if(start == NULL)
		printf("The process queue is empty \n");
	else{
		while(start!=NULL)
	{
        if(start->priority!= 0)
            start->priority -=1;
		start=start->next;
	}
	printf("The queue has been aged. \n ");
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
	node* head = NULL;
	char str[size];
	int p;
	int c = 0;

    while(c != 7)
    {
		printf("1. Add a process \n");
		printf("2. Run the process queue (pop) \n");
		printf("3. Print process list \n");
		printf("4. Print highest priority processes. \n");
		printf("5. View current highest priority process. \n");
		printf("6. Age the process queue. \n");
		printf("7. Exit the program. \n");	

        printf("Enter your choice :");
        scanf("%d",&c);
        getchar();

        switch(c)
        {
        case 1:
		{
			printf("Enter the process name : ");
			scanf("%s", str);
            printf("Enter its priority : ");
            scanf("%d", &p);   
			push(&head,str,p);
		}	
		break;
		case 2:
		{
			pop(&head);
		}
		break;
        case 3:
		{
			list_process(head);
		}
		break;
		case 4:
		{
			list_highest(head);
		}
		break;
		case 5:
		{
			peek(&head);
		}
		break;
		case 6:
		{
			age_queue(&head);
		}
		break;
        case 7: printf("\n");
            break;
        default:printf("\nPlease choose a valid option\n");
        }

    }
}

	
