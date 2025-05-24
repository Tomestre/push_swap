#include "push_swap.h"

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
    while (b->size > 0)
    {
        pa(a, b);
    }

}

#include "push_swap.h"

// Função para encontrar o maior número na stack
int find_max(t_stack *stack) {
    int max = stack->top->value;
    t_node *current = stack->top->next;

    while (current != stack->top) {
        if (current->value > max) {
            max = current->value;
        }
        current = current->next;
    }
    return max;
}

// Função para encontrar o menor número na stack
int find_min(t_stack *stack) {
    int min = stack->top->value;
    t_node *current = stack->top->next;

    while (current != stack->top) {
        if (current->value < min) {
            min = current->value;
        }
        current = current->next;
    }
    return min;
}

// Função para calcular a média
int calculate_average(int max, int min) {
    return (max + min) / 2;
}

// Atualização na função sort_stack
void sort_stack(t_stack *a, t_stack *b) {
    int max = find_max(a);
    int min = find_min(a);
    int average = calculate_average(max, min);

    // Passar todos os nós abaixo da média para a stack b
    int size = a->size;
    for (int i = 0; i < size; i++) {
        if (a->top->value < average) {
            pb(a, b);
        } else {
            ra(a); // Rotaciona para manter a ordem
        }
    }

    // Continue com a lógica de ordenação
    while (a->size > 0) {
        int top_a = a->top->value;
        int next_a = a->top->next->value;
        int bottow_a = a->top->prev->value;

        int top_b = b->top ? b->top->value : 0;
        int next_b = b->top ? b->top->next->value : 0;
        int bottow_b = b->top ? b->top->prev->value : 0;

        if (top_a > next_a) {
            sa(a);
        } else if (top_a > bottow_a) {
            rra(a);
        } else if (top_b < bottow_b) {
            rb(b);
        } else if (top_b < next_b) {
            sb(b);
        } else {
            pb(a, b);
        }
    }

    while (b->size > 0) {
        pa(a, b);
    }
}
