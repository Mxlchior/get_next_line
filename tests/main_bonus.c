/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrelli <melchior.grellier42@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 04:07:13 by megrelli          #+#    #+#             */
/*   Updated: 2025/12/18 04:54:24 by megrelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line_bonus.h"

int main()
{
	int	fd1, fd2, fd3, fd4;
	char	*line1, *line2;
	int	finished;
	
	fd1 = open("tests/test_ninho.txt", O_RDONLY);
	fd2 = open("tests/test_binks.txt", O_RDONLY);
	if (fd1 < 0 || fd2 < 0 || fd3 < 0 || fd4 < 0)
	{
		perror("Error");
		return (1);
	}
	finished = 0;
	while (!finished)
	{
		finished = 1;
		line1 = get_next_line(fd1);
		if (line1)
		{
			printf("[fd %d]: %s", fd1, line1);
			free(line1);
			finished = 0;
		}
		line2 = get_next_line(fd2);
		if (line2)
		{
			printf("[fd %d]: %s", fd2, line2);
			free(line2);
			finished = 0;
		}
	}
	close(fd1);
	close(fd2);
	return (0);
}