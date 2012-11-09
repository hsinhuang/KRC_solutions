/*
 * Description:	A stack implemented by linked list
 * Usage:		function `NewStack` is used to initialize a stack
 * 				the pointer returned by `NewStack` must be __freed__
 * 				no boundary check
 * Copyright:	Copyright(c)2012 Leon Huang, Nanjing University OPEN Assn.
 * License:		GPLv3
 *
 * If you find any bug, please report to leon@njuopen.com
 */

#ifndef LEON__STACK_H
#define LEON__STACK_H

#include <stdlib.h>

struct node{
	const void *element;
	struct node* next;
};

struct stack{
	int len;
	struct node *first;
};

// **NOTE**: Need to __free__ the pointer
// returned by this function
struct stack* NewStack();

extern void Push(const void* element, struct stack* s);

extern const void* Pop(struct stack* s);

extern int isEmpty(struct stack* s);

#endif