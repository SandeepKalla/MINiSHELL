
#ifndef SIGNALS_H
# define SIGNALS_H

/*** DEFINES ***/

# define SIGINT_EXIT 130
# define SIGQUIT_EXIT 131

/*** PROTOTYPES ***/

/* utils/signals.c */
void	sig_heredoc(void);
void	sig_child(void);
void	sig_parent(void);
void	sig_ignore(void);

#endif
