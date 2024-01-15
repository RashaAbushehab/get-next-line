#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
} t_list;

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
# endif
char	*get_next_line(int fd);
void	clean_list(t_list *list);
char	*get_line(t_list *list);
void	join_list(t_list *list, char *buffer);
void	create_list(t_list **list, int fd);
t_list	*ft_lstlast(t_list *lst);
int	len_to_newline(t_list *list);
void	copy_to_buffer(t_list	*list, char	*str);
int	found_newline(t_list *list);
void	deallocate(t_list **list, t_list *clean_node, char *buffer);


#endif
