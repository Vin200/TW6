# TW6
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

void Display(struct node *head)
{
	struct node *temp;
	temp=head;
	while(temp !=NULL)
	{
		printf("%d  ",temp->data);

		temp=temp->next;
	}
}

struct node* Add(struct node *head,int value)
{
	struct node *newnode,*prev,*curr;

	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = value;
	newnode->next = NULL;

	if(newnode == NULL)
	{
		printf("Error:Could not allocate memory:");
	}
	else
	{
		if(head == NULL)
			head = newnode;
		else
		{
			if(newnode->data < head->data)
			{
				newnode->next = head;
				head = newnode;
			}
			else
			{
				curr=head->next;
				prev=head;

				while(curr!= NULL && newnode->data > curr->data)
				{
					prev = prev->next;
					curr = curr->next;
				}
				prev->next = newnode;
				newnode->next= curr;
			}
		}
	}
	return head;
}

void main()
{
	int choice,value;
	struct node *head= NULL;

	for(;;)
	{
		printf("\nEnter 1.Add 2.Display 3.Exit");
		printf("\nEnter choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter value:");
				scanf("%d",&value);
				head = Add(head,value);
				break;
			case 2:
				if(head == NULL)
				{
					printf("List is empty");
				}
				Display(head);
				break;
			case 3:
				exit(1);
				break;
		}
	}
}
