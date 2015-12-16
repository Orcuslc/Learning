/*Review of Chapter 10*/
/*15.8.12*/
#define stack_init_size 10
#define stack_increment 2

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ELemType;
typedef int Status;
typedef enum _bool{false = 0, true = 1,}bool;

typedef struct Node
{
	ELemType data;
	struct Node *next;
}Node;

typedef struct Stack
{
	Node top;
	int size;
}Stack;

Status visit(ELemType c)
{
	printf("%d", c);
}

Status Stack_init(Stack *s)
{
	/*init a new stack*/
	s->top = (Node)malloc(sizeof(Node));
	if (!s->top)
	{
		return "ERROR";
	}
	s->top = NULL;
	s->size = 0;
}

Status Empty(Stack *s)
{
	StackPtr p, q;
	p = s->top;
	while(p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	s->size = 0;
}

Status is_empty(Stack *s)
{
	if (s.size == 0)
	{
		return true;
	}
	return false;
}

Status push(Stack *s, ElemType x)
{
	Node n = (Node)malloc(sizeof(Node));
	if (!s)
	{
		return "ERROR";
	}
	n->data = x;
	n->next = s->top;
	s->top = n;
	s->size++;
}

Status pop(Stack *s, ElemType *n)
{
	Node p;
	if (is_empty(*s))
	{
		return "ERROR";
	}
	*n = s->top->data;
	p = s->top;
	s->top = s->top->next;
	free(p);
	s->size--;
}


