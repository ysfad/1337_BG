#include "push_swap.h"

int ft_sorted_checker(t_stack **a, int cas)
{
	t_stack	*tmp;

	tmp = *a;
	while(tmp->next)
	{
		if(tmp->num > tmp->next->num)
			break;
		tmp = tmp->next;
	}
	if(tmp->next == NULL && cas == 1)
	{
		free_node(a);
		exit(0);
	}
    else if(tmp->next == NULL)
        return (1);
    return (0);
}

long	ft_count_size(t_stack **a, t_stack**b)
{
	long	i;
	long	count;
	t_stack *tmp;

	count = 0;
	tmp = *b;
	while(tmp)
	{
		tmp = tmp->next;
		count++;
	}
	i = 0;
	while (count > i)
	{
		ft_push(b, a);
		i++;
	}
	return (count);
}

void	ft_dup_checker(t_stack **a)
{
	int num;
	t_stack *tmp;
	t_stack	*tmp2;

	tmp = *a;
	while(tmp->next)
	{
		tmp2 = tmp->next;
		num = tmp->num;
		while(tmp2)
		{
			if (tmp2->num == num)
				ft_error(a);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}
