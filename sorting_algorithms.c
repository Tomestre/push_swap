#include "push_swap.h"

int is_sorted(t_stack *a)
{
    if (a->size < 2)
        return 1;
    t_node *current = a->top;
    while (current->next != a->top)
    {
        if (current->value > current->next->value)
            return 0;
        current = current->next;
    }
    return 1;
}

// Encontra o nó de maior ranking em B
t_node *find_highest_rank_node(t_stack *b)
{
    t_node *current = b->top;
    t_node *max_node = current;
    int i = 0;
    while (++i < b->size)
    {
        current = current->next;
        if (current->rank > max_node->rank)
            max_node = current;
    }
    return max_node;
}

void bring_node_to_top(t_stack *b, t_node *target)
{
    int pos = 0;
    t_node *current = b->top;
    while (current != target)
    {
        current = current->next;
        pos++;
    }
    if (pos <= b->size / 2)
        while (b->top != target)
            rb(b);
    else
        while (b->top != target)
            rrb(b);
}

void sort_stack_second(t_stack *a, t_stack *b)
{
    while (b->size > 0)
    {
        t_node *target = find_highest_rank_node(b);
        bring_node_to_top(b, target);
        pa(a, b);
    }
}
void sort_stack(t_stack *a, t_stack *b)
{
    t_node *current_a;
    t_node *current_b;

    if (!a || !b || a->size == 0)
        return;

    pb(a, b);

    while (a->size > 1)
    {
        current_a = a->top;
        current_b = b->top ? b->top : NULL;

        if (current_a->value > current_a->next->value && current_b->value < current_b->next->value)
        {
            ss(a, b);
            continue;
        }
        else if (current_a->value > current_a->prev->value && current_b->value < current_b->prev->value)
            {
            rrr(a, b);
            continue;
        }
        else if (current_a->value > current_a->next->value)
        {
            sa(a);
            continue;
        }
        else if (current_b->value < current_b->prev->value)
            {
                rb(b);
                continue;
            }
        else if (current_b->value < current_b->next->value)
        {
            sb(b);
            continue;
        }
        else if (current_a->value > current_a->prev->value)
        {
            rra(a);
            continue;
        }
        else
            pb(a, b);
    }

    // ft_putstr_fd("Meio\n", 1);
    print_stack(a, "Stack A");
    print_stack(b, "Stack B");

    sort_stack_second(a, b);
}
