
#include <sh.h>

/* execute syntax tree */
int	exec_ast(t_ast *ast)
{
	handle_cmd_line(ast);
	return (0);
}

/* handle all heredocs */
int	exec_heredoc(t_ast *ast)
{
	if (hd_cmd_line(ast))
		return (1);
	return (0);
}
