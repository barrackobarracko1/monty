#include "monty.h"

/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_push(stack_t **head, unsigned int counter)
{
	int k, g = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			g++;
		for (; bus.arg[g] != '\0'; g++)
		{
			if (bus.arg[g] > 57 || bus.arg[g] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	k = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, k);
	else
		addqueue(head, k);
}
