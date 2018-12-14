/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 09:19:54 by dpiven            #+#    #+#             */
/*   Updated: 2018/12/06 13:51:50 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strtrim_n(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (s[i] == '\n' && s[i])
		i++;
	return (&s[i]);
}

static char	*ft_strdup_chr(const char *s1, char c)
{
	char	*s2;
	int		len;
	int		i;

	i = 1;
	while (s1[i] != c && s1[i])
		i++;
	len = i;
	if (!(s2 = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (i < len && s1[i] != c)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

static char	*ft_allstr(char *allstr, int fd)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	*temp;

	if (allstr == NULL)
		allstr = ft_strnew(0);
	if (ft_strchr(allstr, '\n') == 0)
		while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
		{
			buf[ret] = '\0';
			temp = allstr;
			allstr = ft_strjoin(temp, buf);
			free(temp);
			if (ft_strchr(buf, '\n'))
				break ;
		}
	return (allstr);
}

t_list		*ft_searchlst(t_list **list, const int fd)
{
	t_list	*ptr;

	ptr = *list;
	while (ptr)
	{
		if (ptr->content_size == (size_t)fd)
			return (ptr);
		else
			ptr = ptr->next;
	}
	ptr = (t_list*)malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->content = 0;
	ptr->content_size = fd;
	ptr->next = NULL;
	ft_lstadd(list, ptr);
	return (*list);
}

int			get_next_line(const int fd, char **line)
{
	char			*temp;
	t_list			*ptr;
	static t_list	*list = {0};

	if (read(fd, 0, 0) || !line || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	ptr = ft_searchlst(&list, fd);
	temp = ft_allstr(ptr->content, fd);
	if (ft_strchr(temp, '\n'))
	{
		*line = ft_strdup_chr(temp, '\n');
		ptr->content = ft_strdup(ft_strtrim_n(ft_strchr(temp, '\n')));
		free(temp);
		return (1);
	}
	if (ft_strlen(temp) > 0 && ft_strchr(temp, '\0'))
	{
		*line = ft_strdup(temp);
		ptr->content = NULL;
		free(temp);
		return (1);
	}
	ptr->content = NULL;
	free(temp);
	return (0);
}
