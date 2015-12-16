//exercise3.1
//stack.h

#ifndef Stack_H
#define Stack_H

typedef char Elemtype;
typedef struct Node * node;
/*定义栈节点类型*/
typedef struct Node
{
	Elemtype data;
	node* down;
}Node;
/*定义栈类型*/
typedef struct Stack
{
	Node top;
	int size;
}Stack;
/*构造一个空栈*/
Stack *init_stack();

/*销毁一个栈*/
void destroy_stack(Stack *ps);

/*把栈置空*/
void clear_stack(Stack *ps);

/*判定是否为空栈*/
int is_empty(Stack *ps);

/*返回栈大小*/
int get_size(Stack *ps);

/*返回栈顶元素*/
Node get_top(Stack *ps,Elemtype *pElemtype);

/*元素入栈*/
Node push(Stack *ps,Elemtype Elemtype);

/*元素出栈*/
Node pop(Stack *ps,Elemtype *pElemtype);

/*遍历栈并访问visit函数*/
void stack_traverse(Stack *ps,void (*visit)());

#endif
