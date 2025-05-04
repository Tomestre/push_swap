#include "push_swap.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        return 0;
    }

    // Inicializar stack
    t_stack *a = malloc(sizeof(t_stack));
    t_stack *b = malloc(sizeof(t_stack));
    if (!a || !b) {
        return 1;
    }
    a->top = NULL;
    a->size = 0;
    b->top = NULL;
    b->size = 0;

    // Parsear entrada (simplificado por agora)
    for (int i = 1; i < argc; i++) {
        int value = atoi(argv[i]);
        t_node *node = new_node(value);
        if (!node) {
            // Tratar erro
            return 1;
        }
        push(a, node);
    }

    // Aqui você adicionará o algoritmo de ordenação
    // Por enquanto, apenas um teste simples
    if (a->size >= 2) {
        sa(a);
    }

    // Liberar memória (a ser implementado)
    // free_stacks(a, b);

    free(a);
    free(b);
    return 0;
}