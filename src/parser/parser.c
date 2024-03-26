
#include <sh.h>

/* parse main function */
int	parse(t_lexer *lex, t_ast **ast)
{
	g_sh.tok = lex->tok_lst;
	g_sh.ao_ast = (t_ast **)malloc(sizeof(t_ast *));
	*g_sh.ao_ast = NULL;
	*ast = cmd_line();
	if (lex->n_toks == 0)
		return (1);
	if (g_sh.tok != NULL && g_sh.tok->type != 0)
	{
		ft_dprintf(STDERR_FILENO, "error: syntax error near: %s\n",
			g_sh.tok->data);
		free(g_sh.ao_ast);
		return (1);
	}
	free(g_sh.ao_ast);
	return (0);
}
