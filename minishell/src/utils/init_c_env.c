#include "../../headers/minishell.h"

void	init_c_env(t_cmd_env *c, char **env)
{
	c->hdoc_expand = 1;
	c->input = NULL;
	c->stdin_cpy = -2;
	c->stdout_cpy = -2;
	c->parsing_error = 0;
	c->hashmap = NULL;
	c->exit_code = 0;
	c->paths = NULL;
	c->num_of_cmds = 1;
	c->pid = NULL;
	c->pipes = NULL;
	c->env_copy = env;
	c->hashmap = init_hmap(env);
	if (!c->hashmap)
		malloc_error();
	c->PWD = ft_strdup(get_value_hmap(c->hashmap, "PWD")->value);
	if (!c->PWD)
		malloc_error();
	add_shelllevel(c->hashmap);
}
