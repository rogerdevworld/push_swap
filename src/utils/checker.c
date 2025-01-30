#include "../../include/push_swap.h"

// --- caso de 3 elementos ---
void checker(t_stack *stack)
{
    if (!sorted(stack))
        printf("\033[0;31m[KO]\033[0m");
    else
        printf("\033[0;32m[OK]\033[0m\n");
}