
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
	DeleteList(list->next);
    delete list;
}

int Pop(struct node*& list)
{
	int poppedItem = -999999;
	if(list == NULL)
		return -999999;
	struct node* temp = list;
	poppedItem = temp->data;
	temp = temp->next;
	delete(list);
	list = temp;
	return poppedItem;
}

void InsertNth(struct node*& list, int position, int value)
{
	if(list == NULL)
	{
		struct node* temp = create(value);
		list = temp;
	}
	else
	{
		struct node* current = list;
		int count = 0; 
		while(current != NULL)
		{
			// this is a case when we found the position
			if(count == position-1)
			{
				struct node* temp = create(value);
				temp->next = current->next;
				current->next = temp;
				break;
			}
			else if(count > position)
				break;
			count++;
			current = current->next;
		}
	}
}


void Push(struct node*& headRef, int newNode)
{
	if(headRef == NULL)
	{
		struct node* nodenew = create(newNode);
		nodenew->next = headRef;
		headRef = nodenew;
	}
}

void SortedInsert(struct node*& headRef, struct node* newNode)
{
	/*Write a SortedInsert() function which given a list that is sorted in increasing order, and a
	single node, inserts the node into the correct sorted position in the list. While Push()
	allocates a new node to add to the list, SortedInsert() takes an existing node, and just
	rearranges pointers to insert it into the list. There are many possible solutions to this
	problem.*/
	if(headRef == NULL)
	{
		Push(headRef, newNode->data);
	}
	else
	{
		struct node* current = headRef;
		while(current->next != NULL)
		{
			if(newNode->data < current->data)
			{
				newNode->next = current;
				current = newNode;
			}
			else if(newNode->data < current->next->data)
			{
				newNode->next = current->next;
				current->next = newNode;
			}
			current = current->next;
		}
		if(current->next == NULL && newNode->data > current->data)
		{
			current->next = newNode;
		}
	}
}


void InsertSort(struct node*& headRef)
{
	if(headRef == NULL)
		return;
	else
	{
		struct node* current = headRef;
		while(current != NULL)
		{
			SortedInsert(headRef, current);
			current = current->next;
		}
	}
}

int main()
{
	struct node* temp = createList(6);

	struct node* nullpointer = NULL;
	//int nth = GetNth(temp, 4);
	//DeleteList(temp);
	//int popped = Pop(temp);
	//InsertNth(nullpointer,2,7);

	SortedInsert(temp, create(7));
	return 0;
}	
