/*Basic Data Structure*/
/*15.8.18*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ElemType;
#define size 3

typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;

int main()
{	
	int i;
	Node classes[size];
	for (i = 0; i < size; i++)
	{
		classes[i].data = getchar();
		printf("%d\n", classes[i].data);
	}
}
