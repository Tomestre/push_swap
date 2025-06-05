#include "push_swap.h"

void sort_b(t_stack *a, t_stack *b) 
{
    while (b->size > 2) 
    {
        if (b->top->value < b->top->next->value)
        {
            sb(b);
        }
        else if (b->top->value < b->top->prev->value) 
        {
            rb(b);
        }
    }
}
static void mark_target_nodes(t_stack *a, t_stack *b) 
{
    t_node *current_a;
    t_node *target_node;
    long best_match_i;

    

    while (b) 
    {
        best_match_i = LONG_MAX;
        current_a = a;
        while(current_a) 
        {
            if (current_a->value > b->value && current_a->value < best_match_i) 
            {
                best_match_i = current_a->value;
                target_node = current_a;
            }
            current_a = current_a->next;
        }
        if(LONG_MAX == best_match_i) 
            target_node = find_smallest(a);
        else
            b->target_node = target_node;
        b = b->next;
    }
}

void sort_stack(t_stack *a, t_stack *b) 
{
    size_t i;
        
    while (a->size > 3) 
    {
        while (a->size != 3)
        {
            sort_b(a, b); // Ordena a pilha B antes de mover o menor para B

            if(a->top->value > a->top->next->value) {
                    sa(a); // Ordena os dois primeiros se necessário
                }
            else if (a->top->value > a->top->prev->value) {
                    rra(a); // Coloca o menor no topo
                }
                
            pb(a, b); // Move o menor para a pilha B
        }
    }

    if (a->size <= 3) // Se a pilha A tiver 3 ou menos elementos, ordena diretamente
    {
        i= 0;
        while(i < a->size)
        {
            if(a->top->value > a->top->next->value) {
                sa(a); // Ordena os dois primeiros se necessário
            }
            else if (a->top->value > a->top->prev->value) {
                rra(a); // Coloca o menor no topo
            }
            i++;
        }
        
        return;
    }
    // Ordena a pilha B
    sort_b(a, b);

    //segunda etapa
    while(b->size > 0) 
    {
        mark_target_nodes(a, b); // Marca os nós alvo na pilha A
    }
}