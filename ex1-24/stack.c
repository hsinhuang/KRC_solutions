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

#include "stack.h"

struct stack* NewStack(){
	struct stack* s = (struct stack*)malloc(sizeof(struct stack)); 
	s->len = 0;
	s->first = NULL;
	return s;
}

void Push(const void* element, struct stack* s){
	struct node* n = (struct node*)malloc(sizeof(struct node));
	n->element = element;
	n->next = s->first;

	s->len++;
	s->first = n;
}

const void* Pop(struct stack* s){
	struct node* n = s->first;
	const void* ele = n->element;
	s->first = n->next;
	free(n);
	s->len--;
	return ele;
}

int isEmpty(struct stack* s){
	return s->len == 0 ? 1 : 0;
}