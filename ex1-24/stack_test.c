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

#include <stdio.h>
#include "stack.h"

int main(int argc, char const *argv[])
{
	struct stack* s = NewStack();
	char c1 = 'a';
	char c2 = 'b';
	char c3 = 'c';
	char c4 = 'd';

	Push(&c1, s);
	Push(&c2, s);
	Push(&c3, s);

	printf("%c\n", *(char*)Pop(s));
	printf("%d\n", isEmpty(s));
	printf("%c\n", *(char*)Pop(s));
	printf("%d\n", isEmpty(s));

	Push(&c4, s);
	printf("%c\n", *(char*)Pop(s));
	printf("%d\n", isEmpty(s));
	printf("%c\n", *(char*)Pop(s));
	printf("%d\n", isEmpty(s));

	free(s);
	return 0;
}