#include "../../headers/minishell.h"

t_file	*file_lstnew(char *file, int fd, int append)
{
	t_file	*new;

	new = (t_file *)malloc(sizeof(t_file));
	if (!new)
		return (NULL);
	new->file = file;
	new->fd = fd;
	new->append = append;
	new->next = NULL;
	return (new);
}

void	file_lstadd_back(t_file **lst, t_file *new)
{
	t_file	*node;

	if (!new)
		return ;
	else if (*lst == NULL)
		*lst = new;
	else
	{
		node = *lst;
		while (node->next)
			node = node->next;
		node->next = new;
	}
}

void	file_lstclear(t_file **lst, int rm_hdoc)
{
	t_file	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		if ((*lst)->fd >= 0)
			close((*lst)->fd);
		if (rm_hdoc == 1)
			unlink((*lst)->file);
		free((*lst)->file);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}
