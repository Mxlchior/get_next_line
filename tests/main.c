/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrelli <melchior.grellier42@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 03:29:26 by megrelli          #+#    #+#             */
/*   Updated: 2025/12/18 04:05:45 by megrelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

int main()
{
	int	fd;
	char	*line;

	fd = open("tests/test_ninho.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		return (1);
	}
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line == NULL)
			break ;
		free(line);
	}
	close(fd);
	return (0);
}
