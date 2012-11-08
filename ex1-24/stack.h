#ifndef LEON__STACK_H
#define LEON__STACK_H

#include <stdlib.h>

struct node{
	void *element;
	struct node* next;
};

struct stack{
	int len;
	struct node *first;
};

struct stack* NewStack();

extern void Push(void* element, struct stack* s);

extern void* Pop(struct stack* s);

extern int isEmpty(struct stack* s);

#endif