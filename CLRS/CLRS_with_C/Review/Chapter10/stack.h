 /*stack.h*/
#include <stdio.h>
#include <stdlib.h>

#define type int

void init_stack(size_t size);

void delete_stack(void);

void push(type value);

type pop(void);

type top(void);

bool is_empty(void);

bool is_full(void);