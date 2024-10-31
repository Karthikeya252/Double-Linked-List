#include <stdio.h>
#include <stdlib.h>

//Structure declaration for Node 
typedef struct Node 
{	int data;		// Data is stored
	struct Node *pri;	// Address of privious NODE
	struct Node *next;	// Address of next NODE
}Node;

//Structure declaration for starting and ending NODES
typedef struct List
{	struct Node *start;	// Address of starting NODE
	struct Node *end;	// Address of ending NODE
} List;

//Function declaration (Prototype)
List* createList();
Node* createNode(int);
void append(List*, Node*);
int isEmpty(List*);
void emptyList(List*);
void display(List*);
int deleteNode(int,List*);
int insertNode(int, Node*, List*);
int lenght(List*);
void reverseDisplay(List*);

// Memory allocation for list to store starting and ending node address
List *createList()	// No parameter
{	List *list = (List*)malloc(sizeof(List));
	list->start = NULL;	// Initializing start pointer
	list->end = NULL;	// Initializing end pointer
	return list;		// returing the address where these list is allocated
}

// Memory allocation for NODE
Node *createNode(int data)	// Integer parameter to store data into the node
{	Node *node = (Node *)malloc(sizeof(Node));	// Memory allocation for node
	if(node != NULL)
	{	node->data = data;	// Storing the data into data field in NODE
		node->pri = NULL;	// Initializing its privious field
		node->next = NULL;	// Initializing its next field
	}
	return node;
	
}

// Appends the incoming NODES into the list
void append(List *list, Node *node)	// Parameters are List and Node to add new the node at the end of the list
{	if(list->start == NULL)	// If the list is empty
	{	list->start = list->end = node;
		return;
	}
	node->pri = list->end;
	list->end->next = node;
	list->end = node;
	return;
}

// Inserting the NODE to the desired position
int insertNode(int loc, Node *node, List *list)
{	int i;
	Node *prev, *curr;
	if(loc == 1 && list->start == NULL)
	{	list->start = list->end = node;
		return 0;
	}
	
	prev = curr = list->start;
	for(i=0;i<loc-1 && curr != NULL;i++, prev=curr, curr=curr->next);
	// Insertion towards the beginning
	if(i == loc-1 && list->start == curr)
	{	node->next = curr;
		curr->pri = node;
		list->start = node;
		return 0;
	}
	// Insertion at the end 
	if (i==loc-1 && curr == NULL)
	{	node->pri = prev;
		prev->next = node;
		list->end = node;
		return 0;
	}
	// Insertion in between start and end
	if(i==loc-1 && curr != NULL)
	{	node->next = curr;
		node->pri = prev;
		prev->next = node;
		curr->pri = node;
		return 0;
	}
	// If index not found
	else
		return 1;
}

// Deletion of desired NODE
int deleteNode(int data, List *list)
{	Node *prev, *curr;
	if (isEmpty(list))	//first checking whether the list is empty or not if not checked core dumped error may occur  
		return 1;
	prev = curr = list->start;	//Initializing prev and curr pointers
	if(curr->data == data && list->start == list->end)
	{	list->start = list->end = NULL;
		free(curr);
		return 0;
	}
	for (;curr->data!=data && curr->next!=NULL;prev=curr, curr=curr->next);
	// Deleting starting NODE
	if(curr->data == data && list->start == curr)
	{	list->start = curr->next;
		list->start->pri = NULL;
		curr->next = NULL;
		curr->pri = NULL;
		free(curr);
		return 0;
	}

	// Deleting end NODE
	if(curr->data == data && list->end == curr)
	{	list->end = prev;
		prev->next = NULL;
		curr->pri = NULL;
		free(curr);
		return 0;
	}

	// Deletion of NODE in between start and end
	if(curr->data = data)
	{	prev->next = curr->next;
		curr->next->pri = prev;
		curr->next = NULL;
		curr->pri = NULL;
		free(curr);
		return 0;
	}
	// If not found
	return 1;
}

// Checks for empty list
int isEmpty(List *list)
{	if(list->start == NULL)
		return 1;
	else 
		return 0;
}

// Deallocates the memory provided to each NODE and list elements
void emptyList(List *list)
{	Node *pri = list->start;
	Node *curr;

	while(pri!=NULL)
	{	curr = pri->next;
		free(pri);
		pri = curr;
	}
	list->start = list->end = NULL;
}

// Display elements in the list
void display(List *list)
{	Node *ptr;
	if(list->start == NULL)
	{	printf("\nList is Empty\n");
		return;
	}
	printf("\nData elements present in List\n");
	for(ptr = list->start;ptr!=NULL;ptr = ptr->next)
		printf("%d\n",ptr->data);
	return;
}

// Lenght of the list
int length(List *list)
{	int i;
	Node *ptr = list->start;
	for(i=0;ptr!=NULL;i++,ptr = ptr->next);
	return i+1;
}

// Display the elements in reverse manner
void reverseDisplay(List *list)
{	Node *ptr;
	if(list->start == NULL)
	{	printf("List is empty can not reverse the elements!!\n");
		return;
	}
	printf("Elements in reverse order\n");
	ptr = list->end;
	for (;ptr != NULL;ptr = ptr->pri)
		printf("%d\n",ptr->data);
}
