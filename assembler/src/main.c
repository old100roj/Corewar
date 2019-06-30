/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:28:13 by iganich           #+#    #+#             */
/*   Updated: 2019/01/31 15:28:14 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "asm.h"
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

unsigned int	start_asm(int fd_from, unsigned char **word)
{
	char			*line;
	t_address		*head;
	int				row;
	t_header		*header;
	unsigned int	res;

	line = NULL;
	head = NULL;
	row = 0;
	header = make_header(&row, fd_from);
	header->prog_size = 0;
	while (get_next_line(fd_from, &line))
	{
		row++;
		if (line && line[0] && line[0] != COMMENT_CHAR)
			header->prog_size += parse_line(line, &head, row);
		ft_strdel(&line);
	}
	if (!line)
		ft_handle_errors(make_error(row, 0, 15, &head), NULL);
	make_code(&head, header, word);
	res = header->prog_size;
	free(header);
	ft_strdel(&line);
	return (res);
}

char			*make_file_name(const char *file)
{
	char	*res;
	size_t	i;
	size_t	len;

	i = ft_strlen(file) - 1;
	if (!file[i] || file[i] != 's' || !file[i - 1] || file[i - 1] != '.')
	{
		ft_printf("ERROR - file name doesn't end with .s\n");
		exit(EXIT_FAILURE);
	}
	i -= 2;
	len = 0;
	while (i > 0 && file[i] != '/' && ++len)
		i--;
	res = ft_strnew(len);
	if (i != 0)
		i++;
	len = 0;
	while (i <= ft_strlen(file) - 3)
	{
		res[len] = file[i];
		i++;
		len++;
	}
	return (res);
}

void			start_processing(const char *file)
{
	int				fd_from;
	char			*file_name;
	unsigned char	*word;
	int				fd_to;
	int				len;

	fd_from = open(file, O_RDONLY);
	if ((fd_from < 0 || read(fd_from, 0, 0) < 0) &&
		ft_printf("Error - %s: %s\n", file, strerror(errno)))
		exit(EXIT_FAILURE);
	file_name = make_file_name(file);
	ft_strconcat(&file_name, ".cor", ft_strlen(file_name), 4);
	word = ft_str_unsigned_new(0);
	len = start_asm(fd_from, &word);
	close(fd_from);
	fd_to = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_to < 0 && ft_printf("Error - %s: %s\n", file_name, strerror(errno)))
		exit(EXIT_FAILURE);
	ft_printf("Writing output program to %s\n", file_name);
	write(fd_to, (char *)word, len + PROG_NAME_LENGTH + 16 + COMMENT_LENGTH);
	ft_str_unsigned_del(&word);
	close(fd_to);
	ft_strdel(&file_name);
}

int				main(int argc, const char *argv[])
{
	if (argc != 2)
	{
		ft_printf("ERROR - usage ./asm filename\n");
		return (EXIT_FAILURE);
	}
	start_processing(argv[1]);
	return (0);
}
