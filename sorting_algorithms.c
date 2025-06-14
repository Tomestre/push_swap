#include "push_swap.h"

int is_sorted(t_stack *a)
{
	if (a->size < 2)
		return 1;
	t_node *current = a->top;
	while (current->next != a->top) {
		if (current->value > current->next->value)
			return 0;
		current = current->next;
	}
	return 1;
}
void sort_stack(t_stack *a, t_stack *b)
{
    int min_cost = INT_MAX;
    t_node *best_element = NULL;
    t_node *current = stack_a->head;

    while (current)
    {
        int cost = total_coast(current, stack_a, stack_b);
        if (cost < min_cost)
        {
            min_cost = cost;
            best_element = current;
        }
        current = current->next;
    }
}

