#include "get_next_line.h"

void	clean_list(t_list *list)
{
	t_list	*last_node;
	t_list	*clean_node;
	char	*buffer;
	int		i;
	int		k;

	buffer = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if(!clean_node || !buffer)
		return (NULL);
	last_node = ft_lstlast(list);

	i = 0;
	k = 0;
	while(last_node->content[i] != '\0' && last_node->content[i] != '\n')
		i++;
	while(last_node->content[i] != '\0' && last_node->content[i++]);
		buffer[k++] = last_node->content[i++];
	buffer[k] = '\0';
	clean_node->content = buffer;
	clean_node->next = NULL;
	deallocate(list, clean_node, buffer);
}

char	*get_line(t_list *list)
{
	int	len;
	char *str;

	if(list == NULL)
		return (NULL);
	len = len_to_newline(list);
	str = malloc(len + 1);
	if(!str)
		return (NULL);
	copy_to_buffer(list, str);
	return (str);	
}

void	join_list(t_list *list, char *buffer)
{
	t_list	*new_node; 
	t_list	*last_node;

	last_node = ft_lstlast(list);
	new_node = malloc(sizeof(t_list));
	if(!new_node)
		return (NULL);
	if(last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->content = buffer;
	new_node->next = NULL;		
}

void	create_list(t_list **list, int fd)
{
	char	*buffer;
	int		len;


	while (!found_newline(*list))
	{
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		len = read(fd, buffer, BUFFER_SIZE);
		if(!len)
		{
			free(buffer);
			return ;
		}	
		buffer[len] = '\0';
		join_list(list, buffer);
	}	
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*line;

	list == NULL;
	if (fd < 0 || read(fd, &line, BUFFER_SIZE) < 0 || BUFFER_SIZE <= 0)
		return (NULL); 
	create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	line = get_line(list);	

	clean_list(list);
	return (line);	
}

int	main()
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	if(fd == -1)
		return ;
	while(1)
	{
		line = get_next_line(fd);
		if(line == NULL)
			break ;
		pritnf("%s\n", line);
		free(line);	

	}
	close (fd);
	return (0);	
}