#include "../../headers/minishell.h"

void	error_msg(char *c, char *str)
{
	write(2, "minishell: ", 12);
	if (c)
		write(2, c, ft_strlen(c));
	if (str)
		write(2, str, ft_strlen(str));
}

void	malloc_error(void)
{
	ft_putstr_fd("Memory allocation failed.\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_puterror(int code, char *str, t_cmd_data *cmd)
{
	char	*msg;
	char	*temp;

	if ((code == 127 || code == 126) && cmd)
	{
		temp = ft_strdup(cmd->args[0]);
		if (!temp)
			malloc_error();
		msg = ft_strjoin(temp, str);
		free(temp);
	}
	else
		msg = ft_strdup(str);
	if (!msg)
		malloc_error();
	ft_putendl_fd(msg, 2);
	free(msg);
	exit(code);
}

void	quote_error(void)
{
	write(2, "minishell: quote error\n", 24);
	exit(1);
}

void	error_exit(char *item, char *msg, t_cmd_data **d, int exit_code)
{
	ft_putstr_fd("minishell: ", 2);
	if (item)
	{
		ft_putstr_fd(item, 2);
		ft_putstr_fd(": ", 2);
	}
	if (!msg)
		perror("");
	else
		ft_putstr_fd(msg, 2);
	if (d && (*d)->env_ptr->num_of_cmds == 1 && is_builtin(*d))
	{
		(*d)->env_ptr->exit_code = exit_code;
		clear_structs(d, 1, (*d)->env_ptr);
	}
	else
	{
		if (d)
			free_all(d);
		exit(exit_code);
	}
}
