#include "push_swap.h"

t_node *new_node(int value)
{
	t_node *node = ft_calloc(1, sizeof(t_node));
	if (!node)
		return NULL;
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

void bubble_sort(int *values, int size)
{
    int i = 0;
    while (i < size - 1) {
        int j = 0;
        while (j < size - i - 1) {
            if (values[j] > values[j + 1]) {
                int tmp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = tmp;
            }
            j++;
        }
        i++;
    }
}

void ranking(t_stack *stack)
{
    if (stack->size == 0)
        return;

    int *values = malloc(sizeof(int) * stack->size);
    if (!values)
        return;

    t_node *current = stack->top;
    int i = 0;
    while (i < stack->size) {
        values[i] = current->value;
        current = current->next;
        i++;
    }
    bubble_sort(values, stack->size);
    current = stack->top;
    i = 0;
    while (i < stack->size) {
        int rank = 0;
        while (rank < stack->size && values[rank] != current->value)
            rank++;
        current->ranking = rank;
        current = current->next;
        i++;
    }
    free(values);
}

void push(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return;
	if (stack->top == NULL)
	{
		stack->top = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->next = stack->top;
		node->prev = stack->top->prev;
		stack->top->prev->next = node;
		stack->top->prev = node;
		stack->top = node;
	}
	stack->size++;
}

t_node *pop(t_stack *stack)
{
	if (!stack || stack->top == NULL)
		return NULL;
	t_node *node = stack->top;
	if (stack->size == 1)
	{
		stack->top = NULL;
	}
	else
	{
		stack->top = node->next;
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	stack->size--;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

void free_stack(t_stack *stack)
{
	if (!stack)
		return;
	t_node *current = stack->top;
	if (current != NULL)
	{
		t_node *next = current->next;
		while (next != stack->top)
		{
			free(current);
			current = next;
			next = next->next;
		}
		free(current);
	}
	free(stack);
}

void sa(t_stack *a)
{
	if (a->size < 2)
		return;
	t_node *first = pop(a);
	t_node *second = pop(a);
	push(a, first);
	push(a, second);
	ft_putstr_fd("sa\n", 1);
}

void sb(t_stack *b)
{
	if (b->size < 2)
		return;
	t_node *first = pop(b);
	t_node *second = pop(b);
	push(b, first);
	push(b, second);
	ft_putstr_fd("sb\n", 1);
}

void ss(t_stack *a, t_stack *b)
{
	if (a->size < 2)
		return;
	t_node *first_a = pop(a);
	t_node *second_a = pop(a);
	push(a, first_a);
	push(a, second_a);
	if (b->size < 2)
		return;
	t_node *first_b = pop(b);
	t_node *second_b = pop(b);
	push(b, first_b);
	push(b, second_b);
	ft_putstr_fd("ss\n", 1);
}

void pa(t_stack *a, t_stack *b)
{
	if (b->size == 0)
		return;
	t_node *node = pop(b);
	push(a, node);
	ft_putstr_fd("pa\n", 1);
}

void pb(t_stack *a, t_stack *b)
{
	if (a->size == 0)
		return;
	t_node *node = pop(a);
	push(b, node);
	ft_putstr_fd("pb\n", 1);
}

void ra(t_stack *a)
{
	if (a->size <= 1)
		return;
	a->top = a->top->next;
	ft_putstr_fd("ra\n", 1);
}

void rb(t_stack *b)
{
	if (b->size <= 1)
		return;
	b->top = b->top->next;
	ft_putstr_fd("rb\n", 1);
}

void rr(t_stack *a, t_stack *b)
{
	if (a->size <= 1)
		return;
	a->top = a->top->next;
	if (b->size <= 1)
		return;
	b->top = b->top->next;
	ft_putstr_fd("rr\n", 1);
}

void rra(t_stack *a)
{
	if (a->size <= 1)
		return;
	a->top = a->top->prev;
	ft_putstr_fd("rra\n", 1);
}

void rrb(t_stack *b)
{
	if (b->size <= 1)
		return;
	b->top = b->top->prev;
	ft_putstr_fd("rrb\n", 1);
}

void rrr(t_stack *a, t_stack *b)
{
	if (a->size <= 1)
		return;
	a->top = a->top->prev;
	if (b->size <= 1)
		return;
	b->top = b->top->prev;
	ft_putstr_fd("rrr\n", 1);
}
