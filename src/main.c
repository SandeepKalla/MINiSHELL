
#include <sh.h>

/* global var */
t_sh	g_sh;

/* check if line is blank */
int	line_is_blank(char *line)
{
	char	*aux;

	aux = line;
	while (*aux != '\0')
	{
		if (ft_isblank(*aux) == 0)
			break ;
		aux++;
	}
	if (*aux == '\0')
		return (1);
	return (0);
}

/* main */
int	main(int argc, char *argv[])
{
	char	*line;

	init_shell();
	handle_flags(argc, argv);
	while (1)
	{
		sig_parent();
		g_sh.is_expd = FALSE;
		g_sh.is_child = FALSE;
		line = read_prompt();
		if (line == NULL)
		{
			write(STDOUT_FILENO, "exit\n", 5);
			exit(g_sh.status);
		}
		if (ft_strlen(line) <= 0)
		{
			free(line);
			continue ;
		}
		if (line_is_blank(line) == 0)
			add_history(line);
		handle_line(line, TRUE);
	}
	return (EXIT_SUCCESS);
}
