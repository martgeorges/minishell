/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:19:09 by laichoun          #+#    #+#             */
/*   Updated: 2024/02/28 12:48:33 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd((n / 10), fd);
	}
	ft_putchar_fd('0' + (n % 10), fd);
}
/*
#include "libft.h"
#include <fcntl.h> // Pour les constantes O_WRONLY et O_CREAT
#include <unistd.h> // Pour la fonction close

int main(void)
{
    int fd;

    // Ouvre un fichier "output.txt" en écriture (crée fich si existe pas)
    fd = open("output.txt", O_WRONLY | O_CREAT, 0666);

    // Affiche l'entier 12345 dans le fichier "output.txt"
    ft_putnbr_fd(12345, fd);

    // Ferme le descripteur de fichier une fois qu'on a fini de l'utiliser
    close(fd);

    return (0); // Fin du programme sans erreur
}
*/
