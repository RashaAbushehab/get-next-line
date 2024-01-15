#include "get_next_line.h"

t_list	*ft_lstlast(t_list *lst)
{
    t_list	*tmp;
    tmp = lst;

    if (lst == NULL)
        return (NULL);
    while(tmp->next != NULL)
        tmp = tmp->next;
    return (tmp);
}

int	len_to_newline(t_list *list)
{
	int	i;
	int	len;

	if (list == NULL)
		return (NULL);
	while(list)
	{
		i = 0;
		while(list->content[i])
		{
			if(list->content[i] == '\0')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

void	copy_to_buffer(t_list	*list, char	*str)
{
	int	i;
	int	k;

	if (list == NULL)
		return (NULL);
	k = 0;
	while(list)
	{
		i = 0;
		while(list->content[i])
		{
			if(list->content[i] == '\n')
			{
				str[k++] = '\n';
				str[k] = '\0';
				return ;
			}
			str[k++] = list->content[i++];
		}
		list = list->next;
	}
	str[k] = '\0';
}

int	found_newline(t_list *list)
{
	int	i;

	if (list == NULL)
		return (0);
	while(list)
	{
		i = 0;
		while(list->content[i] && i < BUFFER_SIZE)
		{
			if (list->content[i] == '\0')
				return (1);
			i++;
		}
		list = list->next;
	}	
	return (0);
}

void	deallocate(t_list **list, t_list *clean_node, char *buffer)
{
	t_list *tmp;

	if (list == NULL)
		return (NULL);
	while(*list)
	{
		tmp = (*list)->next;
		free((*list)->content);
		free((*list));
		*list = tmp;
	}
	*list = NULL;
	if (clean_node->content[0])
		*list = clean_node;
	else
	{
		free(buffer);
		free(clean_node);
	}	
}