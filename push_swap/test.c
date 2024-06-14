
#include "push_swap.h"

void	ft_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

int	ft_atoi_v2(const char *s)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	nb = 0;
	sign = 1;
	while (s[i] == '\t' || s[i] == '\r' || s[i] == '\f' || s[i] == '\v'
		|| s[i] == '\n' || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[0] == '-')
			sign = -1;
		i++;
	}
	while (s[i] > 47 && s[i] < 58)
	{
		nb = nb * 10 + (s[i] - 48);
		i++;
	}
	if (s[i] != 0 || i == 0 || ((s[i - 1] == '-' || s[i - 1] == '+')
			&& s[i] == 0) || nb * sign < -2147483648 || nb * sign > 2147483647)
		ft_error();
	return (nb * sign);
}

void	ft_stack_filler(t_stack **b, char *s)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack));
	if (tmp == NULL)
		ft_error();
	tmp->num = ft_atoi_v2(s);
	tmp->next = *b;
	*b = tmp;
	tmp = NULL;
}

void	ft_stack_checker(t_stack **b, char **s)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	while (s[i])
	{
		x = 0;
		j = 0;
		while (s[i] && s[i][j] && x == 0)
		{
			if (s[i][j] != ' ' && !(s[i][j] >= '0' && s[i][j] <= '9')
				&& s[i][j] != '-' && s[i][j] != '+')
				ft_error();
			if (s[i][j] == ' ')
			{
				ft_stack_checker(b, ft_split(s[i], ' '));
				x = 1;
			}
			j++;
		}
		if (x == 0)
			ft_stack_filler(b, s[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	int		i;
	t_stack	*a;
	t_stack	*b;
	t_stack	*tmp;

	i = 1;
	a = NULL;
	b = NULL;
	if (ac < 2)
		ft_error();
	av++;
	ft_stack_checker(&a, av);
	tmp = a;
	while (tmp)
	{
		ft_printf("%i ", tmp->num);
		tmp = tmp->next;
	}
	ft_printf("\n");
}
