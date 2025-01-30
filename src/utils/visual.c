#include "../../include/push_swap.h"

// Función para visualizar la pila con colores
void visual(t_stack *stack, int argc)
{
    int i;
    int tmp;
    int bg_color;
    i = argc;

    while (stack && i)
    {
        tmp = 0;
        bg_color = 41 + (stack->group % 7);
        printf("\033[%dm", bg_color);
        while (tmp < stack->value)
        {
            printf(" ");
            tmp++;
        }
        printf("\033[0m\n");
        stack = stack->next;
        i--;
    }
}
//mas detalles dentro de las pilas 
//printf("Nodo: valor=%d, grupo=%d, color=%d\n", stack->value, stack->group, bg_color);