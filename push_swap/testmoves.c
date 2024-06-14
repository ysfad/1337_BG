#include "push_swap.h"

void    ft_swap(t_stack *x)
{
    if (x && x->next)
    {
        int nbtmp;
        t_stack *tmp;

        nbtmp = 0;
        tmp = x;
        while(tmp->next->next)
            tmp = tmp->next;
        nbtmp = tmp->num;
        tmp->num = tmp->next->num;
        tmp->next->num = nbtmp;
    }
}

void    ft_rotate(t_stack **x)
{
    t_stack *tmp;
    t_stack *tmp2;

    if (*x && (*x)->next)
    {
        tmp = *x;
        while(tmp->next->next)
            tmp = tmp->next;
        tmp2 = tmp->next;
        tmp->next = NULL;
        tmp2->next = *x;
        *x = tmp2;
    }
}

void    ft_reverse_rotate(t_stack **x)
{
    t_stack *tmp;
    t_stack *tmp2;
    if (*x && (*x)->next)
    {
        tmp = *x;
        while(tmp->next)
            tmp = tmp->next;
        tmp->next = *x;
        *x = (*x)->next;
        tmp->next->next = NULL;
    }
}

void    ft_last_t_stack(t_stack **src, t_stack **dst)
{
    t_stack   *tmp;

    tmp = *dst;
    while(tmp->next)
        tmp = tmp->next;
    tmp->next = *src;
    *src = NULL;
}

void    ft_push(t_stack **src, t_stack **dst)
{
    t_stack *tmp;
    t_stack *tmp2;

    if (*src)
    {
        if ((*src)->next)
        {
            tmp = *src;
            tmp2 = *dst;
            while(tmp->next->next)
                tmp = tmp->next;
            if (*dst == NULL)
                    *dst = tmp->next;
            else
            {
                while(tmp2->next)
                    tmp2 = tmp2->next;
                tmp2->next = tmp->next;
            }
            tmp->next = NULL;
        }
        else
            ft_last_t_stack(src, dst);
    }
}

