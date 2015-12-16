//exercise 3.1
//stack.c
#include "stack.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

Stack *init_stack()
{
	Stack *s = (Stack*)malloc(sizeof(Stack));
	if (s!=NULL)
	{
		s->size = 0;
	}
	return s;
}

int is_empty(Stack *s)
{
	if (s->size == 0)
		return 1;
	else
		return 0;
}

int get_size(Stack *s)
{
	return s->size;
}

Node Push(Stack *s, Elemtype item)
{
	Node *node = (Node*)malloc(sizeof(Node));
	if(node != NULL)
	{
		node->data = item;
		node->down = get_top(s, NULL);
		s->size++;
		s->top = node;
	}
	return node;
}

Node get_top(Stack *s, Elemtype *p)
{
	if (is_empty(s) != 1&& p!=NULL)
		*p = s->top->data;
	return s->top;
}

Node pop(Stack *s, Elemtype *p)
{
	Node *p = s->top;
	if (is_empty(s) != 1&&p!= NULL)
	{
		if (p != NULL)
			*p = p->data;
		s->size--;
		s->top = s->top->down;
		free(p);
	}
	return s->top;
}

void destroy_stack(Stack *s)
{
	if (is_empty(s)!=1)
		clear_stack(s);
	free(s);
}

void clear_stack(Stack *s)
{
	while (is_empty(s) != 1)
		pop(s, NULL);
}

void stack_traverse(Stack *s, void (*visit)())
{
	Node *p = s->top;
	int i = s->size;
	while(i--)
	{
		visit(p->data);
		p = p->down;
	}
}

