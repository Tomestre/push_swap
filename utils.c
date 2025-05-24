#include "push_swap.h"

int is_valid_integer(char *str)
{
    if (!str || !*str)
        return 0;
    if (*str == '-' || *str == '+')
        str++;
    if (!*str)
        return 0;
    while (*str)
    {
        if (!ft_isdigit(*str))
            return 0;
        str++;
    }
    // Verificar limites de int (simplificado)
    long value = ft_atoi(str);
    if (value > 2147483647 || value < -2147483648)
        return 0;
    return 1;
}

int check_duplicates(t_stack *stack, int value)
{
    t_node *current = stack->top;
    if (!current)
        return 0;
    int steps = stack->size;
    while (steps--)
    {
        if (current->value == value)
            return 1;
        current = current->next;
    }
    return 0;
}

void print_stack(t_stack *stack, char *name)
{
    ft_putstr_fd(name, 1);
    ft_putstr_fd(":\n", 1);
    if (!stack || !stack->top)
    {
        ft_putstr_fd("(empty)\n", 1);
        return;
    }
    t_node *current = stack->top;
    int steps = stack->size;
    while (steps--)
    {
        ft_putstr_fd("| ", 1);
        ft_putnbr_fd(current->value, 1);
        ft_putstr_fd(" |\n", 1);
        current = current->next;
    }
    ft_putstr_fd("-----\n", 1);
}
