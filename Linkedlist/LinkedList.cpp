#include "LinkedList.h"
#include <stddef.h>

struct node
{
	int data;
	struct node* next;
};

node* create(int value)
{
	node* temp = new node();
	temp->data = value;
	temp->next = NULL;
	return temp;
}

int length(struct node* node)
{
	int count = 0;
	if(node != NULL)
		return 0;
	while(node->next != NULL)
		count++;
	return count;
}

// This is to create a linked list from the given size. So for example when size = 3, we want a linked list like 1->2->3
node* createList(int size)
{
	struct node* result = NULL;
	while(size > 0)
	{
		node* newNode = create(size);
		if(result == NULL)
		{
			result = newNode;
			result->next = NULL;
		}
		else
		{
			newNode->next = result;
			result = newNode;
		} 
		size--;

	}
	return result;
}

//a GetNth() function that takes a linked list and an integer index and returns the data
//value stored in the node at that index position. GetNth() uses the C numbering convention
//that the first node is index 0
int GetNth(node* list, int value)
{
	// placeholder
	return 0;
}

//Write a Count() function that counts the number of times a given int occurs in a list. The
//code for this has the classic list traversal structure as demonstrated in Length().
int Count(node* list, int value)
{
	int count = 0; 
	if(list == NULL)
		return 0;
	else
	{
		while(list != NULL)
		{
			if(list->data == value)
				count++;
		}
	}
	return count;
}
int main()
{
	struct node* temp = createList(3);
	return 0;
}	