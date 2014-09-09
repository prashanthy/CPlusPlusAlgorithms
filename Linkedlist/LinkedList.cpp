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
	int count = 0; 
	struct node* current = list;
	if(list != NULL)
	{
		while(current->next != NULL)
		{
			if(count == value)
				return current->data;
			current = current->next;
			count++;
		}
	}
	// placeholder
	return -9999999;
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

//Write a function DeleteList() that takes a list, deallocates all of its memory and sets its
//head pointer to NULL (the empty list).
void DeleteList(struct node*& list) 
{
	if(list == NULL)
		return;
	// doing this recursively
	struct node* temp = list->next;
	delete(list);
	DeleteList(temp);
}


int main()
{
	struct node* temp = createList(9);
	int nth = GetNth(temp, 4);
	DeleteList(temp);
	return 0;
}	
