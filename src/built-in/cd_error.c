
#include <sh.h>

int	print_error(const char *dir)
{
	if (dir)
	{
		write(STDERR_FILENO, "cd: ", 4);
		write(STDERR_FILENO, dir, ft_strlen(dir));
		write(STDERR_FILENO, ": no such file or directory:\n", 29);
	}
	else
		write(STDERR_FILENO, "cd: HOME not set\n", 17);
	return (1);
}

int	home_handler(void)
{
	if (goto_home() == 1)
		return (1);
	return (0);
}

void	set_env(t_list *env)
{
	locate_env(env);
}
