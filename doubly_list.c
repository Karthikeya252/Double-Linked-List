#include "doubly_list.h"

void main()
{	List *list;
	Node *node;
	int num, data, i, ind;

	list = createList();
	printf("Enter the number of data elements:");
	scanf("%d",&num);
	for (i = 0;i < num;i++)
	{	printf("Enter element %d:",i+1);
		scanf("%d",&data);
		node = createNode(data);
		append(list, node);
	}
	while(1)
	{	printf("===================================================\n");
		printf("Double Linked List operations\n");
		printf("--------------------------------------\n");
		printf("0.Exit\n1.Insertion\n2.Deletion\n3.Display\n4.Is empty\n5.To check length\n6.Empty the entire list\n7.Reverse Display\n8.Append some elements\n");
		printf("Enter your choice:");
		scanf("%d",&num);
		switch(num)
		{	case 0:
				emptyList(list);
				free(list);
				printf("\nProgram Terminated.\n\n");
				exit(0);
				break;
			case 1:
				printf("===================================================\n");
				printf("Enter the data to insert:");
				scanf("%d",&data);
				node = createNode(data);
				printf("Enter the index to insert:");
				scanf("%d",&ind);
				i = insertNode(ind, node, list);
				if(!i)
					printf("Node inserted successfully !!\n");
				else
					printf("Node is not inserted to the list !!\n");
				break;
			case 2:
				printf("===================================================\n");
				printf("Enter the data to delete:");
				scanf("%d",&data);
				i = deleteNode(data, list);
				if(!i)
					printf("Data deleted successfully\n");
				else
					printf("Data not found in the list\n");	
				break;

			case 3:
				printf("===================================================");
				display(list);
				break;

			case 4:
				printf("===================================================\n");
				i = isEmpty(list);
				if(i)
					printf("List is empty !!\n");
				else
					printf("List is not empty !!\n");
				break;

			case 5:
				printf("===================================================\n");
				i = length(list);
				printf("List containg %d element(s)\n",i);
				break;
			case 6:
				printf("===================================================\n");
				emptyList(list);
				printf("Elements are deleted !!\n");
				break;
			case 7:
				printf("===================================================\n");	
				reverseDisplay(list);
				break;
			case 8:
				printf("===================================================\n");
				printf("Enter the number of elements to append:");
				scanf("%d",&num);
				printf("Enter the elements one by one\n");
				for (i=0;i<num;i++)
				{	printf("Enter element %d",i+1);
					scanf("%d",&data);
					node = createNode(data);
					append(list,node);
				}
				break;
	  		default:
				printf("Invalid input please check and re-enter\n");
		}
	}
}
