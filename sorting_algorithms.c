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

// Função para calcular a média de todos os valores da stack
int calculate_average_all(t_stack *stack) {
    if (stack->size == 0)
        return 0;
    int sum = 0;
    int count = 0;
    t_node *current = stack->top;
    while (count < stack->size) {
        sum += current->value;
        current = current->next;
        count++;
    }
    return sum / count;
}

void push_below_average(t_stack *a, t_stack *b, int average) {
    int size = a->size;
    int i = 0;
    while (i < size) {
        if (a->top->value < average)
            pb(a, b);
        else
            ra(a);
        i++;
    }
}

void sort_stack_a(t_stack *a) {
    while (a->size > 0) {
        int top = a->top->value;
        int next = a->top->next->value;
        int bottom = a->top->prev->value;
        if (top > next)
            sa(a);
        else if (top > bottom)
            rra(a);
        else
            break;
    }
}

void sort_stack_b(t_stack *b) {
    // Implemente se necessário
}

void move_back_to_a(t_stack *a, t_stack *b) {
    while (b->size > 0)
        pa(a, b);
}

// Atualização na função sort_stack
void sort_stack(t_stack *a, t_stack *b) {
    // int max = find_max(a);
    // int min = find_min(a);
    // int average = calculate_average(max, min);
    int average = calculate_average_all(a);

    push_below_average(a, b, average);
    sort_stack_a(a);
    sort_stack_b(b);
    move_back_to_a(a, b);
}
