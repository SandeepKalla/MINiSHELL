
#include <sh.h>

/* get node type */
int	ast_gettype(t_ast *ast)
{
	return (ast->type & (~AST_DATA));
}

/* delete tree */
void	ast_del(t_ast *ast)
{
	if (ast == NULL)
		return ;
	if (ast->type & AST_DATA)
		free(ast->data);
	ast_del(ast->left);
	ast_del(ast->right);
	free(ast);
}

/* attach leafs to node */
void	ast_attach(t_ast *root, t_ast *left, t_ast *right)
{
	if (root == NULL)
		return ;
	root->left = left;
	root->right = right;
}

/* set node type */
void	ast_settype(t_ast *ast, t_asttype type)
{
	if (ast == NULL)
		return ;
	ast->type = type;
}

/* set node data */
void	ast_setdata(t_ast *ast, char *data)
{
	if (ast == NULL || data == NULL)
		return ;
	ast->data = data;
	ast->type |= AST_DATA;
}
