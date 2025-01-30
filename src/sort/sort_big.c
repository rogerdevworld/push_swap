#include "../../include/push_swap.h"

//tengo problemas con la constante fue modificada a 0.532
int chuncks_opimi(int argc)
{
    int chunks = 0;
    const double Z = 0.532;

    if (argc <= 6)
        return 1;  // Al menos 1 chunk para listas pequeñas

    // Calculamos los chunks para listas grandes y redondeamos
    chunks = (int)(ft_sqrt(argc - 1) * Z + 0.5);  // Redondeo al entero más cercano
    return (chunks);
}


// aplicar index
void assign_indices(t_stack *stack)
{
    t_stack *tmp;
    t_stack *comparator;
    int index;

    if (!stack)
        return;
    tmp = stack;
    while (1)
    {
        index = 1;
        comparator = stack;
        while (1)
        {
            if (comparator->value < tmp->value)
                index++;
            comparator = comparator->next;
            if (comparator == stack)
                break;
        }
        tmp->index = index;
        tmp = tmp->next;
        if (tmp == stack)
            break;
    }
}

// aplicar index de chunck
void assign_chunks(t_stack *stack, int num_chunks)
{
    if (!stack || num_chunks <= 0)
        return;

    size_t max_index = 0;
    t_stack *tmp = stack;
    t_stack *start = stack;
    while (tmp->next != start)
    {
        if (tmp->index > max_index)
            max_index = tmp->index;
        tmp = tmp->next;
    }
    if (tmp->index > max_index)
        max_index = tmp->index;
    size_t range = (max_index) / num_chunks + ((max_index) % num_chunks != 0);
    tmp = stack;
    while (tmp->next != start)
    {
        tmp->group = (max_index - tmp->index) / range;
        tmp = tmp->next;
    }
    tmp->group = (max_index - tmp->index) / range;
}

// Función para encontrar el elemento más rentable para mover 
t_stack *find_best_element(t_stack *stack)
{
    if (!stack)
        return NULL;
    t_stack *best = stack;
    t_stack *tmp = stack;
    while (tmp->next != stack)
    {
        if (tmp->group > best->group || (tmp->group == best->group))
            best = tmp;
        tmp = tmp->next;
    }
    if (tmp->group > best->group || (tmp->group == best->group))
        best = tmp;
    return (best);
}

// Determinar si usar ra o rra para mover el elemento al tope
int calculate_cost(t_stack *stack, t_stack *target)
{
    size_t size = size_stack(stack);
    size_t forward_steps = 0;
    size_t backward_steps = 0;

    t_stack *tmp = stack;
    while (tmp != target)
    {
        forward_steps++;
        tmp = tmp->next;
    }
    backward_steps = size - forward_steps;
    if (forward_steps <= backward_steps)
        return (1);
    else
        return (-1);
}

// Función para mover el elemento más rentable al tope y pasarlo al stack_b
void optimize_and_push(t_stack **stack_a, t_stack **stack_b)
{
    if (!stack_a || !*stack_a)
        return;
    t_stack *best = find_best_element(*stack_a);
    if (!best)
        return;
    int direction = calculate_cost(*stack_a, best);
    while (*stack_a != best)
    {
        if (direction == 1)
            ft_ra_rotate_a(stack_a, 1);
        else
            ft_rra_reverse_a(stack_a, 1);
    }
    ft_pb_push_b(stack_a, stack_b);
}

//función para pasar todos los grupos menos el 0
//pasa el nodo en orden ascendente de grupo
void pass_group_to_b(t_stack **stack_a, t_stack **stack_b, int argc)
{
    if (!stack_a || !*stack_a)
        return;

    int max_group = get_max_group(*stack_a);
    int max = 0;
    t_stack *tmp = *stack_a;
    t_stack *start = *stack_a;
    while (1) {
        if (tmp->group != 0)
            optimize_and_push(stack_a, stack_b);
        tmp = tmp->next;
        max++;
        if (max > 3000)
            break ;
    }
}

//vale ahora vamos por una version de la segunda parte suponiendo que ya tenemos 
//todos los chuncks en orden

// Función para encontrar el elemento más rentable para mover al a
t_stack *find_best_element_to_a(t_stack *stack)
{
    if (!stack)
        return NULL;

    t_stack *best = stack;
    t_stack *tmp = stack;

    while (tmp->next != stack)
    {
        if (tmp->index > best->index)
            best = tmp;
        tmp = tmp->next;
    }
    if (tmp->index > best->index)
        best = tmp;
    return (best);
}

// Función para mover el elemento más rentable al tope y pasarlo al stack_b
void optimize_and_push_to_b(t_stack **stack_a, t_stack **stack_b)
{
    if (!stack_b || !*stack_b)
        return;
    t_stack *best = find_best_element_to_a(*stack_b);
    if (!best)
        return;
    int direction = calculate_cost(*stack_b, best);
    while (*stack_b != best)
    {
        if (direction == 1)
            ft_rb_rotate_b(stack_b, 1);
        else
            ft_rrb_reverse_b(stack_b, 1);
    }
    ft_pa_push_a(stack_a, stack_b);
}

//función para pasar todos los grupos menos el 0
//pasa el nodo en orden ascendente de grupo
void go_to_a(t_stack **stack_a, t_stack **stack_b, int argc)
{
    if (!stack_b || !*stack_b)
        return;
    t_stack *tmp = *stack_b;
    t_stack *start = *stack_b;
    do {
        if (tmp->group != 0)
            optimize_and_push_to_b(stack_a, stack_b);
        tmp = tmp->next;
    } while (tmp != start);
}

void    sort_fixed(t_stack **stack_a, t_stack **stack_b)
{
    int max = 4;

    if (sorted(*stack_b))
    {
        if (size_stack(*stack_b) == 2)
            ft_sb_swap_b(stack_b, 1);
        while (*stack_b)
         ft_pa_push_a(stack_a, stack_b);
    }
    else
    {
        while (max--)
            optimize_and_push_to_b(stack_a, stack_b);
    }
}
