
#include <sh.h>

char	**get_env_char(void)
{
	char	**env;
	t_list	**aux;
	int		i;

	i = 0;
	env = (char **)malloc(sizeof(char *) * (ft_lstsize(*g_sh.env) + 1));
	aux = g_sh.env;
	while (*aux)
	{
		env[i++] = ft_strdup((char *)(*aux)->data);
		aux = &(*aux)->next;
	}
	env[i] = NULL;
	return (env);
}
