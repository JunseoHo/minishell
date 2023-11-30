#include <signal.h>

void	handle_signal_2(int signo)
{
	(void)signo;
	g_exit_status = 1;
}

void	handle_signal(int signo)
{
	pid_t	pid;
	int		status;

	pid = waitpid(-1, &status, WNOHANG);
	if (signo == SIGINT)
	{
		if (pid == -1)
		{
			printf("\n");
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
			g_exit_status = 1;
		}
		else//자식 프로세스가 존재함
		{
			printf("부모 시그널\n");
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
			g_exit_status = 1;
		}
	}
	// else if (signo == SIGQUIT)
	// {
	// 	if (pid == -1)
	// 		ft_putstr_fd("\b\b  \b\b", STDOUT);
	// 	else
	// 		ft_putstr_fd("Quit: 3\n", STDOUT);
	// }
}

// void	do_sigint(int signum)
// {
// 	(void)signum;
// 	printf("\n");
// 	rl_on_new_line();
// 	rl_replace_line("", 0);
// 	rl_redisplay();
// 	g_exit_status = 1;
// }

void	set_terminal_print_off(void)
{
	struct termios	term;

	tcgetattr(1, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(1, 0, &term);
}

void	set_terminal_print_on(void)
{
	struct termios	term;

	tcgetattr(1, &term);
	term.c_lflag |= (ECHOCTL);
	tcsetattr(1, 0, &term);
}

void	set_default_signal(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}


void	set_signal(void)
{
	set_terminal_print_off();
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, SIG_IGN);
}