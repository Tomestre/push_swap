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
int is_better_rra(t_stack *a, int bit)
{
    int cost_ra = 0;
    t_node *current = a->top;
    int has_zero = 0;
    while (current && cost_ra < a->size) {
        if (((current->ranking >> bit) & 1) == 0) {
            has_zero = 1;
            break;
        }
        cost_ra++;
        current = current->next;
    }
    if (!has_zero)
        return 0;

    int cost_rra = 0;
    current = a->top->prev;
    while (current && cost_rra < a->size) {
        if (((current->ranking >> bit) & 1) == 0)
            break;
        cost_rra++;
        current = current->prev;
    }
    cost_rra++;

    return cost_rra < cost_ra;
}
int has_bit_zero(t_stack *a, int bit)
{
    t_node *current = a->top;
    int i = 0;
    while (i < a->size) {
        if (((current->ranking >> bit) & 1) == 0)
            return 1; // Encontrou um elemento com bit 0
        current = current->next;
        i++;
    }
    return 0; // Nenhum elemento tem bit 0
}
void process_bit(t_stack *a, t_stack *b, int bit) 
{
	if (is_sorted(a) || !has_bit_zero(a, bit))
		return;
    int total = a->size;
    int count = 0;
    while (count < total) {
        if (((a->top->ranking >> bit) & 1) == 0) {
            pb(a, b);
        } else {
			if(is_better_rra(a, bit))
				rra(a);
			else
            	ra(a);
        }
        count++;
    }
    while (b->size > 0) {
        pa(a, b);
    }
}

void sort_stack(t_stack *a, t_stack *b)
{
    ranking(a);
    int max_rank = a->size - 1;
    int bit = 0;
    while ((1 << bit) <= max_rank) {
        process_bit(a, b, bit);
        bit++;
    }
}    
