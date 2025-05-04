#include "push_swap.h"

void sort_stack(t_stack *a, t_stack *b)
{
    t_node *current_a = a->top;
    t_node *bottow_a = a->top->prev;
    t_node *current_b = b->top;
    t_node *bottow_b = b->top->prev;
    t_node *second_a = current_a->next;
    t_node *second_b = current_b->next;

    if(current_a->value > second_a->value && current_b->value > second_b->value)
        ss(a, b);
   else if(current_a->value > bottow_a->value && current_b->value < bottow_b->value)
            rrr(a, b);
    else if(current_a->value > second_a->value)
        sa(a);
    else if(current_b->value > second_b->value)
        sb(b);
    else if(current_a->value > bottow_a->value)
        rra(a);
    else if(current_b->value < bottow_b->value)
        rrb(b);
}
