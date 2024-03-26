
#include <sh.h>

/* on other states */
void	handle_other_st(t_lexsup *ls)
{
	if (ls->st == ST_IN_QUOTE)
	{
		ls->tok->data[ls->j++] = ls->c;
		if (ls->type == CHAR_QOUTE)
			ls->st = ST_GEN;
	}
	else if (ls->st == ST_IN_DQUOTE)
	{
		ls->tok->data[ls->j++] = ls->c;
		if (ls->type == CHAR_DQOUTE)
			ls->st = ST_GEN;
	}
	else if (ls->st == ST_IN_CURLY)
	{
		ls->tok->data[ls->j++] = ls->c;
		if (ls->type == CHAR_CCL)
			ls->st = ST_GEN;
	}
}
