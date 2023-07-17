/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushswap.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kyuuh <kyuuh@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/06 17:19:46 by kyuuh         #+#    #+#                 */
/*   Updated: 2023/02/02 20:59:04 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

typedef struct top
{
	int	a;
	int	b;
	int	malsize;
}	t_tops;

typedef struct stk
{
	int		*stack_a;
	int		*stack_b;
}	t_stacks;

void	pushback_a(t_stacks *stk, t_tops *top, int push);

int		returnpivot(int *stack, int push, int top);

int		lenarg(char **arg);
int		check_input(char *toadd);
void	ft_freee(char **str);
void	argorstr(int argc, char **argv, t_tops *top, int **stack_a);
int		ft_atoi_overflow(char *str, int *number);
int		freeab(int *stack_a, int *stack_b);

void	smallsorta(int **stack, char e, int top);
void	smallsortb(int **stack, int top);

int		checker(int *stack, t_tops *top, char *toadd);
void	stackcrea(int argc, char **argv, t_tops *top, int **stack_a);

int		pusha(t_stacks *stk, t_tops *top, char e);
int		pushb(t_stacks *stk, t_tops *top, char e);
int		swapa(int **stack, int top, char c);
int		swapb(int **stack, int top, char c);
int		swaps(int **stack_a, int **stack_b, t_tops *top, char e);
int		rotabs(int **stack_a, int **stack_b, t_tops *top, char e);
int		rota(int **stack, int top, char c);
int		rotb(int **stack, int top, char c);
int		revrota(int **stack, int top, char c);
int		revrotb(int **stack, int top, char c);
int		revrotabs(int **stack_a, int **stack_b, t_tops *top, char e);

void	backa(int **stack, int top, int itenb, int pushn);
void	backb(int **stack, int top, int itenb, int pushn);

void	quicksort_a(t_stacks *stk, t_tops *top, int push);
void	quicksort_b(t_stacks *stk, t_tops *top, int push);

void	smola(t_stacks *stk, char e, t_tops *top);
void	endsmola(t_stacks *stk, char e, t_tops *top);
void	smolb(t_stacks *stk, char e, t_tops *top);
void	endsmolb(t_stacks *stk, char e, t_tops *top);
void	issmola(t_stacks *stk, char e, t_tops *top, int push);
void	issmolb(t_stacks *stk, char e, t_tops *top, int push);

void	swap_from_a(t_stacks *stk, t_tops *top);
void	swap_from_b(t_stacks *stk, t_tops *top);

#endif