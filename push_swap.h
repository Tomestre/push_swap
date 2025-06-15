#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <limits.h>

// Estrutura para um nó da lista duplamente ligada
typedef struct s_node {
    int value;
    int rank;
    struct s_node *next;
    struct s_node *prev;
    int position_a;
    int position_b;
    int direction;
    int is_sorted;
} t_node;

// Estrutura para a pilha
typedef struct s_stack {
    t_node *top;
    int size;
} t_stack;

// Funções de utils.c
int is_valid_integer(char *str);
int check_duplicates(t_stack *stack, int value);
void print_stack(t_stack *stack, char *name);
void ranking(t_stack *stack);


// Funções de stack_operations.c
t_node *new_node(int value);
void push(t_stack *stack, t_node *node);
t_node *pop(t_stack *stack);
void free_stack(t_stack *stack);
void sa(t_stack *a);
void sb(t_stack *b);
void ss(t_stack *a, t_stack *b);
void pa(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);
void ra(t_stack *a);
void rb(t_stack *b);
void rr(t_stack *a, t_stack *b);
void rra(t_stack *a);
void rrb(t_stack *b);
void rrr(t_stack *a, t_stack *b);

// Funções de sorting_algorithms.c
void sort_stack(t_stack *a, t_stack *b);


#endif
