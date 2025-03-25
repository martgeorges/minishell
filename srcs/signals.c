/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:29:09 by laichoun          #+#    #+#             */
/*   Updated: 2024/10/24 10:31:39 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_ignore(int sig)
{
	(void)sig;
}

// rl_on_new_line();  --> pour pas avoir à taper entrée pour aller à la ligne
// rl_replace_line("", 1); --> vider le buffer et pas afficher la commande
// rl_redisplay(); --> pour réafficher le prompt à l'appel de readline

//ça c'est ctrl C avant readline
static void	signal_new_input(int sig)
{
	extern int	g_sig;

	g_sig = sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}

static void	signal_newline(int sig)
{
	(void)sig;
	write(1, "\n", 1);
}

void	signal_before(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, signal_new_input);
}

void	signal_after(void)
{
	signal(SIGINT, signal_newline);
}
