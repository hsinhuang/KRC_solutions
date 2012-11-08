#include "stack.h"

struct stack* NewStack(){
	struct stack* s = (struct stack*)malloc(sizeof(struct stack)); 
	s->len = 0;
	s->first = NULL;
	return s;
}

void Push(void* element, struct stack* s){
	struct node* n = (struct node*)malloc(sizeof(struct node));
	n->element = element;
	n->next = s->first;

	s->len++;
	s->first = n;
}

void* Pop(struct stack* s){
	struct node* n = s->first;
	void* ele = n->element;
	s->first = n->next;
	free(n);
	s->len--;
	return ele;
}

int isEmpty(struct stack* s){
	return s->len == 0 ? 1 : 0;
}