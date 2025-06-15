#include "push_swap.h"

t_node *new_node(int value)
{
	t_node *node = ft_calloc(1, sizeof(t_node));
	if (!node)
		return NULL;
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

int min(int a, int b)
{
	return (a < b) ? a : b;
}


void bubble_sort(int *values, int size)
{
    int i = 0;
    while (i < size - 1) {
        int j = 0;
        while (j < size - i - 1) {
            if (values[j] > values[j + 1]) {
                int tmp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = tmp;
            }
            j++;
        }
        i++;
    }
}

void ranking(t_stack *stack)
{
    if (stack->size == 0)
        return;

    int *values = malloc(sizeof(int) * stack->size);
    if (!values)
        return;

    t_node *current = stack->top;
    int i = 0;
    while (i < stack->size) {
        values[i] = current->value;
        current = current->next;
        i++;
    }
    bubble_sort(values, stack->size);
    current = stack->top;
    i = 0;
    while (i < stack->size) {
        int rank = 0;
        while (rank < stack->size && values[rank] != current->value)
            rank++;
        current->rank = rank;
        current = current->next;
        i++;
    }
    free(values);
}
void calculate_position_a(t_stack *a)
{
	if (!a || a->size == 0)
		return;
	t_node *current_a = a->top;
	int position = 0;
	while (position < a->size)
	{
		current_a->position_a = position;
		current_a = current_a->next;
		position++;
	}
}
void calculate_position_b(t_stack *b)
{
	if (!b || b->size == 0)
		return;
	t_node *current_b = b->top;
	int position = 0;
	while (position < b->size)
	{
		current_b->position_b = position;
		current_b = current_b->next;
		position++;
	}
}
int calculate_cost_a(t_node *node, int size_a)
{
    if (!node)
        return -1;
    int ra = node->position_a;         // Quantos "ra" para levar ao topo
    int rra = size_a - node->position_a; // Quantos "rra" para levar ao topo
    return min(ra, rra);               // Menor custo entre ra e rra
}
int calculate_cost_b(int target_position, int size_b)
{
    int rb = target_position;         // Quantos "rb" para levar a posição alvo ao topo
    int rrb = size_b - target_position; // Quantos "rrb" para levar a posição alvo ao topo
    return min(rb, rrb);              // Menor custo entre rb e rrb
}
int find_target_position_in_b(t_stack *b, int value)
{
    if (!b || b->size == 0)
        return 0; // Se B está vazia, a posição é 0
    t_node *current = b->top;
    int position = 0;
    while (position < b->size)
    {
        if (value > current->value) // Encontrou a posição onde value deve ir
            return position;
        current = current->next;
        position++;
    }
    return b->size; // Se value é menor que todos em B, vai para o fundo
}

int total_coast(t_node *node_a, t_stack *a, t_stack *b)
{
    if (!node_a || !a || !b)
        return -1;

    // Variável 1: custo para mover node_a ao topo de A
    int cost_a = (node_a->position_a < a->size - node_a->position_a)
                 ? node_a->position_a
                 : a->size - node_a->position_a;

    // Variável 2: direção de rotação em A (1 para ra, -1 para rra)
    int dir_a = (node_a->position_a < a->size - node_a->position_a) ? 1 : -1;

    // Variável 3: posição alvo em B
    int target_pos_b = find_target_position_in_b(b, node_a->value);

    // Variável 4: custo para mover target_pos_b ao topo de B
    int cost_b = (target_pos_b < b->size - target_pos_b)
                 ? target_pos_b
                 : b->size - target_pos_b;

    // Variável 5: direção de rotação em B (1 para rb, -1 para rrb)
    int dir_b = (target_pos_b < b->size - target_pos_b) ? 1 : -1;

    // Cálculo do custo total
    if (dir_a == dir_b)
    {
        // Se as direções são iguais, usar o maior custo + 1 (rotações simultâneas)
        return (cost_a > cost_b ? cost_a : cost_b) + 1;
    }
    // Se direções são diferentes, somar os custos + 1
    return cost_a + cost_b + 1;
}

void push(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return;
	if (stack->top == NULL)
	{
		stack->top = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->next = stack->top;
		node->prev = stack->top->prev;
		stack->top->prev->next = node;
		stack->top->prev = node;
		stack->top = node;
	}
	stack->size++;
}

t_node *pop(t_stack *stack)
{
	if (!stack || stack->top == NULL)
		return NULL;
	t_node *node = stack->top;
	if (stack->size == 1)
	{
		stack->top = NULL;
	}
	else
	{
		stack->top = node->next;
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	stack->size--;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

void free_stack(t_stack *stack)
{
	if (!stack)
		return;
	t_node *current = stack->top;
	if (current != NULL)
	{
		t_node *next = current->next;
		while (next != stack->top)
		{
			free(current);
			current = next;
			next = next->next;
		}
		free(current);
	}
	free(stack);
}

void sa(t_stack *a)
{
	if (a->size < 2)
		return;
	t_node *first = pop(a);
	t_node *second = pop(a);
	push(a, first);
	push(a, second);
	ft_putstr_fd("sa\n", 1);
}

void sb(t_stack *b)
{
	if (b->size < 2)
		return;
	t_node *first = pop(b);
	t_node *second = pop(b);
	push(b, first);
	push(b, second);
	ft_putstr_fd("sb\n", 1);
}

void ss(t_stack *a, t_stack *b)
{
	if (a->size < 2)
		return;
	t_node *first_a = pop(a);
	t_node *second_a = pop(a);
	push(a, first_a);
	push(a, second_a);
	if (b->size < 2)
		return;
	t_node *first_b = pop(b);
	t_node *second_b = pop(b);
	push(b, first_b);
	push(b, second_b);
	ft_putstr_fd("ss\n", 1);
}

void pa(t_stack *a, t_stack *b)
{
	if (b->size == 0)
		return;
	t_node *node = pop(b);
	push(a, node);
	ft_putstr_fd("pa\n", 1);
}

void pb(t_stack *a, t_stack *b)
{
	if (a->size == 0)
		return;
	t_node *node = pop(a);
	push(b, node);
	ft_putstr_fd("pb\n", 1);
}

void ra(t_stack *a)
{
	if (a->size <= 1)
		return;
	a->top = a->top->next;
	ft_putstr_fd("ra\n", 1);
}

void rb(t_stack *b)
{
	if (b->size <= 1)
		return;
	b->top = b->top->next;
	ft_putstr_fd("rb\n", 1);
}

void rr(t_stack *a, t_stack *b)
{
	if (a->size <= 1)
		return;
	a->top = a->top->next;
	if (b->size <= 1)
		return;
	b->top = b->top->next;
	ft_putstr_fd("rr\n", 1);
}

void rra(t_stack *a)
{
	if (a->size <= 1)
		return;
	a->top = a->top->prev;
	ft_putstr_fd("rra\n", 1);
}

void rrb(t_stack *b)
{
	if (b->size <= 1)
		return;
	b->top = b->top->prev;
	ft_putstr_fd("rrb\n", 1);
}

void rrr(t_stack *a, t_stack *b)
{
	if (a->size <= 1)
		return;
	a->top = a->top->prev;
	if (b->size <= 1)
		return;
	b->top = b->top->prev;
	ft_putstr_fd("rrr\n", 1);
}
