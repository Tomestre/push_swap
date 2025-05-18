#include "push_swap.h"

/*static int is_sorted(t_stack *a)
{
    if (!a || !a->top)
        return 1;
    t_node *current = a->top;
    int steps = a->size - 1;
    while (steps--)
    {
        if (current->value > current->next->value)
            return 0;
        current = current->next;
    }
    return 1;
}*/

/*oid sort_stack(t_stack *a, t_stack *b)
{
        while(!is_sorted(a))
        {
            t_node *current_a = a->top;
            t_node *next_a = current_a ? current_a->next : NULL;
            t_node *current_b = b->top;

            if(current_a->value > next_a->value)
            {
                sa(a);
            }
            else if(current_b == NULL || current_a->value < current_b->value)
                {
                    pb(a, b);
                }
            else
                {
                    pa(a, b);
                }
            }
            print_stack(a, "Stack A");
            print_stack(b, "Stack B");
}*/
void sort_stack(t_stack *a, t_stack *b)
{


 while (a->size > 0)
 {
    int top_a = a->top->value;
    int next_a = a->top->next->value;
    int bottow_a = a->top->prev->value;

    int top_b = b->top ? b->top->value : 0;
    int next_b = b->top ? b->top->next->value : 0;
    int bottow_b = b->top ? b->top->prev->value : 0;

    if(top_a > next_a)
    {
        sa(a);
    }
    else if (top_a > bottow_a)
    {
        rra(a);
    }
    else if (top_b < bottow_b)
    {
        rb(b);
    }
    else if (top_b < next_b)
    {
        sb(b);
    }
    else
    {
        pb(a, b);

    }
 }

 /*ft_putstr_fd("Inicio da etapa 2\n\n", 1);*/
 while (b->size > 0)
 {
    int top_b = b->top->value;
    int next_b = b->top->next->value;
    int top_a = a->top ? a->top->value : 0;
    int next_a = a->top ? a->top->next->value : 0;
    int bottow_a = a->top ? a->top->prev->value : 0;



    if(next_b > top_a && next_b > next_a && next_b > top_b)
    {
        sb(b);
        if(top_a > next_a)
        {
            sa(a);
        }
        pa(a, b);
        sa(a);
        pb(a, b);
    }
    if(top_a > next_a)
    {
         sa(a);
    }
    else if(top_b < next_b)
    {
        sb(b);
    }
    else if(top_a > bottow_a)
    {
        rra(a);
    }
    else{
        pa(a, b);

    }

    top_a = a->top ? a->top->value : 0;

    if(top_a > next_a && a->size > 3)

        {
            ra(a);
            sa(a);
            pb(a, b);
            rra(a);
        }

 }
return;
}

