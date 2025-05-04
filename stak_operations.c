#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

// Função para criar um novo nó
t_node *new_node(int value) {
    t_node *node = malloc(sizeof(t_node));
    if (!node) {
        return NULL;
    }
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void push(t_stack *stack, t_node *node) {
    if (!stack || !node) {
        return;
    }
    if (stack->top == NULL) {
        stack->top = node;
        node->next = node;
        node->prev = node;
    } else {
        node->next = stack->top;
        node->prev = stack->top->prev;
        stack->top->prev->next = node;
        stack->top->prev = node;
        stack->top = node;
    }
    stack->size++;
}

t_node *pop(t_stack *stack) {
    if (!stack || stack->top == NULL) {
        return NULL;
    }
    t_node *node = stack->top;
    if (stack->size == 1) {
        stack->top = NULL;
    } else {
        stack->top = node->next;
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    stack->size--;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

// Operações básicas
void sa(t_stack *a) {
    if (a->size < 2) {
        return;
    }
    t_node *first = pop(a);
    t_node *second = pop(a);
    push(a, first);
    push(a, second);
    printf("sa\n");
}
void sb(t_stack *b) {
    if (b->size < 2) {
        return;
    }
    t_node *first = pop(b);
    t_node *second = pop(b);
    push(b, first);
    push(b, second);
    printf("sb\n");
}
void ss(t_stack *a, t_stack *b)
{
    sa(a);
    sb(b);
    printf("ss\n");
}
void pa(t_stack *a, t_stack *b) {
    if (b->size == 0) {
        return;
    }
    t_node *node = pop(b);
    push(a, node);
    printf("pa\n");
}

void pb(t_stack *a, t_stack *b) {
    if (a->size == 0) {
        return;
    }
    t_node *node = pop(a);
    push(b, node);
    printf("pb\n");
}

void ra(t_stack *a) {
    if (a->size <= 1) {
        return;
    }
    a->top = a->top->next;
    printf("ra\n");
}
void rb(t_stack *b) {
    if (b->size <= 1) {
        return;
    }
    b->top = b->top->next;
    printf("rb\n");
}
void rr(t_stack *a, t_stack *b)
{
    ra(a);
    rb(b);
    printf("rb\n")
}

void rra(t_stack *a) {
    if (a->size <= 1) {
        return;
    }
    a->top = a->top->prev;
    printf("rra\n");
}

void rrb(t_stack *b) {
    if (a->size <= 1) {
        return;
    }
    b->top = b->top->prev;
    printf("rrb\n");
}

void rrr(t_stack *a, t_stack *b)
{
    rra(a);
    rrb(b);
    printf("rrr\n")
}