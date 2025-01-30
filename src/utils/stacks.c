/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:26:29 by rmarrero          #+#    #+#             */
/*   Updated: 2024/11/05 16:27:54 by rmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

// --- inicializar el nodo ---
t_stack  *ft_create_value(int value)
{
    t_stack  *new_value;

    new_value = (t_stack *)malloc(sizeof(t_stack));
    if (!new_value)
        return (NULL);
    new_value->value = value;
    new_value->index = 0;
    new_value->group = 1;
    new_value->next = NULL;
    new_value->prev = NULL;
    return (new_value);
}

// --- obtener ultimo nodo---
t_stack  *ft_get_last_value(t_stack *list)
{
    if (!list)
        return (NULL);
    while(list->next)
        list = list->next;
    return (list);

}

// --- anadir al final del stack ---
void    ft_add_back_the_list(t_stack **list, t_stack *new_value)
{
	t_stack	*last_value;

	if (!list || !new_value)
		return ;
	if (!*list)
		*list = new_value;
	else
	{
		last_value = ft_get_last_value(*list);
        last_value->next = new_value;
        new_value->prev = last_value;
	}
}

// --- circular list link between the last and the first one ---
void    ft_linke_first_to_last(t_stack **stack)
{
    t_stack  *first_value;
    t_stack  *last_value;

    first_value = *stack;
    last_value = ft_get_last_value(*stack);
    if (!stack || !*stack || !(*stack)->next)
        return ;
    first_value->prev = last_value;
    last_value->next = first_value; 
}

// --- funcion para eliminar las listas ft_free() ---
void    free_stack(t_stack **stack)
{
    t_stack  *tmp;

    if (!stack)
        return ;
    while(*stack)
    {
        tmp = (*stack)->next;
        (*stack)->value = 0;
        free(*stack);
        *stack = tmp;
    }
    *stack = NULL;
}

// --- obtener tamano del stack ---
size_t size_stack(t_stack *stack)
{
    t_stack  *tmp;
    size_t i;

    if (!stack)
        return (0);
    i = 0;
    tmp = stack;
    while (tmp->next && tmp->next != stack)
    {
        i++;
        tmp = tmp->next;
    }
    return (i + 1);
}