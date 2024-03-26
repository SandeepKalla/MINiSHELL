
#include <sh.h>

char	*ft_getenv(const char *path)
{
	int		path_size;
	char	*aux;
	char	*ret;
	t_list	*tmp;

	tmp = *g_sh.env;
	aux = ft_strjoin(path, "=");
	path_size = ft_strlen(aux);
	while (tmp)
	{
		if (ft_strncmp(aux, (char *)tmp->data, path_size) == 0)
		{
			ret = ft_substr((char *)tmp->data, path_size,
					ft_strlen((char *)tmp->data) - path_size);
			free(aux);
			return (ret);
		}
		tmp = tmp->next;
	}
	free(aux);
	return (NULL);
}
