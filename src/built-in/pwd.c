
#include <sh.h>

static void	print_pwd(const char *pwd)
{
	write(STDOUT_FILENO, pwd, ft_strlen(pwd));
	write(STDOUT_FILENO, "\n", 1);
}

int	ft_get_wdir(char **n)
{
	char	*pwd;

	pwd = (char *)malloc(sizeof(char) * PATH_MAX);
	if (!pwd)
		return (1);
	(void)n;
	if (getcwd(pwd, PATH_MAX) == NULL)
	{
		free(pwd);
		pwd = NULL;
	}
	if (pwd == NULL)
		pwd = ft_getenv("PWD");
	if (pwd == NULL)
		return (1);
	print_pwd(pwd);
	free(pwd);
	return (0);
}
