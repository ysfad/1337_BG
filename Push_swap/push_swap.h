/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:51:00 by yakhadad          #+#    #+#             */
/*   Updated: 2024/05/31 09:51:09 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct stack
{
	int				num;
	struct stack	*next;
}					t_stack;

void				ft_error(t_stack **a);
void				free_str(char **str);
void				ft_str_error(t_stack **a, char **str);
void				ft_check_node(t_stack **a, t_stack **b);
void				free_node(t_stack **node);
void				ft_split_2(t_stack **a, char *s);
void				ft_stack_checker(t_stack **a, char **s);
void				ft_fill_a(t_stack **a, t_stack **b, long size);
void				ft_swap(t_stack *x);
void				ft_rotate(t_stack **x);
void				ft_reverse_rotate(t_stack **x);
void				ft_push(t_stack **src, t_stack **dst);
void				action(char *s, t_stack **a, t_stack **b);
void				ft_dup_checker(t_stack **a);
void				ft_sort_3(t_stack **a);
void				ft_sort_4(t_stack **a, t_stack **b);
void				ft_sort_5(t_stack **a, t_stack **b, long size, int *arr);
int					ft_sorted_checker(t_stack **a, int cas);
int					*ft_array(t_stack **a, long size);
long				ft_count_size(t_stack **s);
long				find_position(t_stack **a, int start, int end);
void				ft_big_sort(t_stack **a, t_stack **b, int *arr);

#endif
