#include "push_swap.h"

static t_node *find_smallest(t_stack a)
{
	t_node *current_a;
	t_node *smallest;
	current_a = a->top->next;

	smallest = current_a;
	while(current_a != a->top)
	{
		if(current_a->value < smallest->value)
			smallest = current_a;
		current_a = current_a->next;
	}
	return(smallest);
}
static sort_b(t_stack *a, t_stack *b) 
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

		// Rotaciona A até o target_node do topo de B estar no topo
		while (a->top != b->top->target_node)
			ra(a); // ou rra(a), se quiser otimizar depois

		pa(a, b); // Move o topo de B para o topo de A
	}
}