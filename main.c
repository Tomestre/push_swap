#include "push_swap.h"

int main(int argc, char **argv)
{
    if (argc < 2)
        return 0;

    // Inicializar pilhas
    t_stack *a = ft_calloc(1, sizeof(t_stack));
    t_stack *b = ft_calloc(1, sizeof(t_stack));
    if (!a || !b)
    {
        ft_putstr_fd("Error\n", 2);
        free_stack(a);
        free_stack(b);
        return 1;
    }
    a->top = NULL;
    a->size = 0;
    b->top = NULL;
    b->size = 0;

    // Parsear e preencher pilha A (primeiro argumento no topo)
    int i = argc - 1;
    while (i >= 1)
    {
        if (!is_valid_integer(argv[i]))
        {
            ft_putstr_fd("Error\n", 2);
            free_stack(a);
            free_stack(b);
            return 1;
        }
        int value = ft_atoi(argv[i]);
        if (check_duplicates(a, value))
        {
            ft_putstr_fd("Error\n", 2);
            free_stack(a);
            free_stack(b);
            return 1;
        }
        t_node *node = new_node(value);
        if (!node)
        {
            ft_putstr_fd("Error\n", 2);
            free_stack(a);
            free_stack(b);
            return 1;
        }
        push(a, node);
        i--;
    }

   // Imprimir pilhas antes da operação
    /*print_stack(a, "Stack A");
    print_stack(b, "Stack B");*/

    // Chamar algoritmo de ordenação
    sort_stack(a, b);

        // Imprimir pilhas após a operação
       /* ft_putstr_fd("Final\n", 1);
        print_stack(a, "Stack A");
        print_stack(b, "Stack B");*/

    // Liberar memória
    free_stack(a);
    free_stack(b);
    return 0;
}
