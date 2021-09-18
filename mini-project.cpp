//@cpp-check
//include standard library
#include <stdio.h>
#include <conio.h>



//Create schema with data and pointer
typedef struct dataNode
{
	int number;
	struct dataNode *next; 
} data;

// declare All pointer is NULL 
data *headA = NULL, *headB = NULL, *head = NULL, *end = NULL,
     *root = NULL, *startNode = NULL;
//function Create node
data *CreateNode(int n) 
{
	data *temp; //create pointer temp is newdataNode
	temp = new data;
	if (temp != NULL) //if temp is not null 
	{
		temp->number = n; //pointer temp link to number in dataNode 
		temp->next = NULL; //set temp next is null
		return (temp); //return temp
	}
	// else condition is return null 
	else
	{
		return (NULL);
	}
}

//function insertnode
void insertnode(data *ptr, data *&head) 
{
	data *start, *prev;// create pointer start and prev
	if (head == NULL) // check address pointer is null
	{
		head = ptr;// give head equal  is ptr
		end = ptr;// give end  equal is  ptr
		return;
	}
	start = head; //set pointer start is headNode 
	// loop do-While
	do
	{
		if (start->number == ptr->number) //check  index number equal last number
		{
			delete (ptr);// apply function delete last number
			return;
		}
		start = start->next; // increase pointer start 
	} while (start != NULL); //pointer start is not null
	start = head; //set pointer start equal pointer head
	while (start->number < ptr->number)
	{
		start = start->next;
		if (start == NULL)
			break;
	}
	if (start == head)
	{
		ptr->next = head;
		head = ptr;
	}
	else
	{
		prev = head;
		while (prev->next != start)
		{
			prev = prev->next;
		}
		prev->next = ptr;
		ptr->next = start;
		if (end == prev) {

			end = ptr;
		}
	}
}
//function printNode
void printnode(data *ptr)
{
	printf("Number : %d\t", ptr->number); //show  list number
}
//function printList from setC
void printlist(data *ptr)
{
	while (ptr != NULL) // pointer is not Null
	{
		printnode(ptr); // show node 
		ptr = ptr->next; //increase pointer to next of ptr
	}
}
//function search
data *search(int key, data *&head)
{
	data *ptr;// declare pointer to dataNode
	ptr = head; //set pointer to headNode
	if (ptr == NULL) // check value from pointer  if pointer is Null  return Null
	{
		return (NULL); //if pointer is Null  return Null
	}
	while (key != ptr->number) //check key:int is not ptr number of dataNode 
	{
		ptr = ptr->next; // increase pointer 
		if (ptr == NULL) // check pointer increase is Null 
		{
			break; // stop to search data
		}
	}
	return (ptr); // return to function 
}
//function delete set A B
void deletenode(data *ptr, data *&head) //parameter head, address and ptr point to dataNode
{
	data *start, *prev;// declare pointer start and prev
	start = ptr; //set begin pointer start with get from ptr point to dataNode 
	if (start == head) //check if pointer start equal pointer head  
	{
		head = head->next; //increase pointer head 
		if (end == start) // check if  pointer end in dataNode equal pointer start 
		{
			end = end->next; //increase pointer end
		}
		delete (start); //delete value in pointer start
	}
	//else condition 
	else
	{
		prev = head; //set pointer prev equal pointer head of dataNode
		//loop
		while (prev->next != start) //check if prev next is not pointer start  from dataNode
		{
			prev = prev->next; //set increase prev  
		}
		prev->next = start->next; // Enter a value from  start next that points to prev to the next node.
		delete (start); //after delete value in pointer start
	}
}
//function delete set C
void deletenodeC(data *ptr) //declare pointer ptr
{
	data *start, *prev;// set pointer start and prev
	start = ptr;	   //  put value from pointer ptr come in pointer start
	if (start == head) //check if pointer start equal head from dataNode
	{
		head = head->next; //set pointer head to the next node  
		if (end == start) //check if pointer end value in dataNode equal pointer start value in dataNode
		{
			end = end->next; //set pointer end to the next node
		}
		delete (start); //after delete  value in pointer start 
	}
	else
	{
		prev = head; //  put value from pointer head come in pointer prev
		while (prev->next != start) //check if pointer prev to the next node is not pointer start
		{
			prev = prev->next; //set pointer prev to the next node
		}
		prev->next = start->next; //Enter a value from  start next that points to prev to the next node.
		if (end == start)	  //check if value in pointer end is equal value in pointer start
		{
			end = prev;//Enter a value from pointer prev that points to end .
		}
		delete (start); //after delete  value in pointer start
	}
}

//function main 
int main()
{
	data *temp;
	int choice, n;

	do
	{
		printf("Welcome to program  C = A intersect B\n\n");
		printf("1.Insert number set A\t\t2.Insert number set B\n");
		printf("3.List set A\t\t\t4.List set B\n");
		printf("5.Search  set A\t\t\t6.Search set B \n");
		printf("7.Delete set node A\t\t8.Delete set node B\n");
		printf("9.Result set C = A intersec B\t\t10.DELETE SET C\n\n"); 
		printf("0. Quit\n\n");
		printf("Enter your Number Choice : ");
		scanf("%d", &choice);


		switch (choice)
		 //select choice
		{
		case 1:
			printf("\nEnter product number set A : ");
			scanf("%d", &n);
			temp = CreateNode(n);
			insertnode(temp, headA);
			break;
		case 2:
			printf("\nEnter product number set B : ");
			scanf("%d", &n);
			temp = CreateNode(n);
			insertnode(temp, headB);
			break;
		
		case 3:
			printlist(headA);
			printf("\n\n-----------Enter to clear-----------\n\n");
			getch();
			break;
		case 4:
			printlist(headB);
			printf("\n\n-----------Enter to clear-----------\n\n");
			getch();
			break;
		case 5:
			printf("\nEnter key a set A : ");
			scanf("%d", &n);
			temp = search(n, headA);
			if (temp == NULL)
			{
				printf("\nSearch \"%d\" not found\n", n);
				printf("\n-----------Enter to clear-----------\n\n");
				getch();
			}
			else
			{
				printf("\nSearch %d to success\n", n);
				printnode(temp);
				printf("\n-----------Enter to clear-----------\n\n");
				getch();
			}
			break;
		case 6:
			printf("\nEnter key a set B : ");
			scanf("%d", &n);
			temp = search(n, headB);
			if (temp == NULL)
			{
				printf("\nSearch \"%d\" not found\n", n);
				printf("\n-----------Enter to clear-----------\n\n");
				getch();
			}
			else
			{
				printf("\nSearch %d to success\n", n);
				printnode(temp);
				printf("\n-----------Enter to clear-----------\n\n");
				getch();
			}
			break;
			
		case 7:
			printf("\nEnter key a set A : ");
			scanf("%d", &n);
			temp = search(n, headA);
			if (temp == NULL)
			{
				printf("\nSearch \"%d\" not found\n", n);
				printf("\n-------Enter to clear-----------\n\n");
				getch();
			}
			else
			{
				deletenode(temp, headA);
				printf("\n deleted success\n");
				printf("\n-----------Enter to clear-----------\n\n");
				getch();
			}
			break;
		case 8:
			printf("Enter key a set B : ");
			scanf("%d", &n);
			temp = search(n, headB);
			if (temp == NULL)
			{
				printf("Search \"%d\" not found\n", n);
				printf("-----------Enter to clear-----------\n\n");
				getch();
			}
			else
			{
				deletenode(temp, headB);
				printf("deleted success\n");
				printf("t-----------Enter to clear-----------\n\n");
				getch();
			}
			break;
		//setC = A intersect B// 
		case 9:
			data *A, *B;
			printf("Set C = A intersection B: \n");
			A = headA;
			B = headB;
			while (A != NULL)
			{
				while (B != NULL)
				{
					if (A->number == B->number)
					{
						printnode(A);
						B = B->next;
					}
					A = A->next;
				}
			}
			printlist(head);
			printf("\n-----------Enter to clear-----------\n\n");
			getch();
			break;
		case 10: 
			root = head;
			end = startNode;
			while (root != NULL)
			{
				while (end != NULL)
				{
					deletenodeC(root);
					end = end->next;
				}
				root = root->next;
			}
			printf("\nDelect NodeC to Success\n");
			break;
			
		case 0 : printf("Code for Everyone\n");
			 printf("{Thank You For Reading}\n");
			break;
		default:
			printf("Enter the  number. !!\n");
			getch();
			break;
		}
	} while (choice != 0); // ch is not 0
	return 0;
}


