#include <stdio.h>
#include <stdlib.h>

#define MAXMEMBERS 100
typedef struct queue
{
	int members[MAXMEMBERS];
	int top;
	int size;
}queue;

int pop(queue *q)
{
	if (q->size <= 0)
		return -1;
	int next = q->top;
	q->top = (q->top + 1) % MAXMEMBERS;
	q->size -= 1;
	return q->members[next];
}
int main()
{
	;
}

int hash_string(str *s)
{
	
}
